#include "../../../AHRS_core/src/pipeline/abstract/pipelineNode.hpp"
class ThermxRenderer : public SubNode{
    protected:
        float min = 0;
        float max = 0;
        std::atomic<float> center = 0;
        int height = 640;
        int width = 480;
        cv::Mat currentData = cv::Mat(cv::Size(32, 24), CV_8UC3, cv::Scalar(0,0,0));
        cv::UMat UcurrentData = cv::UMat(cv::Size(32, 24), CV_8UC3, cv::Scalar(0,0,0));
        cv::ColormapTypes toApply = cv::ColormapTypes::COLORMAP_INFERNO;
        std::mutex matMutex;
        std::mutex dataMutex;
        void draw();
        void drawGL();
    public:
        vector<float> data;
        ThermxRenderer();
        void processFrame(cv::UMat& input, cv::Point2d& cursorPos) override;
        void refreshData(vector<float> newData);
};