#pragma once
#include "UI.hpp"
#include "Trainer.hpp"

class Events {
public:
	Events() {

	}

	void Introduction(Trainer& player, Trainer& rival) {
		UI ui;

		ui.DisplayMessage("Welcome to the Wonderful World of Pokemon!");
		ui.DisplayMessage("OAK", "Pokemon are like normal animals, but it's okay\n  to make them fight each other!");
		ui.DisplayMessage("OAK", "Even for just, like, petty grudges and stuff...");
		ui.DisplayMessage("OAK", "I'm a Pokemon professor that studies Pokemon.");
		ui.DisplayMessage("OAK", "What's your name?");

		std::string playerName = ui.PromptUser("What's your name?", "Name");
		player.SetName(playerName);

		ui.DisplayMessage("OAK", "It's nice to meet you, " + playerName + "!");

		ui.DisplayMessage("OAK", "There's only 2 kids in this town,\n  and my grandson is the neighborhood bully.");
		ui.DisplayMessage("OAK", "He's pretty much hazed you your entire life.\n  Which is weird because he has literally no friends.");
		ui.DisplayMessage("OAK", "Anyway, he's a huge disappointment, so I don't even\n  remember his name.");

		std::string rivalName = ui.PromptUser("What's your rival's dumb name?", "Dumb name");
		rival.SetName(rivalName);

		ui.DisplayMessage("OAK", "Yea, f&%* " + rivalName + ". All my homies hate " + rivalName + ".");
	}

	void WakeUp(std::string playerName) {
		UI ui;

		ui.DisplayMessage(playerName + " wakes up in their room...");

		std::vector<std::string> menuOptions = {
			"Check my computer",
			"Play video games",
			"Go back to sleep",
			"Go downstairs and head outside"
		};

		int choice = 0;

		do {
			choice = ui.PromptUserWithMenu("What do you want to do today?", menuOptions);

			switch (choice) {
			case 1:
				ui.DisplayMessage(playerName + " checks their computer, but the internet is out...");
				break;
			case 2:
				ui.DisplayMessage(playerName + " decides to play Minecraft all day.");
				break;
			case 3:
				ui.DisplayMessage(playerName + " decides to stay in bed. Today just ain't the day.");
				break;
			case 4:
				ui.DisplayMessage(playerName + " leaves their room, goes downstairs, and heads outside.");
				break;
			default:
				std::cout << "Invalid selection. Please try again!";
				break;
			}
		} while (choice != 4);
	}

	void TouchGrass(std::string playerName) {
		UI ui = UI();
		int choice = 0;

		ui.DisplayMessage(playerName + " leaves their house and wanders around town for a bit.");
		
		do {
			ui.DisplayMessage(playerName + " stops as a patch of tall grass at the town entrace.");

			choice = ui.PromptUserWithMenu("Touch grass?", { "Yes", "No" });

			switch (choice) {
			case 1:
				ui.DisplayMessage(playerName + " decides to risk it all, and touch grass.\n  How brave.");
				break;
			case 2:
				ui.DisplayMessage(playerName + " remembers their just cleaned their shoes.\n  That ain't worth.");
				break;
			default:
				std::cout << "Invalid menu selection. Please try again!";
			}		
		} while (choice != 1);

		// Professor OAK gets really upset
		ui.DisplayMessage("OAK", "WHAT THE F%*$ ARE YOU DOING?!");
		ui.DisplayMessage("OAK", "There are BUGS in that grass!");
		ui.DisplayMessage("OAK", "Bugs are like SUPER dangerous in this world!");
	}

	void SelectPokemon(Trainer& player, Trainer& rival) {
		UI ui;
		
		Pokemon charmander("Charmander", 5, 18, 18, 10, 9, 10, Type::FIRE, Type::NONE);
		Pokemon bulbasaur("Bulbasaur", 5, 19, 19, 11, 11, 13, Type::GRASS, Type::POISON);
		Pokemon squirtle("Squirtle", 5, 19, 19, 11, 13, 11, Type::WATER, Type::GRASS);
		Move scratch("Scratch", Type::NORMAL, 40, 1, 35, 35);
		Move tackle("Tackle", Type::NORMAL, 40, 1, 35, 35);

		charmander.LearnMove(scratch);
		bulbasaur.LearnMove(scratch);
		squirtle.LearnMove(tackle);

		ui.DisplayMessage(player.GetName() + " enters into Prof OAKs weird lab...");
		ui.DisplayMessage("OAK", "Welcome to my lab!");
		ui.DisplayMessage("OAK", "I've selected 3 invasive species for you to choose from!");

		std::vector<std::string> menuOptions = {
			charmander.GetName(),
			bulbasaur.GetName(),
			squirtle.GetName()
		};

		int choice = 0;

		// do {
			choice = ui.PromptUserWithMenu("Choose a Pokemon", menuOptions);

			switch (choice) {
			case 1:
				// Charmander;
				player.AddPokemonToTeam(charmander);
				break;
			case 2:
				// Bulbasaur;
				player.AddPokemonToTeam(bulbasaur);
				break;
			case 3:
				// Squirtle
				player.AddPokemonToTeam(squirtle);
				break;
			default:
				break;
			}

		// }while(choice < 1 || choice > menuOptions.size());
	
	}
};