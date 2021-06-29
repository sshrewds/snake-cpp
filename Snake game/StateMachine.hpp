#pragma once
#include <stack>
#include <memory>
#include "State.hpp"
class StateMachine
{
private:
	std::stack< std::unique_ptr<State> > _states;
	std::unique_ptr<State> _newState;

	bool _isAdding, _isReplacing, _isRemoving;

public:
	StateMachine();
	virtual ~StateMachine();

	void AddState(std::unique_ptr<State> newState, bool isReplacing = true);
	void RemoveState();
	void ProcessStateChanges();

	std::unique_ptr<State>& GetActiveState();
};

