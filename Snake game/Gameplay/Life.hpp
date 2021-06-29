#pragma once
#include "SFML/Graphics.hpp"
#include "../GameData.hpp"
class Life
{
private:
	std::shared_ptr<GameData> _data;
	sf::Vector2f _position;
public:
	sf::Sprite sprite;
public:
	Life(std::shared_ptr<GameData>& data, const sf::Vector2f & position);
	virtual ~Life();

	void RemoveLife();
};

