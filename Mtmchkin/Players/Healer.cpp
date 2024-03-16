#include "Healer.h"
#define NAME "Healer"
Healer::Healer(string name) : Player(name){}

void Healer::heal(int healingPoints) {
    Player::heal(healingPoints * 2);
}

void Healer::getPlayerInfo(ostream& os) const {
    printPlayerDetails(os, m_name.c_str(), NAME, m_level, m_force, m_hp, m_coins);
}