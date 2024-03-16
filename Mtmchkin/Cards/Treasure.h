//
// Created by maorgo on 23/06/2023.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H
#include "Card.h"

class Treasure: public Card {
    int m_Loot;
public:
    Treasure();
    void getCardInfo(ostream& os) const override;
    void applyEncounter(Player& player) const override;
};


#endif //EX4_TREASURE_H
