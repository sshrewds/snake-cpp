#include "StateMachine.hpp"



StateMachine::StateMachine()
{
}


StateMachine::~StateMachine()
{
}

void StateMachine::AddState(std::unique_ptr<State> newState, bool isReplacing)
{
	this->_isAdding = true;
	this->_isReplacing = isReplacing;
	this->_newState = std::move(newState);
}

void StateMachine::RemoveState()
{
	this->_isRemoving = true;
}

void StateMachine::ProcessStateChanges()
{
	if (_isRemoving && !this->_states.empty()) {
		this->_isRemoving = false;
		this->_states.pop();
	}
	if (_isAdding) {
		this->_isAdding = false;
		if (this->_isReplacing&& !this->_states.empty()) {
			this->_states.pop();
		}

		this->_states.push(std::move(this->_newState));
		this->_states.top()->Init();
	}

}

std::unique_ptr<State>& StateMachine::GetActiveState()
{
	return this->_states.top();
}

