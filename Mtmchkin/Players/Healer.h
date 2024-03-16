#ifndef EX4_healer_H
#define EX4_healer_H

#include "Player.h"
#include "../utilities.h"

using namespace std;

class Healer : public Player {

public:
    Healer(string name);
    void heal(int healingPoints) override;
    ~Healer() = default;
private:
    void getPlayerInfo(ostream& os) const override;
};
#endif //EX4_healer_H