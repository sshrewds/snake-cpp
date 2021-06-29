#pragma once
class State
{
public:
	State();
	virtual ~State();

	virtual void Init() = 0;
	virtual void Draw(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void HandleInput(const float & dt) = 0;
	
};

