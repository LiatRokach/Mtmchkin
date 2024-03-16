//
// Created by maorgo on 23/06/2023.
//

#include "Card.h"

Card::Card(string name): m_name(name) {}

ostream& operator<<(ostream& os, const Card& card) {
    card.getCardInfo(os);
    return os;
}