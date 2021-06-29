#include "Snake.hpp"
#include "Direction.hpp"
#include "../GameState.hpp"

/*TO-DO:
- block changing direction if snake is out of board
- eating tail*/

Snake::Snake(std::shared_ptr<GameData> data) :_data(data)
{	
	this->AddSnakePart(std::make_shared<SnakeHead>(this->_data, sf::Vector2i(10,10), Direction::Right));
	this->AddSnakePart(std::make_shared<SnakeBody>(this->_data, sf::Vector2i(9,10), Direction::Right));
	this->AddSnakePart(std::make_shared<SnakeBody>(this->_data, sf::Vector2i(8,10), Direction::Right));
	this->AddSnakePart(std::make_shared<SnakeTail>(this->_data, sf::Vector2i(7,10), Direction::Right));
	

	this->_nextMove = Direction::Right;
	this->currentHeadField = this->_snakeParts.front()->numOfField;
	this->_gameSpeedClock.restart();
}

Snake::~Snake()
{
}

void Snake::Draw(const float & dt)
{
	for (std::shared_ptr<SnakePart>& part : std::move(_snakeParts)) {
		this->_data->window.draw(part->sprite);
	}
}


void Snake::MoveSnake(const float & dt)
{
	if (canMove) {
		switch (this->_nextMove) {
		case Direction::Up:
			currentHeadField.y--;
			break;

		case Direction::Right:
			currentHeadField.x++;
			break;

		case Direction::Down:
			currentHeadField.y++;
			break;

		case Direction::Left:
			currentHeadField.x--;
			break;
		}

		this->_snakeParts.front() = std::static_pointer_cast<SnakeBody>(this->_snakeParts.front());
		this->_snakeParts.front()->SetTexture("body");

		this->_snakeParts.insert(this->_snakeParts.begin(), std::make_shared<SnakeHead>(this->_data, this->currentHeadField, this->_nextMove));

		this->_snakeParts.pop_back();

		this->_snakeParts.back() = std::static_pointer_cast<SnakeTail>(this->_snakeParts.back());
		this->_snakeParts.back()->SetTexture("tail");
		this->_snakeParts.back()->SetDirection(this->_snakeParts[this->_snakeParts.size() - 2]->direction);
	}
}

void Snake::UpdateSnake(const float & dt)
{
	frameCounter++;
	if (this->_gameSpeedClock.getElapsedTime().asSeconds() >= (1 / this->speed)) {
		//if (frameCounter % 4 == 0) {  //----ADD VARIABLE FOR THAT
		
		if (!this->OutOfBoardHandling()) {
			//std::cout << this->currentHeadField.x << " " << this->currentHeadField.y << Grid::GetFieldCoords({ 0,0 }).x<< std::endl;
	//}		
		/*if (this->_hasEatenItself) {
			sf::Clock pause;
			pause.restart();
			while (pause.getElapsedTime().asSeconds() < 0.1) {}
			this->_hasEatenItself = false;
		}*/
			if (!this->IsFieldATail(this->currentHeadField)) {
				this->hasEatenItself = true;
				this->EatTail(this->currentHeadField);
			}
			this->_gameSpeedClock.restart();
			this->_hasRecentMoveProcessed = true;
			
		}
		this->MoveSnake(dt);
		
		
	}
	
}



void Snake::AddSnakePart(std::shared_ptr<SnakePart> newPart)
{
	this->_snakeParts.push_back(std::move(newPart));
}

void Snake::GrowSnake()
{
	this->_length++;
	std::cout << this->_length << std::endl;

	sf::Vector2i tailField = this->_snakeParts.back()->numOfField;
	this->_snakeParts.insert(this->_snakeParts.end()-1, std::make_shared<SnakeBody>(this->_data, tailField, this->_snakeParts.back()->direction));
	
	switch (this->_snakeParts.back()->direction) {
	case Direction::Up:
		tailField.y++;
		break;

	case Direction::Right:
		tailField.x--;
		break;

	case Direction::Down:
		tailField.y--;
		break;

	case Direction::Left:
		tailField.x++;
		break;
	}
	this->_snakeParts.back()->numOfField = tailField;
	
}

void Snake::HandleInput(const sf::Event &event,const float & dt)
{
		
	if (event.type == sf::Event::KeyPressed && this->_hasRecentMoveProcessed) {

			if (event.key.code == sf::Keyboard::Up && _nextMove != Direction::Down) {	
				this->_nextMove = Direction::Up;
			}

			if (event.key.code == sf::Keyboard::Right && _nextMove != Direction::Left) {
				this->_nextMove = Direction::Right;
			}

			if (event.key.code == sf::Keyboard::Down && _nextMove != Direction::Up) {
				this->_nextMove = Direction::Down;
			}

			if (event.key.code == sf::Keyboard::Left && _nextMove != Direction::Right) {
				this->_nextMove = Direction::Left;
			}
			
			if (event.key.code == sf::Keyboard::Key::D) { //!
				this->GrowSnake();
			}

			this->_hasRecentMoveProcessed = false;
	}
}

bool Snake::OutOfBoardHandling()
{
	/*if (this->currentHeadField.x == numberOfFields.x && this->_nextMove == Direction::Right)
		this->currentHeadField.x = -1;

	else if (this->currentHeadField.x == 0 && this->_nextMove == Direction::Left)
		this->currentHeadField.x = numberOfFields.x+1;

	else if (this->currentHeadField.y == numberOfFields.y && this->_nextMove == Direction::Down)
		this->currentHeadField.y = minYField-1;

	else if (this->currentHeadField.y == minYField && this->_nextMove == Direction::Up)
		this->currentHeadField.y = numberOfFields.y + 1;*/
	//std::cout << currentHeadField.x << " " << currentHeadField.y << std::endl;
	/*if (this->currentHeadField.x > numberOfFields.x-1)*/ if (this->currentHeadField.x == numberOfFields.x-1 && this->_nextMove == Direction::Right) {
		this->currentHeadField.x = -1;
		std::cout << Grid::GetFieldCoords(this->currentHeadField).x << " " << Grid::GetFieldCoords(this->currentHeadField).y << std::endl;
		std::cout << this->_snakeParts.front()->sprite.getOrigin().x << " " << this->_snakeParts.front()->sprite.getOrigin().y << std::endl;
		return true;
	}	

	/*else*/ /*if (this->currentHeadField.x < 0)*/if (this->currentHeadField.x == 0 && this->_nextMove == Direction::Left) {
		this->currentHeadField.x = numberOfFields.x;
		std::cout << Grid::GetFieldCoords(this->currentHeadField).x << " " << Grid::GetFieldCoords(this->currentHeadField).y << std::endl;
		std::cout << this->_snakeParts.front()->sprite.getOrigin().x << " " << this->_snakeParts.front()->sprite.getOrigin().y << std::endl;

		return true;
	}
		

	/*else*/ /*if (this->currentHeadField.y > numberOfFields.y-1)*/ if (this->currentHeadField.y == numberOfFields.y-1 && this->_nextMove == Direction::Down) {
		this->currentHeadField.y = minYField;
		std::cout << Grid::GetFieldCoords(this->currentHeadField).x << " " << Grid::GetFieldCoords(this->currentHeadField).y << std::endl;
		return true;
	}
		

	/*else*/ /*if (this->currentHeadField.y < minYField+1)*/ if (this->currentHeadField.y == minYField+1 && this->_nextMove == Direction::Up) {
		this->currentHeadField.y = numberOfFields.y;
		std::cout << Grid::GetFieldCoords(this->currentHeadField).x << " " << Grid::GetFieldCoords(this->currentHeadField).y << std::endl;
		return true;
	}
		
	return false;
	//this->MoveSnake(0.1f);
}

bool Snake::IsFieldATail(sf::Vector2i fieldNum)
{
	for (std::shared_ptr<SnakePart>& part : std::move(_snakeParts)) {
		if (fieldNum == part->numOfField && part->GetType()!= "head")
			return false;
	}
	return true;
}

void Snake::EatTail(sf::Vector2i numOfFieldToStart)
{
	for (int i = this->_snakeParts.size() - 1; this->_snakeParts.at(i)->numOfField != numOfFieldToStart; i--)
		this->_snakeParts.pop_back();
	this->_snakeParts.pop_back();
	this->_length = this->_snakeParts.size();
	//std::cout << _length << std::endl;

	//this->hasEatenItself = false;
}

int Snake::GetLength() const
{
	return this->_length;
}
