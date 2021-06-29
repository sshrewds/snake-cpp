#pragma once
#include "State.hpp"
#include "GameData.hpp"

class ScoresState :public State
{
private:
	std::shared_ptr<GameData> _data;
	sf::Sprite _background;
	//sf::Text _topScoresList;
	sf::Text _names;
	sf::Text _topScores;

public:
	ScoresState(std::shared_ptr<GameData> data);
	virtual ~ScoresState();

	void Init() override;
	void Draw(const float& dt) override;
	void Update(const float& dt) override;
	void HandleInput(const float & dt) override;

	void LoadScores();
	std::string FixScoreFormat (const std::string& score) const;
};

