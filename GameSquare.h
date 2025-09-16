#pragma once

#ifndef GAMESQUARE_H
#define GAMESQUARE_H


class GameSquare
{
private:
	bool curState;

public:
	GameSquare() : curState(false){};
	GameSquare(bool inPlay) : curState(inPlay) {};

	//Precondition: Valid Gamesquare instance
	//Post condition: Will know the current state of gamesquare (occupied or not)
	bool occupied() const noexcept {
		return curState;
	}
	//precondition boolean value true of false
	//postcondition state will be updated accordingly
	void setState(bool nState) noexcept{
		curState = nState;
	}
	
	explicit operator bool() const noexcept {
		return curState;
	}
};

#endif
