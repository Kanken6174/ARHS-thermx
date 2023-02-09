// C library headers
#include <stdio.h>
#include <string.h>

// Linux headers
#include <fcntl.h>   // Contains file controls like O_RDWR
#include <errno.h>   // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h>  // write(), read(), close()

#include <thread>
#include <vector>
#include <iostream>

#include <iterator>
#include <algorithm>


int main(){
    struct termios tty;
    
    std::cout << "opening serial port /dev/ttyUSB0" << std::endl;
    int serialPort = open("/dev/ttyACM0", O_RDONLY); // open serial port
    std::cout << "done" << std::endl;

    if (serialPort < 0)
    {
        printf("Error %i from open: %s\n", errno, strerror(errno));
        return -1;
    }

    if (tcgetattr(serialPort, &tty) != 0)
    { // read serial port configuration
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
        return -1;
    }

    // local flags
    tty.c_lflag &= ~ICANON; // enable canonical mode
    tty.c_lflag &= ~ECHO;   // Disable echo
    tty.c_lflag &= ~ECHOE;  // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG;   // Disable interpretation of INTR, QUIT and SUSP
    // input modes
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);                                      // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL); // Disable any special handling of received bytes
    // output modes
    tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
    // c_cc
    tty.c_cc[VTIME] = 10; // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    tty.c_cc[VMIN] = 0;
    // baudrate
    cfsetispeed(&tty, B460800); // set baudrate (input)
    cfsetospeed(&tty, B460800); // (output)

    // Save tty settings, also checking for error
    if (tcsetattr(serialPort, TCSANOW, &tty) != 0)
    {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
        return -1;
    }

    char read_buf[1024];
    float out_buf[24][32];
    std::string outs = std::string("");
    int n = 0;
    int i = 0;
    int j = 0;
    bool goodData = false;
    system("clear");
    while(true){
        n = read(serialPort, &read_buf, sizeof(read_buf));
        if (n > 0)
        {
            //std::cout << read_buf;
            std::cout << n << std::endl;
            j = i = 0;
            outs.clear();
            for(char c : read_buf){
                if(goodData){
                    if(c >= '0' && c <= '9' || c == '.'){
                        outs.append({c});
                    }else if(c == '|'){
                        std::cout << outs;
                        try{
                        out_buf[i][j] = std::stof(outs);
                        outs.clear();
                        j++;
                        } catch(std::invalid_argument e){
                            std::cerr << "stof error" << std::endl;
                        }
                    }else if(c == '\n'){
                        i++;
                    }else if(c == '!'){
                        return 0;
                        break;
                    }
                }else{
                    if(c == '?'){
                        i = -1;
                        goodData = true;
                    }
                }
            }
            i = 0;
            j = 0;
            goodData = false;
            for (uint8_t h=0; h<24; h++) {
            for (uint8_t w=0; w<32; w++) {
                    //printf("%.2f|",out_buf[h][w]);
                }
                //std::cout << std::endl;
            }
            usleep(100000);
            system("clear");
        }
    }
    return 0;
}