#pragma once
#include <string>
#include "Type.hpp"
#include "Move.h"

class Pokemon {
	// Fields
	std::string name;
	int level;
	int totalHp;
	int currentHp;
	int attack;
	int defense;
	int special;
	Type type1;
	Type type2;
	std::vector<Move> moves;
	std::vector<Move> forgottenMoves;

public:
	// Default constructor
	Pokemon() {
		type1 = Type::NONE; // No pokemon should have no type
		type2 = Type::NONE;
		name = "";
		level = -1;
		totalHp = -1;
		currentHp = -1;
		attack = -1;
		defense = -1;
		special = -1;
		moves = std::vector<Move>(4);
	}

	// Overloaded constructor
	Pokemon(std::string _name, int _level, int _currentHp, int _totalHp, 
		int _attack, int _defense, int _special, Type _type1, Type _type2,
		std::vector<Move> _moves = std::vector<Move>(4)) {
			
		name = _name;
		level = _level;
		currentHp = _currentHp;
		totalHp = _totalHp;
		attack = _attack;
		defense = _defense;
		special = _special;
		type1 = _type1;
		type2 = _type2;
		moves = _moves;
	}

	// Access
	std::string GetName() {
		return name;
	}

	int GetLevel() {
		return level;
	}

	int GetCurrentHp() {
		return currentHp;
	}

	int GetTotalHp() {
		return totalHp;
	}

	int GetAttack() {
		return attack;
	}

	int GetDefense() {
		return defense;
	}

	int GetSpecial() {
		return special;
	}

	Type GetType1() {
		return type1;
	}

	Type GetType2() {
		return type2;
	}

	/// <summary>
	/// Attempts to add a new move to the Pokemon's move collection.
	/// </summary>
	/// <param name="move">Move object to add</param>
	/// <returns></returns>
	bool LearnMove(Move move) {
		// Initialize a default result
		bool result = false;

		// Iterate through the moves collection
		for (int i = 0; i < moves.size(); i++) {
			Move currentMove = moves[i];
		
			// Look for an empty space in the collection
			// by identifying a default move
			if (currentMove.GetType() == Type::NONE) {
				// replace the default move with the provided mode
				moves[i] = move;

				// Set the result to true
				result = true;

				// Stop looking
				break;
			}
		}

		// Return result
		return result;
	}

	// Forget a move based on user menu selection
	bool ForgetMoveAtPosition(int position) {
		// Initialize default result
		bool result = false;
		
		// Pull move from moves at the given position
		Move moveInPosition = moves[position];

		// Check to see if that position contains a move
		// by seeing if it's a default object or not
		if (moveInPosition.GetType() != Type::NONE) {
			// If it's not already default
			// add it to a list of forgotten moves...
			forgottenMoves.push_back(moveInPosition);

			// replace it with a default move.
			moves[position] = Move();
			
			// and set result to true
			bool result = true;
		}
		
		// Set the result
		return result;
	}

	// Forget a specific move by name
	bool ForgetMove(std::string name) {
		// Initialize placeholder result
		bool result = false;

		// Iterate through the moves collection
		for (int i = 0; i < moves.size(); i++) {
			// Create a reference of the current move
			Move currentMove = moves[i];

			// If the current move's name matches the provided
			// name parameter...
			if (currentMove.GetName() == name) {
				// Set result to true
				result = true;

				// Add move to forgotten moves
				forgottenMoves.push_back(currentMove);

				// Replace the move in position with a default move
				moves[i] = Move();

				// Stop looking
				break;
			}
		}

		// Return the result
		return result;
	}
};
