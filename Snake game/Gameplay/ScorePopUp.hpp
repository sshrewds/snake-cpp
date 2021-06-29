#pragma once
#include "../GameData.hpp"
#include "../State.hpp"
class ScorePopUp
{
private:
	std::shared_ptr<GameData> _data;
	sf::Sprite _background;
	sf::Text _scoreInfo;
	sf::Text _userName;
	sf::Sprite _gameScreenshot;
	std::string _userInput="";
	int _score;

public:
	ScorePopUp(std::shared_ptr<GameData> data, const int &score);
	ScorePopUp();
	virtual ~ScorePopUp();

	void Init();
	void Draw(const float& dt);
	void Update();
	void HandleInput(sf::Event& e);
	void SaveToFile(const std::string& fileName);
	
};

