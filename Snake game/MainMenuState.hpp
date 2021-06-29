#pragma once
#include "State.hpp"
#include "GameData.hpp"

class MainMenuState :public State
{
private:
	std::shared_ptr<GameData> _data;
	//sf::Sprite button;
	sf::Sprite _background;
	std::string _activeButton = "play";
	int _activeButtonIndex = 0;
	std::string _buttonNames[4] = { "play","scores","info", "exit" };
	std::map <std::string, sf::Sprite[2]> _buttons;
	//std::map <std::string, sf::Sprite>::iterator buttonsIterator;
public:
	MainMenuState(std::shared_ptr<GameData> data);
	virtual ~MainMenuState();

	void Init() override;
	void Draw(const float& dt) override;
	void Update(const float& dt) override;
	void HandleInput(const float & dt) override;
};

