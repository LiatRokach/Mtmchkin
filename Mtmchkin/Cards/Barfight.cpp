//
// Created by maorgo on 23/06/2023.
//

#include "Barfight.h"
#include "../Players/Warrior.h"
#include "../utilities.h"
#define NAME "Barfight"
#define FIGHT_DAMAGE 10
Barfight::Barfight(): Card(NAME), m_healthLost(FIGHT_DAMAGE) {}

void Barfight::getCardInfo(std::ostream &os) const{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

void Barfight::applyEncounter(Player &player) const {
    const Warrior* warriorPlayer = dynamic_cast<const Warrior*>(&player);
    if (warriorPlayer != NULL) {
        printBarfightMessage(true);
    } else{
        player.damage(m_healthLost);
        printBarfightMessage(false);
    }
}