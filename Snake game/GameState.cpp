#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "Gameplay/ScorePopUp.hpp"
#include "Game.hpp"
#include <cmath>
#include <thread>

//CONSTRUCTORS/DESTRUCTORS
GameState::GameState(std::shared_ptr<GameData> data)
	:_data(data){}

GameState::~GameState(){}


//PUBLIC METHODS
void GameState::Init()
{
	this->_data->assets.menuMusic.stop();

	this->_score.setFont(this->_data->assets.GetFont("agency"));
	this->_score.setPosition(750, 50);
	
	/*Sets up textures*/
	this->_background.setTexture(this->_data->assets.GetTexture("gameBackground"));
	this->_scoreClock.restart();
	this->_score.setString("0");

	/*Sets up lives*/
	sf::Vector2f pos = { 50,60 };
	for (int i = 0; i < 3; i++, pos.x += 70)
		this->_lives.push_back(std::make_shared<Life>(this->_data, pos));

	/*Sets up sounds*/
	this->_gameEndSound.setBuffer(this->_data->assets.GetSoundBuffer("gameEnd"));
	this->_lifeLostSound.setBuffer(this->_data->assets.GetSoundBuffer("lifeLost"));
	this->_pointSound.setBuffer(this->_data->assets.GetSoundBuffer("point"));

	this->_backgroundMusic.openFromFile("resources/sounds/game.ogg");
	this->_backgroundMusic.play();
	this->_backgroundMusic.setVolume(70);
}

void GameState::Draw(const float & dt)
{
	/*Draws all elements of game state*/
	this->_data->window.draw(this->_background);
	this->_snake.Draw(dt);

	this->_data->window.draw(this->_apple.sprite);
	this->_data->window.draw(this->_score);
	for (std::shared_ptr<Life>& l : std::move(_lives)) {
		this->_data->window.draw(l->sprite);
	}

	this->_popUpPoints.Draw(dt);

	if (this->_livesLeft == 0) {
		this->_popUpFinalScore.Draw(dt);
	}
}

void GameState::Update(const float & dt)
{
	
	/*Updates all elements of game state*/
	
	/*Checks if apple was eaten*/
	if (this->_snake.currentHeadField == this->_apple.numOfField) {
		_snake.GrowSnake();
		_apple.SetRandomField();

		int deltaPoints = int(15 / this->_scoreClock.getElapsedTime().asSeconds()) + 1;
		this->_popUpPoints.SetText(std::to_string(deltaPoints), Grid::GetFieldCoords(this->_snake.currentHeadField));

		this->_points += deltaPoints;
		this->_score.setString(std::to_string(this->_points));
		this->_scoreClock.restart();
		//if (this->_snake.speed < 50)
		//	this->_snake.speed = /*(this->_points / 50)*//*20 * log10(this->_points)*//*+25*/30.5 + pow(1.01, this->_points);
		//else
		//	this->_snake.speed = 50 + pow(1.002, this->_points);
		this->_snake.speed = 1.5*(this->_points / 25) + 30.5f;
		std::cout << this->_snake.speed << std::endl;

		this->_pointSound.play();
	}

	/*Checks if snake has eaten itself*/
	if (this->_snake.hasEatenItself) {
		this->_livesLeft--;
		this->_lives[this->_livesLeft]->RemoveLife();
		this->_snake.hasEatenItself = false;

		/*Checks if snake is dead*/
		if (this->_livesLeft == 0) {
			/*sf::Texture screenshot;
			screenshot.create(this->_data->window.getSize().x, this->_data->window.getSize().y);
			screenshot.update(this->_data->window);
			sf::Image img = screenshot.copyToImage();*/

			/*img.saveToFile("test.png");*/

			/*this->_data->states.AddState(std::unique_ptr<State>(new ScorePopUpState(this->_data, this->_points, screenshot)));*/
			this->_popUpFinalScore = ScorePopUp(this->_data, this->_points);
			this->_snake.canMove = false;

			this->_gameEndSound.play();
			this->_backgroundMusic.setVolume(45);
		}
		else
			this->_lifeLostSound.play();
	}
	this->_snake.UpdateSnake(dt);
}

void GameState::HandleInput(const float & dt)
{
	/*Handles user input*/
	sf::Event e;
	
	if (this->_data->window.pollEvent(e)) {
		if (this->_livesLeft > 0) {
			if (e.type == sf::Event::KeyPressed) {

				if (e.key.code == sf::Keyboard::Escape) {
					/*If Esc is pressed, changes state to MENU*/
					this->_data->states.AddState(std::unique_ptr<State>(new MainMenuState(this->_data)));
				}
			}


			/*Handles input refering to snake*/
			this->_snake.HandleInput(e, dt);
		}
		
		else {
			this->_popUpFinalScore.HandleInput(e);
		}

		/*Handles closing window event*/
		Game::quitEvent(this->_data->window, e);
	}
}
