#pragma once
#include <vector>
#include "Pokemon.hpp"
#include "UI.hpp"

class Trainer {
	std::string name;
	std::vector<Pokemon> team;

public:
	Trainer() {
		name = "";
		team = std::vector<Pokemon>(6);
	}

	Trainer(std::string _name, std::vector<Pokemon> _team) {
		name = _name;
		team = _team;
	}

	std::string GetName() {
		return name;
	}

	std::vector<Pokemon> GetTeam() {
		return team;
	}

	void SetName(std::string _name) {
		if (_name != "") {
			name = _name;
		}
	}
	
	Pokemon GetPokemonByPosition(int position) {
		return team[position];
	}

	bool AddPokemonToTeam(Pokemon pokemon) {
		// Initialize placeholder variables
		UI ui;
		bool result = false;

		// Iterate through the team vector
		for (int i = 0; i < team.size(); i++) {
			// Reference of pokemon at current position
			Pokemon currentPokemon = team[i];

			// If that pokemon has a type 1 of none
			if (currentPokemon.GetType1() == Type::NONE) {
				// Place given pokemon at that position
				team[i] = pokemon;

				// Set result to true
				result = true;

				ui.DisplayMessage(pokemon.GetName() + " was added to " + name + "'s team!");

				// Stop looking
				break;
			}
		}

		// return the result
		return result;
	}

	void RemovePokemonAtPosition(int position) {
		team[position] = Pokemon();
	}

	bool RemovePokemonByName(std::string name) {
		// Initialize the result
		bool result = false;

		// Iterate through the team vector
		for (int i = 0; i < team.size(); i++) {
			// Reference of pokemon at current position
			Pokemon currentPokemon = team[i];

			// If the current pokemon's name match the given name
			if (currentPokemon.GetName() == name) {
				// Set that pokemon to an empty pokemon
				team[i] = Pokemon();

				// Set result
				result = true;

				// Stop looking
				break;
			}
		}

		// Return the result
		return result;
	}
};
