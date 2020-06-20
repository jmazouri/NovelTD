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

add_subdirectory(lib/tweeny)
add_subdirectory(lib/imgui)

# Include sub-projects.
add_subdirectory ("src")
add_executable (NovelTD 
    "src/NovelTD.cpp" "include/NovelTD.h" "src/UI/Controls/Button.cpp"
    "src/UI/CanvasContext.cpp" "src/UI/TransformOrigin.cpp" "src/UI/ImguiHelper.cpp"
    "src/UI/ImguiHelper.cpp" "src/UI/imgui_impl_glfw.cpp" "src/UI/imgui_impl_opengl3.cpp")
target_link_libraries(NovelTD ${NOVELRT_SAMPLES_LINK_LIBRARIES})
target_link_libraries(NovelTD tweeny)
target_link_libraries(NovelTD imgui)

# Copy NovelRT resources
set (source "${CMAKE_SOURCE_DIR}/lib/NovelRT/src/Resources")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/Resources")
add_custom_command(
 TARGET ${PROJECT_NAME} POST_BUILD
 COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination} 
 DEPENDS ${destination}
 COMMENT "symbolic link resources folder from ${source} => ${destination}"
)

# Copy NovelTD resources
set (source "${CMAKE_SOURCE_DIR}/res")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/res")
add_custom_command(
 TARGET ${PROJECT_NAME} POST_BUILD
 COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination} 
 DEPENDS ${destination}
 COMMENT "symbolic link resources folder from ${source} => ${destination}"
)