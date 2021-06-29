#include "SnakeHead.hpp"

SnakeHead::SnakeHead(std::shared_ptr<GameData> data, sf::Vector2i fieldNum, Direction dir):SnakePart(data, fieldNum, dir )
{
	this->_type = "head";
	this->SetTexture(this->_type);
}


SnakeHead::~SnakeHead()
{
}

