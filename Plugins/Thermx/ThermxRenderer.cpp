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
    data = std::vector<float>();
    data.reserve(32*24);
    for(int i = 0; i < 24; i ++){
        for(int j = 0; j < 32; j++){
            data.push_back(RandomFloat(0.0,40.0));
        }
    }
    refreshData(data);
}

void ThermxRenderer::refreshData(vector<float> newData){
    try{
        //std::cout << "copying data" << std::endl;
        dataMutex.lock();
        data.clear();
        data = newData;
        
        //std::cout << "setting minmax " << newData.size() << std::endl;
        int size = data.size();
        //std::cout << data[0];
        //std::cout << "didn't segfault" << std::endl;
        max = newData.at(0);
        //std::cout << "set minmax" << std::endl;
        for(int i = 0; i < 24; i++){
            for(int j = 0; j < 32; j++){
                if(i*32+j >= newData.size()) break;
                float t = newData.at(i*32+j);
                if(t > max) max = t;
                if(t < min) min = t;
            }
        }
        center = newData.at((24/2)*32+(32/2));

        data.at((24/2)*32+(32/2)) = 0;
        dataMutex.unlock();
        //std::cout << "drawing data" << std::endl;
        //matMutex.lock();
        draw();
        //matMutex.unlock();
        //std::cout << "done refreshing data" << std::endl;
        
       //std::cout << "didn't crash" << std::endl;
    }catch(exception e){
        //std::cout << "thermx render exception: " << e.what() << std::endl;
    }
};

void ThermxRenderer::draw(){
    int h = height/24;
    int w = width/32;
    UcurrentData = cv::UMat(cv::Size(32, 24), CV_8UC3, cv::Scalar(0,0,0));
    currentData = cv::Mat(cv::Size(32, 24), CV_8UC3, cv::Scalar(0,0,0));
    Mat greyActual = cv::Mat(cv::Size(32, 24), CV_8UC1, cv::Scalar(0));   //black heightxwidth umat

    for(int i = 0; i < 24; i++){
        for(int j = 0; j < 32; j++){
            if(i*32+j >= data.size()) break;
            float t = data.at(i*32+j);
            t -= min;
            t /= (max - min); //0.0 -> 1.0
            int k = t*255;  //0 -> 255
            greyActual.at<uchar>(i, j) = k;
        }
    }
    applyColorMap(greyActual,currentData,COLORMAP_INFERNO);    //pass from grayscale to thermal vision

    for(int i = 0; i < 24; i++){
        for(int j = 0; j < 32; j++){
            if(i*32+j >= data.size()) break;
            float t = data.at(i*32+j);
            if(t > 34 && t < 40)
                currentData.at<Vec3b>(i, j) = Vec3b(255,0,0);
        }
    }
    currentData.copyTo(UcurrentData);
}

void ThermxRenderer::processFrame(cv::UMat& input, cv::Point2d& cursorPos){
    if(!input.rows <= 0 && !input.cols <= 0){
        ////std::cout << "drawing frame..." << std::endl;
        cv::UMat output;
        //matMutex.lock();
        cv::resize(UcurrentData, output, cv::Size(input.cols, input.rows), cv::InterpolationFlags::INTER_NEAREST);
        //matMutex.unlock();
        ////std::cout << input.cols << input.rows << input.type() << output.rows << output.cols << output.type()<<"\n";
        cv::UMat k(input.size(), input.type());
        cv::addWeighted(input, 1.0, output, 1.0, 0.0, k);
        float fi = center;
        cv::putText(k, cv::format("%.2f", fi), Point2i(400,250),cv::FONT_HERSHEY_DUPLEX, 2, cv::Scalar(100, 100, 100), 1, cv::LineTypes::FILLED, false);
        input = k;
    }
}