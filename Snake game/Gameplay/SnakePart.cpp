#include "SnakePart.hpp"



SnakePart::SnakePart(std::shared_ptr<GameData> data, sf::Vector2i fieldNum, Direction dir) : GameObject(data,fieldNum)
{
	this->SetDirection(dir);
}


SnakePart::~SnakePart()
{
}


void SnakePart::SetDirection(Direction direction)
{
	this->direction = direction;
	if(this->_type!= "body")
		this->sprite.setRotation(this->direction * 90.f);
}

