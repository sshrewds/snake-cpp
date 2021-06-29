#pragma once

#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "GameData.hpp"

#define FRAMERATE 200


class Game
{
private:
	std::shared_ptr<GameData> _data = std::make_shared<GameData>();
	
	sf::Clock _clock;
	float dt;
public:
	Game(const int& width, const int& height, const std::string& title);
	virtual ~Game();

	void Run();
	void UpdateDt();
	void LoadTextures();
	void LoadFonts();
	void LoadSoundBuffers();
	
	//Static methods
	static void quitEvent(sf::RenderWindow &window, sf::Event& event);
};

