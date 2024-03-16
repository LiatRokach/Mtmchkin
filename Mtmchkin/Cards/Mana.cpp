//
// Created by maorgo on 23/06/2023.
//

#include "Mana.h"
#include "../Players/Healer.h"
#include "../utilities.h"
#define HEALTH_GAIN 10
#define NAME "Mana"
Mana::Mana(): Card(NAME), m_HealthGain(HEALTH_GAIN) {}

void Mana::getCardInfo(std::ostream &os) const{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

void Mana::applyEncounter(Player &player) const {
    const Healer* healerPlayer = dynamic_cast<const Healer*>(&player);
    if (healerPlayer != nullptr) {
        player.heal(m_HealthGain);
        printManaMessage(true);
    } else{
        printManaMessage(false);
    }
}