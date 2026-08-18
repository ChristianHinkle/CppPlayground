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
add_executable(search-a-2d-matrix)

# List out required language features.
target_compile_features(search-a-2d-matrix
  PUBLIC
    cxx_std_20
  )

# List out all the files to compile for our target.
target_sources(search-a-2d-matrix
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/74_search-a-2d-matrix/Solution.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/74_search-a-2d-matrix/Main.cpp"
  )

# Specify base include directories.
target_include_directories(search-a-2d-matrix
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/74_search-a-2d-matrix"
  )

# Create our target.
add_executable(clone-graph)

# List out required language features.
target_compile_features(clone-graph
  PUBLIC
    cxx_std_20
  )

# List out all the files to compile for our target.
target_sources(clone-graph
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/133_clone-graph/Solution.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/133_clone-graph/Main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/133_clone-graph/Node.h"
  )

# Specify base include directories.
target_include_directories(clone-graph
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/133_clone-graph"
  )

# Create our target.
add_executable(reverse-linked-list)

# List out required language features.
target_compile_features(reverse-linked-list
  PUBLIC
    cxx_std_20
  )

# List out all the files to compile for our target.
target_sources(reverse-linked-list
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/206_reverse-linked-list/Solution.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/206_reverse-linked-list/Main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/206_reverse-linked-list/ListNode.h"
  )

# Specify base include directories.
target_include_directories(reverse-linked-list
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/206_reverse-linked-list"
  )

# Create our target.
add_executable(reverse-linked-list_Recursive)

# List out required language features.
target_compile_features(reverse-linked-list_Recursive
  PUBLIC
    cxx_std_20
  )

# List out all the files to compile for our target.
target_sources(reverse-linked-list_Recursive
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/206_reverse-linked-list/Solution_Recursive.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/206_reverse-linked-list/Main_Recursive.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/206_reverse-linked-list/ListNode.h"
  )

# Specify base include directories.
target_include_directories(reverse-linked-list_Recursive
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/206_reverse-linked-list"
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
add_executable(binary-search)

# List out required language features.
target_compile_features(binary-search
  PUBLIC
    cxx_std_20
  )

# List out all the files to compile for our target.
target_sources(binary-search
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/704_binary-search/Solution.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/704_binary-search/Main.cpp"
  )

# Specify base include directories.
target_include_directories(binary-search
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/704_binary-search"
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
