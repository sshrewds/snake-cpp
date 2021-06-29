#pragma once

#include "../GameData.hpp"
#include "SnakeHead.hpp"
#include "SnakeBody.hpp"
#include "SnakeTail.hpp"


#include <vector>


#define START_SPEED 30.5f
#define MINIMUM_Y_COORD 120.f


class Snake
{

private:
	std::shared_ptr<GameData> _data;
	std::vector< std::shared_ptr<SnakePart> > _snakeParts;
	int _length = 4;
	
	
	sf::Clock _gameSpeedClock;

	Direction _nextMove;
	int frameCounter = 0;
	int minYField = Grid::GetFieldNum({ 0,MINIMUM_Y_COORD }).y;
	bool _hasRecentMoveProcessed = true;
public:
	sf::Vector2i currentHeadField;
	float speed = START_SPEED;
	bool hasEatenItself = false;
	bool canMove = true;
	


public:
	Snake(std::shared_ptr<GameData> data);
	virtual ~Snake();

	void Draw(const float& dt);

	void MoveSnake(const float& dt);
	void UpdateSnake(const float& dt);
	void AddSnakePart(std::shared_ptr<SnakePart> newPart);
	void GrowSnake();					
	void HandleInput(const sf::Event& event,const float& dt);
	bool OutOfBoardHandling();

	bool IsFieldATail(sf::Vector2i fieldNum);	
	void EatTail(sf::Vector2i numOfFieldToStart);
	int GetLength() const;
};

