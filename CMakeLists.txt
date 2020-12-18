cmake_minimum_required(VERSION 3.8)
project("Saker's Ping Pong")

set(CMAKE_CXX_STANDARD 17)

add_executable(main "src/Main.cpp" 
					"src/Game.cpp"
					"src/Scenes/SceneManager.cpp" 
					"src/Scenes/MainMenuScene.cpp"
					"src/Scenes/PlayScene.cpp" 
					"src/Scenes/CreditsScene.cpp")
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)

find_package(SFML COMPONENTS graphics audio REQUIRED)
target_link_libraries(main PRIVATE sfml-graphics sfml-audio)

find_package(TGUI CONFIG REQUIRED)
target_link_libraries(main PRIVATE tgui)
