#ifndef VIDEO_PROCESSOR_HPP
#define VIDEO_PROCESSOR_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
// #include <opencv2/core/mat.hpp>
#include <string>

class VideoProcessor {
public:
    VideoProcessor(const std::string& inputPath, const std::string& outputPath);
    ~VideoProcessor();

    bool initialize();
    void processVideo();
    void releaseResources();

private:
    cv::VideoCapture cap;
    cv::VideoWriter out;
    std::string inputPath;
    std::string outputPath;
    
    // 处理函数
    void processFrame(cv::Mat& frame);
    void showChannels(const cv::Mat& frame);
    void showContours(cv::Mat& frame);
};

#endif