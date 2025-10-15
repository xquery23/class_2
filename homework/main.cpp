#include "include/video_processor.hpp"
#include <iostream>

int main() {
    std::string inputPath = "/home/wael/BaseOrigin/hero/8.8/2024-8-8_17-54-17_camKE0200050354.avi";
    std::string outputPath = "/home/wael/BaseOrigin/test.mp4";

    VideoProcessor processor(inputPath, outputPath);
    
    if (!processor.initialize()) {
        return -1;
    }

    processor.processVideo();
    std::cout << "Video processing completed." << std::endl;
    
    return 0;
}