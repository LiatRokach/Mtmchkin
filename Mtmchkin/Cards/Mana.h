//
// Created by maorgo on 23/06/2023.
//

#ifndef EX4_MANA_H
#define EX4_MANA_H
#include "Card.h"

class Mana: public Card {
    int m_HealthGain;
public:
    Mana();
    void getCardInfo(ostream& os) const override;
    void applyEncounter(Player& player) const override;
};


#endif //EX4_MANA_H
