#include "MainMenuState.hpp"
#include "InfoState.hpp"
#include "GameState.hpp"
#include "ScoresState.hpp"
#include "Game.hpp"


MainMenuState::MainMenuState(std::shared_ptr<GameData> data)
	:_data(data)
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Init()
{
	

	//Textures
	float y = 250;
	for (const std::string& name : _buttonNames) {
		/*this->_data->assets.AddTexture(name, "resources/images/menu/"+name+".png");
		this->_data->assets.AddTexture(name+"A", "resources/images/menu/"+name+"active.png");*/

		this->_buttons[name][0].setTexture(this->_data->assets.GetTexture(name));
		this->_buttons[name][1].setTexture(this->_data->assets.GetTexture(name + "A"));

		this->_buttons[name][0].setPosition(400, y);
		this->_buttons[name][1].setPosition(400, y);

		this->_buttons[name][0].setOrigin(110, 25); //addvariable or define
		this->_buttons[name][1].setOrigin(110, 25);

		y += 70;
	}

	/*this->_data->assets.AddTexture("menuBackground", "resources/images/menu/menuBackground.png");*/
	this->_background.setTexture(this->_data->assets.GetTexture("menuBackground"));
	
}

void MainMenuState::Draw(const float & dt)
{
	this->_data->window.draw(this->_background);
	for (const std::string& name : _buttonNames) {
		if (this->_activeButton == name) {
			this->_data->window.draw(this->_buttons[name][1]);
		}
		else
			this->_data->window.draw(this->_buttons[name][0]);
	}

	
}

void MainMenuState::Update(const float & dt)
{

}

void MainMenuState::HandleInput(const float & dt)
{
	sf::Event e;
	if (this->_data->window.pollEvent(e)) {
		if (e.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				_activeButtonIndex--;
				if (_activeButtonIndex < 0)
					_activeButtonIndex = 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				_activeButtonIndex++;
				if (_activeButtonIndex > 3)
					_activeButtonIndex = 0;
			}
			if (e.key.code == sf::Keyboard::Enter) {
				if (this->_activeButton == "play")
					this->_data->states.AddState(std::unique_ptr<State>(new GameState(this->_data)));
					//std::cout << "PLAY" << std::endl;
				if (this->_activeButton == "scores")
					this->_data->states.AddState(std::unique_ptr<State>(new ScoresState(this->_data)));
					//std::cout << "SCORES" << std::endl;
				
				if (this->_activeButton == "info")
					this->_data->states.AddState(std::unique_ptr<State>(new InfoState(this->_data)));
				if (this->_activeButton == "exit")
					this->_data->window.close();
			}
		}
		Game::quitEvent(this->_data->window, e);
		_activeButton = _buttonNames[_activeButtonIndex];
	}
}
