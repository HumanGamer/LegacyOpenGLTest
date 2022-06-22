cmake_minimum_required(VERSION 3.22)
project(LegacyOpenGLTest)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(LIBC ON CACHE BOOL "" FORCE)
add_subdirectory(libs/SDL)
add_subdirectory(libs/glad)

add_subdirectory(src)
