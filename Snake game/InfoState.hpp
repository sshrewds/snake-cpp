#pragma once
#include "State.hpp"
#include "GameData.hpp"

class InfoState :public State
{
private:
	std::shared_ptr<GameData> _data;
	sf::Sprite _background;
	
public:
	InfoState(std::shared_ptr<GameData> data);
	virtual ~InfoState();

	void Init() override;
	void Draw(const float& dt) override;
	void Update(const float& dt) override;
	void HandleInput(const float & dt) override;
};

