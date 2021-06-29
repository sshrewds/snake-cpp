#pragma once
#include "State.hpp"
#include "GameData.hpp"
#include "Gameplay/Snake.hpp"
#include "Gameplay/Apple.hpp"
#include "Gameplay/Life.hpp"
#include "Gameplay/PointsPopUp.hpp"
#include "Gameplay/ScorePopUp.hpp"


class GameState :public State
{
private:
	std::shared_ptr<GameData> _data;
	sf::Sprite _background;
	sf::Text _score;
	sf::Clock _scoreClock;
	int _points = 0;
	sf::Sound _lifeLostSound, _gameEndSound, _pointSound;
	sf::Music _backgroundMusic;

	//Game objects
	Snake _snake = Snake(this->_data);
	Apple _apple = Apple(this->_data,Grid::GetRandomField());
	std::vector<std::shared_ptr<Life>> _lives;
	int _livesLeft = 3;
	PointsPopUp _popUpPoints = PointsPopUp(this->_data);
	ScorePopUp _popUpFinalScore;
	
public:
	//CONSTRUCTORS/DESTRUCTORS
	GameState(std::shared_ptr<GameData> data);
	virtual ~GameState();

	//PUBLIC METHODS
	void Init() override;
	void Draw(const float& dt) override;
	void Update(const float& dt) override;
	void HandleInput(const float & dt) override;
};

