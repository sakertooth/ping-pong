cmake_minimum_required(VERSION 3.0.0)
project(ping-pong VERSION 0.1.0)

add_executable(ping-pong    src/Main.cpp
                            src/Game.cpp
                            src/GameObjects/Button.cpp
                            src/States/MainMenuState.cpp)

find_package(SFML COMPONENTS main graphics audio REQUIRED)
target_link_libraries(ping-pong PUBLIC sfml-main sfml-graphics sfml-audio)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})