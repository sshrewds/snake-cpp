#include "SnakeBody.hpp"

SnakeBody::SnakeBody(std::shared_ptr<GameData> data, sf::Vector2i fieldNum, Direction dir) :SnakePart(data, fieldNum, dir)
{
	this->_type = "body";
	this->SetTexture(this->_type);
}


SnakeBody::~SnakeBody()
{
}