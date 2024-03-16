//
// Created by maorgo on 23/06/2023.
//

#include "Witch.h"
#include "../utilities.h"
#define NAME "Witch"

Witch::Witch()
        : BattleCard(NAME,11, 2, 10){}

void Witch::getCardInfo(std::ostream &os) const{
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, false);
    printEndOfCardDetails(os);
}

void Witch::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    } else{
        player.weaken(1);
        player.damage(m_hpLossOnDefeat);
        printLossBattle(player.getName(),m_name);
    }
}