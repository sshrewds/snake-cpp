#pragma once
#include <SFML/Graphics.hpp>

#define FIELD_WIDTH 20.f
#define FIELD_HEIGHT 20.f
#define WINDOW_WIDTH 800.f
#define WINDOW_HEIGHT 600.f
#define MINIMUM_Y_FIELD Grid::GetFieldNum({0,120.f}).y + 1

static sf::Vector2i numberOfFields = { int(WINDOW_WIDTH / FIELD_WIDTH), int(WINDOW_HEIGHT / FIELD_HEIGHT) };

struct Grid
{
public:
	Grid();
	virtual ~Grid();

	static sf::Vector2f GetFieldCoords(const sf::Vector2i& numOfField);
	static sf::Vector2i GetFieldNum(const sf::Vector2f& positionOfField);
	//static bool IsInField(const sf::Vector2f& positionOfField, const sf::Vector2u& field);
	static sf::Vector2i GetRandomField();
};