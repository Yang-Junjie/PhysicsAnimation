cmake_minimum_required(VERSION 3.10.0)

project(Phy-Animation)

include_directories("./include/svpng/")
include_directories("./include/")
file(GLOB_RECURSE CPP_FILE "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE SVPNG_FILE "${PROJECT_SOURCE_DIR}/src/svpng/*.cpp")

add_executable(${PROJECT_NAME} ${CPP_FILE} ${SVPNG_FILE})

