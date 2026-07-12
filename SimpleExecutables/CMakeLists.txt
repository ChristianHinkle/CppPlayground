# Copyright (c) 2026 Christian Hinkle.

cmake_minimum_required(VERSION 4.0)

project(CppPlayground_SimpleExecutables
  VERSION 0.1.0
  LANGUAGES CXX
  )

# Create our target.
add_executable(two-sum)

# List out required language features.
target_compile_features(two-sum
  PUBLIC
    cxx_std_20
  )

# List out all the files to compile for our target.
target_sources(two-sum
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/1_two-sum/Solution.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/1_two-sum/Main.cpp"
  )

# Specify base include directories.
target_include_directories(two-sum
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/1_two-sum"
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
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/703_kth-largest-element-in-a-stream/Solution.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/703_kth-largest-element-in-a-stream/Main.cpp"
  )

# Specify base include directories.
target_include_directories(kth-largest-element-in-a-stream
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/703_kth-largest-element-in-a-stream"
  )

# Create our target.
add_executable(flood-fill_DepthFirstSearch)

# List out required language features.
target_compile_features(flood-fill_DepthFirstSearch
  PUBLIC
    cxx_std_20
  )

# List out all the files to compile for our target.
target_sources(flood-fill_DepthFirstSearch
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/733_flood-fill/Solution_DepthFirstSearch.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/733_flood-fill/Main_DepthFirstSearch.cpp"
  )

# Specify base include directories.
target_include_directories(flood-fill_DepthFirstSearch
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/733_flood-fill"
  )

# Create our target.
add_executable(flood-fill_BreadthFirstSearch)

# List out required language features.
target_compile_features(flood-fill_BreadthFirstSearch
  PUBLIC
    cxx_std_20
  )

# List out all the files to compile for our target.
target_sources(flood-fill_BreadthFirstSearch
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/733_flood-fill/Solution_BreadthFirstSearch.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/733_flood-fill/Main_BreadthFirstSearch.cpp"
  )

# Specify base include directories.
target_include_directories(flood-fill_BreadthFirstSearch
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/733_flood-fill"
  )
