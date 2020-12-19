#include <Pong/Game.hpp>
#include <Pong/Scenes/MainMenuScene.hpp>
#include <Pong/Scenes/CreditsScene.hpp>
#include <Pong/Scenes/PlayScene.hpp>
int main()
{
	auto& game = Pong::Game::getInstance();
	game.getSceneManager().addScene("Main Menu", std::make_shared<Pong::Scenes::MainMenuScene>());
	game.getSceneManager().addScene("Play", std::make_shared<Pong::Scenes::PlayScene>());
	game.getSceneManager().addScene("Credits", std::make_shared<Pong::Scenes::CreditsScene>());
}