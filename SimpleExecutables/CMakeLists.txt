# Copyright (c) 2026 Christian Hinkle.

cmake_minimum_required(VERSION 4.0)

project(CppPlayground_SimpleExecutables
  VERSION 0.1.0
  LANGUAGES CXX
  )

function(add_simple_executable)

  set(my_options
    )
  set(my_one_value_keywords
    "EXECUTABLE_NAME"
    "SOURCE_DIRECTORY"
    )
  set(my_multi_value_keywords
    "SOURCES_RELATIVE"
    )

  cmake_parse_arguments("my_arg" "${my_options}" "${my_one_value_keywords}" "${my_multi_value_keywords}" "${ARGN}")

  if(NOT DEFINED my_arg_EXECUTABLE_NAME)
    message(FATAL_ERROR "${CMAKE_CURRENT_FUNCTION}: EXECUTABLE_NAME not defined!")
    return()
  endif()

  if(NOT DEFINED my_arg_SOURCE_DIRECTORY)
    message(FATAL_ERROR "${CMAKE_CURRENT_FUNCTION}: SOURCE_DIRECTORY not defined!")
    return()
  endif()

  if(NOT DEFINED my_arg_SOURCES_RELATIVE)
    message(FATAL_ERROR "${CMAKE_CURRENT_FUNCTION}: SOURCES_RELATIVE not defined!")
    return()
  endif()

  # Create our target.
  add_executable(${my_arg_EXECUTABLE_NAME})

  # List out required language features.
  target_compile_features(${my_arg_EXECUTABLE_NAME}
    PUBLIC
      cxx_std_20
    )

  block(SCOPE_FOR VARIABLES)
    # Prepend each relative source file path with their source directory.
    set(my_sources_absolute ${my_arg_SOURCES_RELATIVE})
    list(TRANSFORM my_sources_absolute PREPEND "${my_arg_SOURCE_DIRECTORY}/")

    # List out all the files to compile for our target.
    target_sources(${my_arg_EXECUTABLE_NAME}
      PRIVATE
        ${my_sources_absolute}
      )
  endblock()

  # Specify base include directories.
  target_include_directories(${my_arg_EXECUTABLE_NAME}
    PRIVATE
      "${my_arg_SOURCE_DIRECTORY}"
    )

endfunction()

function(add_simple_leetcode_solution_executable)

  set(my_options
    )
  set(my_one_value_keywords
    "PROBLEM_NUMBER"
    "PROBLEM_SLUG"
    "OPTIONAL_SOLUTION_NAME"
    )
  set(my_multi_value_keywords
    "SOURCES_RELATIVE"
    )

  cmake_parse_arguments("my_arg" "${my_options}" "${my_one_value_keywords}" "${my_multi_value_keywords}" "${ARGN}")

  if(NOT DEFINED my_arg_PROBLEM_NUMBER)
    message(FATAL_ERROR "${CMAKE_CURRENT_FUNCTION}: PROBLEM_NUMBER not defined!")
    return()
  endif()

  if(NOT DEFINED my_arg_PROBLEM_SLUG)
    message(FATAL_ERROR "${CMAKE_CURRENT_FUNCTION}: PROBLEM_SLUG not defined!")
    return()
  endif()

  if(NOT DEFINED my_arg_SOURCES_RELATIVE)
    message(FATAL_ERROR "${CMAKE_CURRENT_FUNCTION}: SOURCES_RELATIVE not defined!")
    return()
  endif()

  set(my_executable_name "${my_arg_PROBLEM_NUMBER}_${my_arg_PROBLEM_SLUG}")

  if(DEFINED my_arg_OPTIONAL_SOLUTION_NAME)
    string(APPEND my_executable_name "_${my_arg_OPTIONAL_SOLUTION_NAME}")
  endif()

  add_simple_executable(
    EXECUTABLE_NAME
      "${my_executable_name}"
    SOURCE_DIRECTORY
      "${CMAKE_CURRENT_SOURCE_DIR}/Source/Leetcode/${my_arg_PROBLEM_NUMBER}_${my_arg_PROBLEM_SLUG}"
    SOURCES_RELATIVE
      "${my_arg_SOURCES_RELATIVE}"
    )

endfunction()

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0001"
  PROBLEM_SLUG
    "two-sum"
  OPTIONAL_SOLUTION_NAME
  SOURCES_RELATIVE
    "Solution.h"
    "Main.cpp"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0021"
  PROBLEM_SLUG
    "merge-two-sorted-lists"
  OPTIONAL_SOLUTION_NAME
  SOURCES_RELATIVE
    "Solution.h"
    "Main.cpp"
    "ListNode.h"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0074"
  PROBLEM_SLUG
    "search-a-2d-matrix"
  OPTIONAL_SOLUTION_NAME
  SOURCES_RELATIVE
    "Solution.h"
    "Main.cpp"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0133"
  PROBLEM_SLUG
    "clone-graph"
  OPTIONAL_SOLUTION_NAME
  SOURCES_RELATIVE
    "Solution.h"
    "Main.cpp"
    "Node.h"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0141"
  PROBLEM_SLUG
    "linked-list-cycle"
  OPTIONAL_SOLUTION_NAME
  SOURCES_RELATIVE
    "Solution.h"
    "Main.cpp"
    "ListNode.h"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0200"
  PROBLEM_SLUG
    "number-of-islands"
  OPTIONAL_SOLUTION_NAME
  SOURCES_RELATIVE
    "Solution.h"
    "Main.cpp"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0206"
  PROBLEM_SLUG
    "reverse-linked-list"
  OPTIONAL_SOLUTION_NAME
  SOURCES_RELATIVE
    "Solution.h"
    "Main.cpp"
    "ListNode.h"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0206"
  PROBLEM_SLUG
    "reverse-linked-list"
  OPTIONAL_SOLUTION_NAME
    "Recursive"
  SOURCES_RELATIVE
    "Solution_Recursive.h"
    "Main_Recursive.cpp"
    "ListNode.h"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0217"
  PROBLEM_SLUG
    "contains-duplicate"
  OPTIONAL_SOLUTION_NAME
  SOURCES_RELATIVE
    "Solution_HashSet.h"
    "Main_HashSet.cpp"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0703"
  PROBLEM_SLUG
    "kth-largest-element-in-a-stream"
  OPTIONAL_SOLUTION_NAME
  SOURCES_RELATIVE
    "Solution.h"
    "Main.cpp"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0704"
  PROBLEM_SLUG
    "binary-search"
  OPTIONAL_SOLUTION_NAME
  SOURCES_RELATIVE
    "Solution.h"
    "Main.cpp"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0733"
  PROBLEM_SLUG
    "flood-fill"
  OPTIONAL_SOLUTION_NAME
    "DepthFirstSearch"
  SOURCES_RELATIVE
    "Solution_DepthFirstSearch.h"
    "Main_DepthFirstSearch.cpp"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0733"
  PROBLEM_SLUG
    "flood-fill"
  OPTIONAL_SOLUTION_NAME
    "BreadthFirstSearch"
  SOURCES_RELATIVE
    "Solution_BreadthFirstSearch.h"
    "Main_BreadthFirstSearch.cpp"
  )

add_simple_leetcode_solution_executable(
  PROBLEM_NUMBER
    "0875"
  PROBLEM_SLUG
    "koko-eating-bananas"
  OPTIONAL_SOLUTION_NAME
  SOURCES_RELATIVE
    "Solution.h"
    "Main.cpp"
  )
