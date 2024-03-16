//
// Created by maorgo on 23/06/2023.
//

#include "Merchant.h"
#include "../utilities.h"
#define HEAL_AMOUNT 1
#define HEAL_PRICE 5
#define BUFF_AMOUNT 1
#define BUFF_PRICE 10
#define NAME "Merchant"

Merchant::Merchant(): Card(NAME), m_healthCost(HEAL_PRICE)
                        , m_healthGain(HEAL_AMOUNT), m_forceCost(BUFF_PRICE), m_forceGain(BUFF_AMOUNT){}

void Merchant::getCardInfo(std::ostream &os) const{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

void Merchant::applyEncounter(Player &player) const {
    std::string purchase;
    int result = -1;
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName(),player.getCoins());
    while(result != 0 && result != 1 && result != 2) {
        std::getline(std::cin, purchase);
        try {
            result = std::stoi(purchase);
        } catch (const std::invalid_argument &e) {
            printInvalidInput();
            continue;
        }
        if(result != 0 && result != 1 && result != 2)
            printInvalidInput();
    }
    switch (result) {
        case 0:
            printMerchantSummary(cout, player.getName(), 0, 0);
            break;
        case 1:
            player.pay(m_healthCost);
            player.heal(m_healthGain);
            printMerchantSummary(cout, player.getName(), 1, m_healthCost);
            break;
        case 2:
            player.pay(m_forceCost);
            player.buff(m_forceGain);
            printMerchantSummary(cout, player.getName(), 2, m_forceCost);
            break;
    }
}