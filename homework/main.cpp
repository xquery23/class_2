#include "include/video_processor.hpp"
#include <iostream>

int main() {
    std::string inputPath = "/home/xeqon9/Videos/TEST2.mp4";
    std::string outputPath = "/home/xeqon9/Videos/TEST2_OUTPUT.mp4";

    VideoProcessor processor(inputPath, outputPath);
    
    if (!processor.initialize()) {
        return -1;
    }

    processor.processVideo();
    std::cout << "Video processing completed." << std::endl;
    
    return 0;
}