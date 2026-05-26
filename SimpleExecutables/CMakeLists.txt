# Copyright (c) 2026 Christian Hinkle.

cmake_minimum_required(VERSION 4.0)

project(CppPlayground_SimpleExecutables
  VERSION 0.1.0
  LANGUAGES CXX
  )

# Create our target.
add_executable(kth-largest-element-in-a-stream)

# List out required language features.
target_compile_features(kth-largest-element-in-a-stream
  PUBLIC
    cxx_std_20
  )

# List out all the files to compile for our target.
target_sources(kth-largest-element-in-a-stream
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/kth-largest-element-in-a-stream.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/kth-largest-element-in-a-stream_main.cpp"
  )

# Specify base include directories.
target_include_directories(kth-largest-element-in-a-stream
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source"
  )
