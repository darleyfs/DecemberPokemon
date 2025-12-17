#pragma once
#include <random>
#include "Trainer.hpp"
#include "UI.hpp"

class Battle {
	Trainer player;
	Trainer trainer;
	UI ui;

	enum Result {
		WIN,
		LOSE,
		CONTINUE
	};

public:
	Battle(Trainer& _player, Trainer _trainer) {
		player = _player;	// player ONLY as a reference
		trainer = _trainer; // another trainer
		UI ui = UI();		// UI object to use throughout the class
	}

	void Start() {		
		// Grab first Pokemon from both trainers
		// TODO: Make these references BACK TO the trainer team
		Pokemon playerPokemon = GetFirstPokemonWithHealth(player);
		Pokemon rivalPokemon = GetFirstPokemonWithHealth(trainer);
		
		// TODO: Coin flip
		int turn = CoinFlip();

		// Dialogue
		ui.DisplayMessage(trainer.GetName() + " approaches!");
		ui.DisplayMessage(player.GetName() + " calls " + playerPokemon.GetName() + "!");
		ui.DisplayMessage(trainer.GetName() + " calls " + trainer.GetName() + "!");

		do {
			// TODO: Loop so long as either trainer has any pokemon with health

			if (turn == 1) {
				// TODO: On player turn, display a menu of options
					// TODO: On FIGHT, display a menu of moves from the current pokemon
					// TODO: On USE MOVE, calculate damage

				turn = 2;
			} else {
				// TODO: On trainer turn, 
					// TODO: select the first move, from the current pokemon
					// TODO: Calculate damage
				turn = 1;
			}

		// Check to see if the battle is over
		} while (CheckWin() == Result::CONTINUE);

	}

	Pokemon GetFirstPokemonWithHealth(Trainer trainer) {
		// Initialize placeholder result
		Pokemon pokemon = Pokemon();

		// Reference the parameter trainer's team
		std::vector<Pokemon> trainerTeam = trainer.GetTeam();

		// Iterate through the team
		for (int i = 0; i < trainerTeam.size(); i++) {
			// Reference current iterator's Pokemon
			Pokemon currentPokemon = trainerTeam[i];

			// Check to see if it has help
			if (currentPokemon.GetCurrentHp() > 0) {
				// If it does, set the pokemon
				pokemon = currentPokemon;

				// Stop looking
				break;
			}
		}

		// Return Pokemon
		return pokemon;
	}

	Result CheckWin() {
		Result result = Result::CONTINUE;
		Pokemon playerPokemon = GetFirstPokemonWithHealth(player);
		Pokemon trainerPokemon = GetFirstPokemonWithHealth(trainer);

		if (playerPokemon.GetType1() == Type::NONE) {
			result = Result::LOSE;
		}
		else if (trainerPokemon.GetType1() == Type::NONE) {
			result = Result::WIN;
		}

		return result;
	}

	int CoinFlip() {
		std::random_device device;		// Object for creating random numbers

		std::mt19937 generator(device()); // Creating our seed

		std::uniform_int_distribution<> distribution(1, 2); // Define a range

		return distribution(generator);
	}
};