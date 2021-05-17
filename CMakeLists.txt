cmake_minimum_required(VERSION 3.0.0)
project("Ping Pong")

set(CMAKE_CXX_STANDARD 17)

add_executable(pingpong WIN32
					${CMAKE_SOURCE_DIR}/src/Main.cpp
					${CMAKE_SOURCE_DIR}/src/Game.cpp
					${CMAKE_SOURCE_DIR}/src/Ball.cpp
					${CMAKE_SOURCE_DIR}/src/SoundManager.cpp
					${CMAKE_SOURCE_DIR}/src/States/MainMenuState.cpp
					${CMAKE_SOURCE_DIR}/src/States/ChooseDifficultyState.cpp
					${CMAKE_SOURCE_DIR}/src/States/TwoPlayerState.cpp
					${CMAKE_SOURCE_DIR}/src/States/SpacebarToStartState.cpp
					${CMAKE_SOURCE_DIR}/src/States/OnePlayerState.cpp
					${CMAKE_SOURCE_DIR}/src/States/GameOverState.cpp)

target_include_directories(pingpong PRIVATE ${CMAKE_SOURCE_DIR}/include)

find_package(SFML COMPONENTS main graphics audio REQUIRED)
target_link_libraries(pingpong PRIVATE sfml-main sfml-graphics sfml-audio)

find_package(TGUI CONFIG REQUIRED)
target_link_libraries(pingpong PRIVATE tgui)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})