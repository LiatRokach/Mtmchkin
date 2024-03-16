//
// Created by maorgo on 23/06/2023.
//

#include "Gremlin.h"
#include "../utilities.h"
#define NAME "Gremlin"

Gremlin::Gremlin()
        : BattleCard(NAME, 5, 2, 10){}

void Gremlin::getCardInfo(std::ostream &os) const{
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, false);
    printEndOfCardDetails(os);
}

void Gremlin::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),NAME);
    } else{
        player.damage(m_hpLossOnDefeat);
        printLossBattle(player.getName(),NAME);
    }
}