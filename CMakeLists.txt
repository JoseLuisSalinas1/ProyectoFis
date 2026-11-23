
cmake_minimum_required(VERSION 3.20)

project(ProyectoFis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(ProyectoFis
    src/main.cpp
    src/Wallpaper.cpp
)

target_link_libraries(ProyectoFis PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

# Copy game assets into the build directory
file(COPY ${CMAKE_SOURCE_DIR}/assets
     DESTINATION ${CMAKE_BINARY_DIR})

