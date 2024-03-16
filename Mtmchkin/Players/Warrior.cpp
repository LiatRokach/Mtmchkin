#include "Warrior.h"
#define NAME "Warrior"
Warrior::Warrior(string name) : Player(name){}

int Warrior:: getAttackStrength() {
    return ((m_force * 2) + m_level);
}

void Warrior::getPlayerInfo(ostream& os) const {
    printPlayerDetails(os, m_name.c_str(), NAME, m_level, m_force, m_hp, m_coins);
}