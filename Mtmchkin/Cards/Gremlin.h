//
// Created by maorgo on 23/06/2023.
//

#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H
#include "BattleCard.h"

class Gremlin: public BattleCard {
public:
    Gremlin();
    void applyEncounter(Player& player) const override;
    void getCardInfo(ostream& os) const override;
    ~Gremlin() = default;
};


#endif //EX4_GREMLIN_H
