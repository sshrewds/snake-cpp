#pragma once
#include "SnakePart.hpp"
class SnakeBody : public SnakePart
{
public:
	SnakeBody(std::shared_ptr<GameData> data, sf::Vector2i fieldNum, Direction dir);
	virtual ~SnakeBody();
};

