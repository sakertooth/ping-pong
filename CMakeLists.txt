cmake_minimum_required(VERSION 3.8)
project("Saker's Ping Pong")

set(CMAKE_CXX_STANDARD 17)

add_executable(main "src/Main.cpp"
					"src/Game.cpp"
					"src/Scenes/SceneWindow.cpp"
					"src/Scenes/MainMenuScene.cpp"
					"src/Scenes/PlayScene.cpp" 
					"src/Scenes/CreditsScene.cpp"
					"src/FPSHud.cpp"
					"src/Resources.cpp")
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)

find_package(SFML COMPONENTS graphics audio REQUIRED)
target_link_libraries(main PRIVATE sfml-graphics sfml-audio)

find_package(TGUI CONFIG REQUIRED)
target_link_libraries(main PRIVATE tgui)

configure_file(${CMAKE_SOURCE_DIR}/resources/bit5x3.ttf ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
