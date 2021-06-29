#include "Game.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"


Game::Game(const int& width, const int& height, const std::string& title)
{
	/*Sets up window, creates first state: MENU*/
	this->_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	
	this->_data->window.setMouseCursorVisible(false);
	this->_data->window.setVerticalSyncEnabled(false);
	this->_data->window.setFramerateLimit(FRAMERATE);
	this->_data->window.setKeyRepeatEnabled(false);

	this->LoadTextures();
	this->LoadFonts();
	this->LoadSoundBuffers();

	this->_data->states.AddState(std::unique_ptr<State>(new MainMenuState(this->_data)));
}

Game::~Game()
{
}

void Game::LoadTextures()
{
	/*Loads all textures in a whole application*/

	/*MAIN MENU STATE*/
	for (const std::string& name : { "play", "scores", "info", "exit" }) {
		this->_data->assets.AddTexture(name, "resources/images/menu/" + name + ".png");
		this->_data->assets.AddTexture(name + "A", "resources/images/menu/" + name + "active.png");
	}
	this->_data->assets.AddTexture("menuBackground", "resources/images/menu/menuBackground.png");
	
	/*INFO STATE*/
	this->_data->assets.AddTexture("infoBackground", "resources/images/info/infoBackground.png");

	/*GAME STATE*/
	this->_data->assets.AddTexture("gameBackground", "resources/images/game/gameBackground.png");
	for (const std::string& type : { "head", "body", "tail", "apple"}) {
		this->_data->assets.AddTexture(type, "resources/images/game/"+type+".png");
	}
	this->_data->assets.AddTexture("heart", "resources/images/game/heart.png");
	this->_data->assets.AddTexture("brokenHeart", "resources/images/game/brokenHeart.png");

	this->_data->assets.AddTexture("scoreWindow", "resources/images/game/scoreWindow.png");
	
	/*SCORE STATE*/
	this->_data->assets.AddTexture("scoresBackground", "resources/images/scores/scoresBackground.png");
}

void Game::LoadFonts()
{
	/*Loads all fonts in a whole application*/
	this->_data->assets.AddFont("agency", "resources/fonts/AGENCYB.ttf");
}

void Game::LoadSoundBuffers()
{
	this->_data->assets.AddSoundBuffer("gameEnd", "resources/sounds/gameEnd.wav");
	this->_data->assets.AddSoundBuffer("lifeLost", "resources/sounds/lifeLost.wav");
	this->_data->assets.AddSoundBuffer("point", "resources/sounds/point.wav");
}


void Game::Run()
{
	this->_data->assets.menuMusic.play();
	/*Main game loop*/
	while (this->_data->window.isOpen())
	{
		/*Updates delta time*/
		this->UpdateDt();
		

		this->_data->window.clear();

		/*Manages states*/
		this->_data->states.ProcessStateChanges();

		this->_data->states.GetActiveState()->Update(this->dt);
		this->_data->states.GetActiveState()->Draw(this->dt);
		this->_data->states.GetActiveState()->HandleInput(this->dt);
		

		this->_data->window.display();
	}
}

void Game::UpdateDt()
{
	/*Updates dt with time it takes to process one frame*/
	this->dt = this->_clock.restart().asSeconds();
}



void Game::quitEvent(sf::RenderWindow &window, sf::Event& event)
{
	/*Handles window closing*/
	if (event.type == sf::Event::Closed)
		window.close();
}

