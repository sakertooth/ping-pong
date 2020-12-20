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
					"src/Scenes/CreditsScene.cpp") 
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)

if(MSVC)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif()

find_package(SFML COMPONENTS main graphics audio REQUIRED)
target_link_libraries(main PRIVATE sfml-main sfml-graphics sfml-audio)

find_package(TGUI CONFIG REQUIRED)
target_link_libraries(main PRIVATE tgui)

message(STATUS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
configure_file(${CMAKE_SOURCE_DIR}/resources/bit5x3.ttf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)
