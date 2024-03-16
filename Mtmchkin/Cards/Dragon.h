//
// Created by maorgo on 23/06/2023.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H
#include "BattleCard.h"

class Dragon: public BattleCard {
public:
    Dragon();
    void applyEncounter(Player& player) const override;
    void getCardInfo(ostream& os) const override;
};


#endif //EX4_DRAGON_H
