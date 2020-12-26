cmake_minimum_required(VERSION 3.8)
project("Saker's Ping Pong")

set(CMAKE_CXX_STANDARD 17)

add_executable(main 
					"src/Main.cpp"
					"src/Game.cpp"
					"src/SoundManager.cpp"					 
					"src/States/MainMenuState.cpp"
					"src/States/TwoPlayerState.cpp"
					"src/Objects/Paddle.cpp"
					 "src/Objects/Ball.cpp")
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)

find_package(SFML COMPONENTS main graphics audio REQUIRED)
target_link_libraries(main PRIVATE sfml-main sfml-graphics sfml-audio)

find_package(TGUI CONFIG REQUIRED)
target_link_libraries(main PRIVATE tgui)

find_package(effolkronium_random CONFIG REQUIRED)
target_link_libraries(main PRIVATE effolkronium_random)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})