#pragma once
#include <string>
#include "Type.hpp"

class Move {
	std::string name;
	Type type;
	float accuracy;
	int power;
	int currentPp;
	int maxPp;

public:
	Move() {
		name = "";
		type = Type::NONE;
		power = -1;
		accuracy = -1.0f;
		currentPp = -1;
		maxPp = -1;
	}

	Move(std::string _name, Type _type, int _power, float _accuracy, int _currentPp, int _maxPp) {
		name = _name;
		type = _type;
		power = _power;
		accuracy = _accuracy;
		currentPp = _currentPp;
		maxPp = _maxPp;
	}

	std::string GetName() {
		return name;
	}

	Type GetType() {
		return type;
	}

	int GetPower() {
		return power;
	}
};