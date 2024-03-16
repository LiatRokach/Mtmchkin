#ifndef EX4_warrior_H
#define EX4_warrior_H

#include "Player.h"
#include "../utilities.h"

using namespace std;

class Warrior : public Player {

public:
    Warrior(string name);
    int getAttackStrength() override;
    ~Warrior() = default;
private:
    void getPlayerInfo(ostream& os) const override;
};
#endif //EX4_warrior_H
