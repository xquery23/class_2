// src/main.cpp
#include <iostream>
#include "greeter.hpp"

int main() {
    std::string name;

    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);  // 从用户获取名字

    greet(name);  // 调用问候函数

    return 0;
}
/*
--compile-commands-dir=${workspaceFolder}/build
--all-scopes-completion
--completion-style=detailed
--background-index
--clang-tidy
*/