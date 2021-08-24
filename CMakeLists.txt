cmake_minimum_required(VERSION 3.0.0)
project(pingpong VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(pingpong $<$<CONFIG:Release>:WIN32>
    src/Main.cpp
    src/Game.cpp
    src/SoundManager.cpp
    src/GameObjects/Button.cpp
    src/GameObjects/Ball.cpp
    src/GameObjects/Paddle.cpp
    src/States/MainMenuState.cpp
    src/States/SpacebarState.cpp
    src/States/OnePlayerState.cpp
    src/States/TwoPlayerState.cpp)

target_compile_options(pingpong PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

find_package(SFML COMPONENTS graphics audio REQUIRED)
target_link_libraries(pingpong PUBLIC sfml-graphics sfml-audio)

if(WIN32)
    find_package(SFML COMPONENTS main REQUIRED)
    target_link_libraries(pingpong PUBLIC sfml-main)

    add_custom_command(TARGET pingpong POST_BUILD
                        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:pingpong> 
                        $<TARGET_RUNTIME_DLLS:pingpong>/../openal32.dll
                        $<TARGET_FILE_DIR:pingpong>
                        COMMAND_EXPAND_LISTS)
endif()

add_custom_command(TARGET pingpong POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:pingpong>/assets)
