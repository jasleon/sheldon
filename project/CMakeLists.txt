cmake_minimum_required(VERSION 3.2)

project(sheldon LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(FETCHCONTENT_QUIET FALSE)

# Add sciplot as an external dependency
include(FetchContent) # If not included already
FetchContent_Declare(sciplot_content
  GIT_REPOSITORY https://github.com/sciplot/sciplot.git
  GIT_TAG        d568f1f5c4708e824ef9bfe44e3246a6862ebe97 # master
  GIT_PROGRESS   1
)
FetchContent_GetProperties(sciplot_content)
if(NOT sciplot_content_POPULATED)
  FetchContent_Populate(sciplot_content)
endif()

include_directories(${sciplot_content_SOURCE_DIR})

# Add Eigen as an external dependency
FetchContent_Declare(eigen_content
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG        3147391d946bb4b6c68edd901f2add6ac1f31f8c # 3.4.0
  GIT_PROGRESS   1
)
FetchContent_GetProperties(eigen_content)
if(NOT eigen_content_POPULATED)
  FetchContent_Populate(eigen_content)
endif()
include_directories(${eigen_content_SOURCE_DIR})

add_executable(helloSciplot src/examples/sciplot.cpp)
add_executable(helloEigen src/examples/eigen.cpp)
