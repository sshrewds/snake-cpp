#include "ScoresState.hpp"
#include "MainMenuState.hpp"
#include "Game.hpp"

#include <fstream>
#include <sstream>



ScoresState::ScoresState(std::shared_ptr<GameData> data)
	:_data(data)
{
}

ScoresState::~ScoresState()
{
}

void ScoresState::Init()
{
	this->_background.setTexture(this->_data->assets.GetTexture("scoresBackground"));

	this->_names.setFont(this->_data->assets.GetFont("agency"));
	this->_names.setCharacterSize(25);
	this->_topScores.setFont(this->_data->assets.GetFont("agency"));
	this->_topScores.setCharacterSize(25);
	this->LoadScores();
}

void ScoresState::Draw(const float & dt)
{
	this->_data->window.draw(this->_background);

	this->_data->window.draw(this->_names);
	this->_data->window.draw(this->_topScores);
}

void ScoresState::Update(const float & dt)
{
	
}

void ScoresState::HandleInput(const float & dt)
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

void ScoresState::LoadScores()
{
	std::ifstream ss("resources/scores.txt");
	std::map<int, std::string, std::greater<int>> scores;

	if (ss.is_open()) {
		std::string buffor;
		char separator = '#';

		std::cout << "Successfully opened scores.txt at resources/scores.txt" << std::endl;
		while (std::getline(ss, buffor)) {
			size_t i;
			if (( i = buffor.find(separator)) != std::string::npos) {
				scores[std::stoi(buffor.substr(i + 1, buffor.size() - i - 1))] = buffor.substr(0, i);
			}
		}
	}
	else
		std::cout << "Couldn't open scores.txt at resources/scores.txt" << std::endl;

	std::string names = "", topScores = "";

	int i = 1;
	for (auto it = scores.begin(); i <= 10; i++) {
		names += std::to_string(i) + ". " + (it != scores.end() ? it->second : "") + "\n";
		topScores += (it != scores.end() ? this->FixScoreFormat(std::to_string(it->first)) : "") + "\n";
		/*std::cout << this->FixScoreFormat("406")<< std::endl;*/
		if (it != scores.end())
			it++;
	}

	this->_names.setString(names);
	this->_names.setOrigin(0, this->_names.getLocalBounds().height / 2);
	this->_names.setPosition(100, 350);

	this->_topScores.setString(topScores);
	this->_topScores.setOrigin(this->_topScores.getLocalBounds().width, this->_topScores.getLocalBounds().height / 2);
	this->_topScores.setPosition(700, 350);
}

std::string ScoresState::FixScoreFormat(const std::string & score) const
{
	int lackingPlaces = 4 - score.size();
	std::string fixed = std::string(lackingPlaces, '0') + score;
	return fixed;
}
