//
// Created by maorgo on 23/06/2023.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H
#include "Card.h"

class Barfight: public Card {
    int m_healthLost;
public:
    Barfight();
    void getCardInfo(ostream& os) const override;
    void applyEncounter(Player& player) const override;
};


#endif //EX4_BARFIGHT_H
