cmake_minimum_required(VERSION 3.2)

project(sheldon LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# Add sciplot as an external dependency
include(FetchContent) # If not included already
set(FETCHCONTENT_QUIET FALSE)
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
  URL     https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.bz2 # 3.4.0
  URL_MD5 132dde48fe2b563211675626d29f1707
)
FetchContent_GetProperties(eigen_content)
if(NOT eigen_content_POPULATED)
  FetchContent_Populate(eigen_content)
endif()
include_directories(${eigen_content_SOURCE_DIR})

# Add Vince's CSV Parser as an external dependency
FetchContent_Declare(csv_parser_content
  GIT_REPOSITORY https://github.com/vincentlaucsb/csv-parser.git
  GIT_TAG        ea547fdb16c7baf99bd9ced5febba52cc5da3ca3 # 2.1.3
  GIT_SUBMODULES ""
  GIT_PROGRESS   1
)
FetchContent_GetProperties(csv_parser_content)
if(NOT csv_parser_content_POPULATED)
  FetchContent_Populate(csv_parser_content)
endif()
add_subdirectory(${csv_parser_content_SOURCE_DIR} ${csv_parser_content_BINARY_DIR})
include_directories(${csv_parser_content_SOURCE_DIR}/include)

add_executable(helloSciplot src/examples/sciplot.cpp)
add_executable(helloEigen src/examples/eigen.cpp)
add_executable(helloCsv src/examples/csv_parser.cpp)
target_link_libraries(helloCsv csv)
