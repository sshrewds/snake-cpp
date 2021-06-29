#pragma once

#include "GameObject.hpp"

class Apple : public GameObject
{
public:
	Apple(std::shared_ptr<GameData> data, sf::Vector2i fieldNum);
	virtual ~Apple();

	void SetRandomField();
};

