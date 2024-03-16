//
// Created by maorgo on 23/06/2023.
//

#include "Well.h"
#include "../Players/Ninja.h"
#include "../utilities.h"
#define DAMAGE 10
#define NAME "Well"

Well::Well(): Card(NAME), m_healthLost(DAMAGE) {}

void Well::getCardInfo(std::ostream &os) const{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

void Well::applyEncounter(Player &player) const {
    const Ninja* ninjaPlayer = dynamic_cast<const Ninja*>(&player);
    if (ninjaPlayer != nullptr) {
        printWellMessage(true);
    } else{
        player.damage(m_healthLost);
        printWellMessage(false);
    }
}