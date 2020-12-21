cmake_minimum_required(VERSION 3.8)
project("Saker's Ping Pong")

set(CMAKE_CXX_STANDARD 17)

add_executable(main 
					"src/Main.cpp"
					"src/Game.cpp"
					"src/ResourceManager.cpp"
					"src/ServiceLocator.cpp"
					"src/Scenes/SceneManager.cpp"
					"src/Scenes/MainMenuScene.cpp"
					"src/Scenes/PlayScene.cpp" 
					"src/Objects/Paddle.cpp" 
					"src/Objects/Ball.cpp") 
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)

find_package(SFML COMPONENTS main graphics audio REQUIRED)
target_link_libraries(main PRIVATE sfml-main sfml-graphics sfml-audio)

find_package(TGUI CONFIG REQUIRED)
target_link_libraries(main PRIVATE tgui)

message(STATUS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
configure_file(${CMAKE_SOURCE_DIR}/resources/bit9x9.ttf ${CMAKE_BINARY_DIR} COPYONLY)
