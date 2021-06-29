#include "Life.hpp"





Life::Life(std::shared_ptr<GameData>& data, const sf::Vector2f & position) : _data(data), _position(position)
{
	this->sprite.setTexture(this->_data->assets.GetTexture("heart"));
	this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
	this->sprite.setPosition(this->_position);
	
}

Life::~Life()
{
}

void Life::RemoveLife()
{
	this->sprite.setTexture(this->_data->assets.GetTexture("brokenHeart"),true);
	//this->sprite.set
	//this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
	/*this->_position.x -= 10;
	this->sprite.setPosition(this->_position);
	this->sprite.set*/
}
