cmake_minimum_required(VERSION 3.10)

project(cut)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV 4 REQUIRED)


set(SOURCE 
    main.cpp
    src/video_processor.cpp
    utility/tool.cpp
)
set(HEADERS
    include/video_processor.hpp
)

add_executable(cut ${SOURCE} ${HEADERS})

target_link_libraries(cut ${OpenCV_LIBS})

# target_include_directories(cut PUBLIC
#     ${OpenCV_INCLUDE_DIRS}
#     # ${SOURCE}
# )


# target_include_directories(
#     ${OpenCV_INCLUDE_DIRS}
#     ${HEADERS}
#     # include/video_processor.hpp
#     )


