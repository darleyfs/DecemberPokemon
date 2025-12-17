#pragma once
#include "Events.hpp"
#include "Trainer.hpp"

class Game {
	// Fields
	Trainer player;
	Trainer rival;

public:
	// Default constructor
	Game() {
		player = Trainer();
		rival = Trainer();
	}

	// Overloaded constructor
	Game(Trainer _player, Trainer _rival) {
		player = _player;
		rival = _rival;
	}

	void Start() {
		Events events;

		events.Introduction(player, rival);
		events.WakeUp(player.GetName());
		events.TouchGrass(player.GetName());
		events.SelectPokemon(player, rival);
	}
};