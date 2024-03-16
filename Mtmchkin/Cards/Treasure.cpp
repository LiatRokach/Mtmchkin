//
// Created by maorgo on 23/06/2023.
//

#include "Treasure.h"
#define COINS 10
#include "../utilities.h"
#define NAME "Treasure"

Treasure::Treasure(): Card(NAME), m_Loot(COINS) {}

void Treasure::getCardInfo(std::ostream &os) const{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

void Treasure::applyEncounter(Player &player) const {
    player.addCoins(m_Loot);
    printTreasureMessage();
}