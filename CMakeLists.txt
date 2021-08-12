cmake_minimum_required(VERSION 3.0.0)
project(pingpong VERSION 0.1.0)

add_executable(pingpong WIN32
    src/Main.cpp
    src/Game.cpp
    src/GameObjects/Button.cpp
    src/States/MainMenuState.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS main graphics audio REQUIRED)
target_link_libraries(pingpong PUBLIC sfml-main sfml-graphics sfml-audio)

add_custom_command(TARGET pingpong POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:pingpong>/assets)