#ifndef EX4_ninja_H
#define EX4_ninja_H

#include "Player.h"
#include "../utilities.h"

using namespace std;

class Ninja : public Player {

public:
    Ninja(string name);
    void addCoins(int coinsToAdd) override;
    ~Ninja() = default;
private:
    void getPlayerInfo(ostream& os) const override;
};
#endif //EX4_ninja_H