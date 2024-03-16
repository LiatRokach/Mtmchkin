//
// Created by maorgo on 23/06/2023.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H
#include "Card.h"

class Merchant: public Card {
    int m_healthCost;
    int m_healthGain;
    int m_forceCost;
    int m_forceGain;
public:
    Merchant();

    void applyEncounter(Player& player) const override;
    void getCardInfo(ostream& os) const override;
};


#endif //EX4_MERCHANT_H
