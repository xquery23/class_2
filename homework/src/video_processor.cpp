#include "../include/video_processor.hpp"
#include <iostream>

VideoProcessor::VideoProcessor(const std::string& inputPath, const std::string& outputPath) 
    : inputPath(inputPath), outputPath(outputPath) {}

bool VideoProcessor::initialize() {
    cap.open(inputPath);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open video." << std::endl;
        return false;
    }

    double fps = cap.get(cv::CAP_PROP_FPS);
    int width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));

    out.open(outputPath, cv::VideoWriter::fourcc('X', 'V', 'I', 'D'), fps, cv::Size(width, height));
    if (!out.isOpened()) {
        std::cerr << "Error: Could not open output video." << std::endl;
        return false;
    }

    return true;
}

void VideoProcessor::processVideo() {
    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        processFrame(frame);
        out << frame;

        if (cv::waitKey(10) >= 0) break;
    }
}

void VideoProcessor::processFrame(cv::Mat& frame) {
    // 显示通道
    showChannels(frame);
    
    // 轮廓检测
    showContours(frame);
    
    // 绘制ROI区域
    cv::Rect roi(300, 400, 600, 600);
    if (roi.x + roi.width <= frame.cols && roi.y + roi.height <= frame.rows) {
        cv::rectangle(frame, roi, cv::Scalar(0, 255, 0), 2);
        cv::putText(frame, "ROI Area", cv::Point(roi.x-10, roi.y-10), 
                   cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 0, 0), 2);
    }
}

void VideoProcessor::showChannels(const cv::Mat& frame) {
    std::vector<cv::Mat> channels;
    cv::split(frame, channels);
    
    cv::imshow("Blue Channel", channels[0]);
    cv::imshow("Green Channel", channels[1]);
    cv::imshow("Red Channel", channels[2]);
}

void VideoProcessor::showContours(cv::Mat& frame) {
    cv::Mat gray, binary, edges;
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, binary, 128, 255, cv::THRESH_BINARY);
    
    cv::GaussianBlur(binary, binary, cv::Size(5, 5), 0);
    cv::Canny(binary, edges, 100, 200);
    
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    
    cv::Mat contourImg = cv::Mat::zeros(frame.size(), CV_8UC3);
    cv::drawContours(contourImg, contours, -1, cv::Scalar(255, 0, 0), 2);
    cv::imshow("Contour Image", contourImg);
}

void VideoProcessor::releaseResources() {
    cap.release();
    out.release();
    cv::destroyAllWindows();
}

VideoProcessor::~VideoProcessor() {
    releaseResources();
}