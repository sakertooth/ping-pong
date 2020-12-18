#include <Pong/Scenes/Scene.hpp>
#include <Pong/Scenes/SceneManager.hpp>
#include <TGUI/TGUI.hpp>

namespace Pong
{
	namespace Scenes
	{
		class CreditsScene : public Scene, public tgui::Gui
		{
			tgui::Label::Ptr m_creditsLabel;
			tgui::Button::Ptr m_goBackButton;
		public:
			CreditsScene(SceneManager& manager, sf::RenderTarget& target);
			void draw();
			void update(float deltaTime);
			void handleEvent(sf::Event& event);
		};
	}
}