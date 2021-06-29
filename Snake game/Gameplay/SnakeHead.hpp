#pragma once
#include "SnakePart.hpp"
class SnakeHead : public SnakePart
{
public:
	SnakeHead(std::shared_ptr<GameData> data, sf::Vector2i fieldNum, Direction dir);
	virtual ~SnakeHead();

};

