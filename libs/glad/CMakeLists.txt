cmake_minimum_required(VERSION 3.22)
project(glad)

include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libs/glad/include)

set(GLAD_SRC
    # Sources
    src/glad.c

    # Headers
    include/glad/glad.h
    include/KHR/khrplatform.h
)

add_library(glad STATIC ${GLAD_SRC})
