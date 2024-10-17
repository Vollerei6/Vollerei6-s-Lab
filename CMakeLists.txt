cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(Vollerei6sLab)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(${PROJECT_SOURCE_DIR}/src)

# 添加源文件
set(SOURCES
    src/main.cpp
    src/character.cpp
    src/play.hpp
    src/archive.hpp
    src/character.hpp
)

# 生成可执行文件
add_executable(Vollerei6sLab ${SOURCES})