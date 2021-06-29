#include "SnakeTail.hpp"

SnakeTail::SnakeTail(std::shared_ptr<GameData> data, sf::Vector2i fieldNum, Direction dir) :SnakePart(data, fieldNum, dir)
{
	this->_type = "tail";
	this->SetTexture(this->_type);
}


SnakeTail::~SnakeTail()
{
}
