//
// Created by maorgo on 23/06/2023.
//

#include "Dragon.h"
#include "../utilities.h"
#define NAME "Dragon"

Dragon::Dragon()
        : BattleCard(NAME,25, 1000, 0){}

void Dragon::getCardInfo(std::ostream &os) const{
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, true);
    printEndOfCardDetails(os);
}

void Dragon::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),NAME);
    } else{
        player.damage(player.getHealth());
        printLossBattle(player.getName(),NAME);
    }
}