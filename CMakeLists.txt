# Copyright (c) 2026 Christian Hinkle.

cmake_minimum_required(VERSION 4.0)

project(CppPlayground
  LANGUAGES CXX
  )

# Set up testing. Defines `BUILD_TESTING` which is ON by default. This must be called by the top-level project only.
if(PROJECT_IS_TOP_LEVEL)
  include(CTest)
endif()

include(FetchContent)

# Declare subprojects.

FetchContent_Declare(CppPlayground_SimpleExecutables
  SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SimpleExecutables"
  OVERRIDE_FIND_PACKAGE
  )

# Add subprojects.

FetchContent_MakeAvailable(CppPlayground_SimpleExecutables)
