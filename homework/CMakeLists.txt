cmake_minimum_required(VERSION 3.10)

project(HOMEWORK_2)

set(SOURCE 
    main.cpp
    src/video_processor.cpp
    utility/tool.cpp
)

set(HEADER
    include/video_processor.hpp
)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADER})