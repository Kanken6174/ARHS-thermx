#include "ThermxRenderer.hpp"
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>
float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

ThermxRenderer::ThermxRenderer(){
    for(int i = 0; i < 24; i ++){
        for(int j = 0; j < 32; j++){
            data[i][j] = RandomFloat(0.0,40.0);
        }
    }
    refreshData(data);
}

void ThermxRenderer::refreshData(float newData[24][32]){
    try{
    const std::lock_guard<std::mutex> lock(dataMutex);
    min = max = data[0][0];
    for(int i = 0; i < 24; i ++){
        for(int j = 0; j < 32; j++){
            float t = data[i][j];
            if(t > max) max = t;
            if(t < min) min = t;
        }
    }
    std::copy(&newData[0][0], &newData[0][0]+24*32,&data[0][0]);
    const std::lock_guard<std::mutex> llock(matMutex);
    draw();
    }catch(exception e){
        std::cout << "thermx render exception: " << e.what() << std::endl;
    }
};

void ThermxRenderer::draw(){
    int h = height/24;
    int w = width/32;
    UcurrentData = cv::UMat(cv::Size(32, 24), CV_8UC3, cv::Scalar(0,0,0));
    currentData = cv::Mat(cv::Size(32, 24), CV_8UC3, cv::Scalar(0,0,0));
    Mat greyActual = cv::Mat(cv::Size(32, 24), CV_8UC1, cv::Scalar(0));   //black heightxwidth umat
    for(int i = 0; i < 24; i ++){
    for(int j = 0; j < 32; j++){
            float t = data[i][j];
            t -= min;
            t /= (max - min); //0.0 -> 1.0
            int k = t*255;  //0 -> 255
            greyActual.at<uchar>(i, j) = k;
        }
    }
    applyColorMap(greyActual,currentData,COLORMAP_INFERNO);    //pass from grayscale to thermal vision
    currentData.copyTo(UcurrentData);
}

void ThermxRenderer::processFrame(cv::UMat& input, cv::Point2d& cursorPos){
    if(!input.rows <= 0 && !input.cols <= 0){
        cv::UMat output;
        cv::resize(UcurrentData, output, cv::Size(input.cols, input.rows), cv::InterpolationFlags::INTER_MAX);
        //std::cout << input.cols << input.rows << input.type() << output.rows << output.cols << output.type()<<"\n";
        cv::UMat k(input.size(), input.type());
        cv::addWeighted(input, 1.0, output, 0.3, 0.0, k);
        input = k;
    }
}