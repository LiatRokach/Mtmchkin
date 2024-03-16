//
// Created by maorgo on 23/06/2023.
//

#ifndef EX4_WITCH_H
#define EX4_WITCH_H
#include "BattleCard.h"

class Witch: public BattleCard {
public:
    Witch();
    void applyEncounter(Player& player) const override;
    void getCardInfo(ostream& os) const override;
};


#endif //EX4_WITCH_H
