//
// Created by maorgo on 23/06/2023.
//

#ifndef EX4_WELL_H
#define EX4_WELL_H
#include "Card.h"

class Well: public Card {
    int m_healthLost;
public:
    Well();
    void getCardInfo(ostream& os) const override;
    void applyEncounter(Player& player) const override;
};


#endif //EX4_WELL_H
