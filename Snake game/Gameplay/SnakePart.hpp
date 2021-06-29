#pragma once
#include "../GameData.hpp"
#include "GameObject.hpp"
#include "Direction.hpp"
#include "Grid.hpp"


#define PART_WIDTH 20.f
#define PART_HEIGHT 20.f

class SnakePart:public GameObject
{

public:
	Direction direction;
	
public:
	SnakePart(std::shared_ptr<GameData> data, sf::Vector2i fieldNum, Direction dir);
	virtual ~SnakePart();

	void SetDirection(Direction direction); 
};

