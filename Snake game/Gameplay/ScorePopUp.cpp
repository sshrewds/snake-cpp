#include "ScorePopUp.hpp"
#include "../MainMenuState.hpp"
#include "../Game.hpp"
#include <fstream>


ScorePopUp::ScorePopUp(std::shared_ptr<GameData> data, const int &score)
	:_data(data), _score(score)
{
	this->_scoreInfo.setString("Your score:\t\t" + std::to_string(this->_score));

	/*sf::Texture screenshot;
	screenshot.create(this->_data->window.getSize().x, this->_data->window.getSize().y);
	screenshot.update(this->_data->window);*/
	/*this->_gameScreenshot.setTexture(screenshot);*/ //blur?
	this->Init();
}

ScorePopUp::ScorePopUp()
{
}

ScorePopUp::~ScorePopUp()
{
}

void ScorePopUp::Init()
{
	this->_background.setTexture(this->_data->assets.GetTexture("scoreWindow"));
	this->_background.setOrigin(this->_background.getLocalBounds().width / 2, this->_background.getLocalBounds().height / 2);
	this->_background.setPosition({ 400,300 });

	this->_scoreInfo.setFont(this->_data->assets.GetFont("agency"));
	this->_scoreInfo.setCharacterSize(32);
	this->_scoreInfo.setOrigin(this->_scoreInfo.getLocalBounds().width / 2, this->_scoreInfo.getLocalBounds().height / 2);
	this->_scoreInfo.setPosition({ 400,260 });


	this->_userName.setFont(this->_data->assets.GetFont("agency"));
	this->_userName.setCharacterSize(24);

}

void ScorePopUp::Draw(const float & dt)
{
	//this->_data->window.draw(this->_gameScreenshot);
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_scoreInfo);
	this->_data->window.draw(this->_userName);
}

void ScorePopUp::Update()
{
	this->_userName.setString(this->_userInput);
	this->_userName.setOrigin(this->_userName.getLocalBounds().width / 2, this->_userName.getLocalBounds().height / 2);
	this->_userName.setPosition({ 400,320 });
}

void ScorePopUp::HandleInput(sf::Event& e)
{
	//sf::Event e;
	if (this->_data->window.pollEvent(e)) {
		if (e.type == sf::Event::KeyPressed) {

			if (e.key.code == sf::Keyboard::Escape) {
				this->_data->states.AddState(std::unique_ptr<State>(new MainMenuState(this->_data)));
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			this->_userInput.pop_back();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			this->SaveToFile("resources/scores.txt");

		else if (e.type == sf::Event::TextEntered) {
			this->_userInput += e.text.unicode;
			
		}
		/*if (e.type == sf::Event::KeyPressed) {
			
		}*/
	}
	this->Update();
}

void ScorePopUp::SaveToFile(const std::string & fileName)
{
	std::ofstream f(fileName,std::ios::app);
	if (f.is_open()) {
		f << this->_userInput << "#" << this->_score << std::endl;
		f.close();

		std::cout << "Successfully saved score to " + fileName + " file" << std::endl;
	}
	else
		std::cout << "Couldn't open " + fileName + " file" << std::endl;

	this->_data->states.AddState(std::unique_ptr<State>(new MainMenuState(this->_data)));
	this->_data->assets.menuMusic.play();
}
