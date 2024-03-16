#include "Ninja.h"
using namespace std;
#define NAME "Ninja"
Ninja::Ninja(string name) : Player(name){}

void Ninja :: addCoins(int coinsToAdd) {
    Player :: addCoins(coinsToAdd * 2);
}

void Ninja::getPlayerInfo(ostream& os) const {
    printPlayerDetails(os, m_name.c_str(), NAME, m_level, m_force, m_hp, m_coins);
}