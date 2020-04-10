# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("NovelTD")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE "x64")


# Ensure dependencies are placed in the main output directory
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set (NOVELRT_SKIP_SAMPLES TRUE)
set (NOVELRT_SKIP_DOCUMENTATION TRUE)
set (NOVELRT_SKIP_TESTS TRUE)
add_subdirectory(lib/NovelRT)

set(NOVELRT_SAMPLES_LINK_LIBRARIES
  NovelRT
)

# Include sub-projects.
add_subdirectory ("NovelTD")
add_executable (NovelTD "NovelTD/NovelTD.cpp" "NovelTD/NovelTD.h")
target_link_libraries(NovelTD ${NOVELRT_SAMPLES_LINK_LIBRARIES})
