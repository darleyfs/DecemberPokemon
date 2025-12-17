#pragma once
#include "Trainer.hpp"
#include "UI.hpp"

class Battle {
	Trainer player;
	Trainer trainer;
	UI ui;

public:
	Battle(Trainer& _player, Trainer _trainer) {
		player = _player;	// player ONLY as a reference
		trainer = _trainer; // another trainer
		UI ui = UI();		// UI object to use throughout the class
	}

	void Start() {		
		// Grab first Pokemon from both trainers
		Pokemon playerPokemon = GetFirstPokemonWithHealth(player);
		Pokemon rivalPokemon = GetFirstPokemonWithHealth(trainer);
		// TODO: Coin flip


		// Dialogue
		ui.DisplayMessage(trainer.GetName() + " approaches!");
		ui.DisplayMessage(player.GetName() + " calls " + playerPokemon.GetName() + "!");
		ui.DisplayMessage(trainer.GetName() + " calls " + trainer.GetName() + "!");


		// While Loop
		// TODO: Loop so long as either trainer has any pokemon with health

		// TODO: On player turn, display a menu of options
			// TODO: On FIGHT, display a menu of moves from the current pokemon
			// TODO: On USE MOVE, calculate damage
		// TODO: On trainer turn, 
			// TODO: select the first move, from the current pokemon
			// TODO: Calculate damage
		// TODO: Do some kind of check to see if the battle is over
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
};