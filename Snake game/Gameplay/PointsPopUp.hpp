#pragma once
#include "../GameData.hpp"

class PointsPopUp
{
private:
	sf::Text _text;
	float _transparency = 0;
	sf::Vector2f _scale;
	std::shared_ptr<GameData> _data;
	sf::Color _color;
	
public:
	PointsPopUp(const std::shared_ptr<GameData>& data);
	virtual ~PointsPopUp();

	void SetText(const std::string& text, const sf::Vector2f& position);
	void Draw(const float& dt);
};

