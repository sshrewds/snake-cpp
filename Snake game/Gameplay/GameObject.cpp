#include "GameObject.hpp"


GameObject::GameObject(std::shared_ptr<GameData> data, sf::Vector2i fieldNum): _data(data), numOfField(fieldNum)
{
	this->sprite.setOrigin(this->size.x / 2, this->size.y / 2);
	this->sprite.setPosition(Grid::GetFieldCoords(this->numOfField));
}

GameObject::~GameObject()
{
}

void GameObject::SetTexture(const std::string & type)
{
	this->_type = type;
	this->sprite.setTexture(this->_data->assets.GetTexture(type));
}

const std::string & GameObject::GetType() const
{
	return this->_type;
}
