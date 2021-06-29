#pragma once

//#include "Game.hpp"
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
class AssetManager
{
private:
	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;
	std::map<std::string, sf::SoundBuffer> _soundBuffers;
public:
	sf::Music menuMusic;
public:
	AssetManager();
	virtual ~AssetManager();

	void AddTexture(const std::string& name, const std::string& fileName);
	sf::Texture& GetTexture(const std::string& name);

	void AddFont(const std::string& name, const std::string& fileName);
	sf::Font& GetFont(const std::string& name);

	void AddSoundBuffer(const std::string& name, const std::string& fileName);
	sf::SoundBuffer& GetSoundBuffer(const std::string& name);

};
