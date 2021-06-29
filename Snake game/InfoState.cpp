#include "InfoState.hpp"
#include "MainMenuState.hpp"
#include "Game.hpp"


InfoState::InfoState(std::shared_ptr<GameData> data)
	:_data(data)
{
}

InfoState::~InfoState()
{
}

void InfoState::Init()
{
	/*this->_data->assets.AddTexture("infoBackground", "resources/images/info/infoBackground.png");*/
	this->_background.setTexture(this->_data->assets.GetTexture("infoBackground"));

}

void InfoState::Draw(const float & dt)
{
	this->_data->window.draw(this->_background);
}

void InfoState::Update(const float & dt)
{

}

void InfoState::HandleInput(const float & dt)
{
	sf::Event e;
	if (this->_data->window.pollEvent(e)) {
		if (e.type == sf::Event::KeyPressed) {

			if (e.key.code == sf::Keyboard::Escape) {
				this->_data->states.AddState(std::unique_ptr<State>(new MainMenuState(this->_data)));
			}
		}
		Game::quitEvent(this->_data->window, e);
	}
}
