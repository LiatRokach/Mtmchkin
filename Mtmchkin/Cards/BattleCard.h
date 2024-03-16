//
// Created by maorgo on 23/06/2023.
//

#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H
#include "Card.h"
#include <string>
class BattleCard: public Card {
protected:
    int m_force;
    int m_loot;
    int m_hpLossOnDefeat;
public:
    BattleCard(string name, int force, int loot, int hpLossOnDefeat )
            : Card(name), m_force(force), m_loot(loot), m_hpLossOnDefeat(hpLossOnDefeat)
    {}
};


#endif //EX4_BATTLECARD_H
