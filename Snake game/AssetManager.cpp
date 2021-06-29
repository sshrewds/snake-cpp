#include "AssetManager.hpp"




AssetManager::AssetManager()
{
	this->menuMusic.openFromFile("resources/sounds/menu.ogg");
	this->menuMusic.setVolume(70);
}


AssetManager::~AssetManager()
{
}

void AssetManager::AddTexture(const std::string & name, const std::string & fileName)
{
	sf::Texture texture;
	if (texture.loadFromFile(fileName)) {
		this->_textures[name] = texture;
		std::cout << "Successfully loaded " << name << " texture at: " << fileName << std::endl;
	}
	else {
		std::cout << "Couldn't load " << name << " texture at: " << fileName << std::endl;
	}
}

sf::Texture & AssetManager::GetTexture(const std::string & name)
{
	return this->_textures.at(name);
}

void AssetManager::AddFont(const std::string & name, const std::string & fileName)
{
	sf::Font font;
	if (font.loadFromFile(fileName)) {
		this->_fonts[name] = font;
	}
	else {
		std::cout << "Couldn't load up " << name << " font at: " << fileName << std::endl;
	}
}

sf::Font & AssetManager::GetFont(const std::string & name)
{
	return this->_fonts.at(name);
}

void AssetManager::AddSoundBuffer(const std::string & name, const std::string & fileName)
{
	sf::SoundBuffer buf;
	if (buf.loadFromFile(fileName)) {
		this->_soundBuffers[name] = buf;
	}
	else {
		std::cout << "Couldn't load up " << name << " sound buffer at: " << fileName << std::endl;
	}
}

sf::SoundBuffer & AssetManager::GetSoundBuffer(const std::string & name)
{
	return this->_soundBuffers.at(name);
}
