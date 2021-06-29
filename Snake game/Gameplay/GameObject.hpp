#pragma once

#include "../GameData.hpp"
#include "Grid.hpp"

#define OBJECT_WIDTH 20.f
#define OBJECT_HEIGHT 20.f

class GameObject
{
protected:
	std::string _type;
	std::shared_ptr<GameData> _data;
public:
	sf::Sprite sprite;
	sf::Vector2f size = { OBJECT_WIDTH, OBJECT_HEIGHT };
	sf::Vector2i numOfField;
public:
	GameObject(std::shared_ptr<GameData> data, sf::Vector2i fieldNum);
	virtual ~GameObject();

	void SetTexture(const std::string& type);
	const std::string& GetType() const;
};

