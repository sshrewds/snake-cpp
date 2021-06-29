#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <iostream>
#include "StateMachine.hpp"
#include "AssetManager.hpp"

struct GameData {
	/*Holds all necessary data to control game flow*/

	sf::RenderWindow window;
	StateMachine states;
	AssetManager assets;
};

