#pragma once

#include <random>
#include "Pokemon.hpp"

class Damage {
public:
    static int GetDamage(Pokemon attacker, Pokemon defender, Move move) {
        int damage = GetRandomDamage(
            GetModifiedDamage(
                GetBaseDamage(
                    attacker.GetLevel(),
                    attacker.GetAttack(),
                    defender.GetDefense(),
                    move
                ),
                attacker, defender, move
            ),
            defender
        );

        return damage;
    }

    static int GetBaseDamage(int level, int attack, int defense, Move move) {
        int baseDamage = 0;

        baseDamage = ((level * 2) / 5) + 2;
        baseDamage *= move.GetPower();
        baseDamage *= attack;
        baseDamage /= defense;
        baseDamage /= 50;

        baseDamage = (baseDamage > 997) ? 997 : baseDamage;

        baseDamage += 2;

        return baseDamage;
    }

    static int GetModifiedDamage(int baseDamage, Pokemon attacker, Pokemon defender, Move move) {
        int modifiedDamage = baseDamage;

        // STAB
        modifiedDamage += (attacker.GetType1() == move.GetType()) ? baseDamage / 2 : 0;

        int effectiveness = Move::CheckEffectiveness(defender.GetType1(), move);

        modifiedDamage = (modifiedDamage * effectiveness) / 10;

        return modifiedDamage;
    }

    static int GetRandomDamage(int modifiedDamage, Pokemon defender) {
        int rndDamage = modifiedDamage;

        if (rndDamage != 1) {
            std::random_device device;		// Object for creating random numbers

            std::mt19937 generator(device()); // Creating our seed

            std::uniform_int_distribution<> distribution(217, 256); // Define a range

            rndDamage *= distribution(generator);
            rndDamage /= 255;
            rndDamage = (defender.GetCurrentHp() < rndDamage) ? defender.GetCurrentHp() : rndDamage;
        }

        return rndDamage;
    }
};