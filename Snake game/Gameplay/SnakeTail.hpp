#pragma once
#include "SnakePart.hpp"
class SnakeTail : public SnakePart
{
public:
	SnakeTail(std::shared_ptr<GameData> data, sf::Vector2i fieldNum, Direction dir);
	virtual ~SnakeTail();
};

