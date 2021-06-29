#include "PointsPopUp.hpp"





PointsPopUp::PointsPopUp(const std::shared_ptr<GameData>& data): _data(data)
{
	this->_text.setFont(this->_data->assets.GetFont("agency"));
}

PointsPopUp::~PointsPopUp()
{
}

void PointsPopUp::SetText(const std::string & text, const sf::Vector2f& position)
{
	this->_text.setString(text);
	///setCharactersize
	this->_text.setOrigin(this->_text.getLocalBounds().width / 2, this->_text.getLocalBounds().height / 2);
	this->_text.setPosition(position);

	this->_color = sf::Color(241, 90, 36);
	this->_text.setFillColor(this->_color);
	this->_transparency = 255;

	this->_scale = { 1,1 };
	this->_text.setScale(this->_scale);
}

void PointsPopUp::Draw(const float & dt)
{
	this->_transparency -= 500 * dt;
	if (this->_transparency > 0) {	
		this->_color.a = this->_transparency;

		this->_text.setFillColor(this->_color);
		this->_scale.x += dt * 3;
		this->_scale.y += dt * 3;
		this->_text.setScale(this->_scale);

		this->_data->window.draw(this->_text);
	}
	

}
