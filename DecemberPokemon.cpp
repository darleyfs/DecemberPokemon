#include "Events.hpp"
#include "Trainer.hpp"

int main()
{
	Events events;

	Trainer player = events.Introduction();
	events.WakeUp(player.GetName());
	events.TouchGrass(player.GetName());
	events.SelectPokemon(player);
}

