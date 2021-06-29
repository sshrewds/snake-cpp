#include "Grid.hpp"
#include <cstdlib>


Grid::Grid()
{
}


Grid::~Grid()
{
}

sf::Vector2f Grid::GetFieldCoords(const sf::Vector2i & numOfField)
{
	return sf::Vector2f(FIELD_WIDTH*(numOfField.x + 0.5f), FIELD_HEIGHT*(numOfField.y + 0.5f));
}

sf::Vector2i Grid::GetFieldNum(const sf::Vector2f & positionOfField)
{
	return sf::Vector2i(int((positionOfField.x - 0.5*FIELD_WIDTH)/FIELD_WIDTH), int((positionOfField.y - 0.5*FIELD_HEIGHT) / FIELD_HEIGHT));
}

sf::Vector2i Grid::GetRandomField()
{
	srand(time(NULL));

	return sf::Vector2i(rand() % (numberOfFields.x-1), int(rand() % (numberOfFields.y-2-MINIMUM_Y_FIELD)+MINIMUM_Y_FIELD));
}
