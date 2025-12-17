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

    static int CheckEffectiveness(Type defenderType, Move move) {

        int modifier = 10;

        switch (defenderType)
        {
        case Type::NORMAL:
            if (move.GetType() == Type::FIGHTING)
            {
                modifier = 20;
            }

            if (move.GetType() == Type::GHOST)
            {
                modifier = 0;
            }

            break;
        case Type::FIRE:
            if (move.GetType() == Type::FIRE || move.GetType() == Type::GRASS || move.GetType() == Type::BUG)
            {
                modifier = 5;
            }

            if (move.GetType() == Type::WATER || move.GetType() == Type::GROUND || move.GetType() == Type::ROCK) {
                modifier = 20;
            }

            break;
        case Type::WATER:
            if (move.GetType() == Type::FIRE || move.GetType() == Type::WATER || move.GetType() == Type::ICE)
            {
                modifier = 5;
            }

            if (move.GetType() == Type::ELECTRIC || move.GetType() == Type::GRASS)
            {
                modifier = 20;
            }
            break;
        case Type::ELECTRIC:
            if (move.GetType() == Type::ELECTRIC || move.GetType() == Type::FLYING)
            {
                modifier = 5;
            }

            if (move.GetType() == Type::GROUND)
            {
                modifier = 20;
            }

            break;
        case Type::GRASS:
            if (move.GetType() == Type::WATER || move.GetType() == Type::ELECTRIC || move.GetType() == Type::GRASS || move.GetType() == Type::GROUND)
            {
                modifier = 5;
            }

            if (move.GetType() == Type::FIRE || move.GetType() == Type::ICE || move.GetType() == Type::POISON || move.GetType() == Type::FLYING || move.GetType() == Type::BUG)
            {
                modifier = 20;
            }
            break;
        }

        return modifier;
    }
};