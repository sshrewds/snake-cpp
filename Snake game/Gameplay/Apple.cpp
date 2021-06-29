#include "Apple.hpp"



Apple::Apple(std::shared_ptr<GameData> data, sf::Vector2i fieldNum) : GameObject(data,fieldNum)
{
	this->_type = "apple";
	this->SetTexture(this->_type);
}

Apple::~Apple()
{
}

void Apple::SetRandomField() 
{
	sf::Vector2i randomField;
	do {
		randomField = Grid::GetRandomField();
	}while(randomField == this->numOfField);
	this->numOfField = randomField;

	this->sprite.setPosition(Grid::GetFieldCoords(this->numOfField));  //add function for setting field
	std::cout << Grid::GetFieldCoords(randomField).x << " " << Grid::GetFieldCoords(randomField).y << std::endl;
}
