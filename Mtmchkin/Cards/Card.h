//
// Created by maorgo on 23/06/2023.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H
#include "../Players/Player.h"
#include <string>
using namespace std;

class Card {
protected:
    string m_name;
public:
    Card(string name);
    virtual void applyEncounter(Player& player) const = 0;
    friend ostream& operator<<(ostream& os, const Card& card);
    virtual void getCardInfo(ostream& os) const = 0;
    virtual ~Card() {}
};


#endif //EX4_CARD_H
