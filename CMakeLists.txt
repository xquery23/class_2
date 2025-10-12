# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目的名称
project(CLASS_2)

# 指定头文件路径
include_directories(include)

# 定义要生成的可执行文件名称和编译所需源文件
add_executable(class_2 src/greeter.cpp src/main.cpp)