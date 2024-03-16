#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "Cards/Card.h"
#include "Exception.h"
#include "Mtmchkin.h"
#include "utilities.h"
#include "Cards/Mana.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Barfight.h"
#include "Cards/Treasure.h"
#include "Cards/Dragon.h"
#include "Cards/Witch.h"
#include "Cards/Gremlin.h"
#include "Players/Healer.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"

#define MIN_CARDS 5
#define MIN_PLAYERS 2
#define MAX_PLAYERS 6
// TODO fix throw
using namespace std;

bool playerNameIsValid(string playerName){
    if (playerName.length() > 15){
        return false;
    }
    for (char letter : playerName){
        if (!isalpha(letter)){
            return false;
        }
    }
    return true;
}

bool PlayerTypeIsValid(string playerType){
    if (playerType == "Warrior" || playerType == "Healer" || playerType == "Ninja"){
        return true;
    }
    return false;
}

void getPlayerInfo(vector<string> &playerInfo, string line, string delimiter){
    int end = line.find(delimiter);
    while (end != -1){
        playerInfo.push_back(line.substr(0, end));
        line.erase(line.begin(), line.begin()+ end + 1);
        end = line.find(delimiter);
    }
    playerInfo.push_back(line);
}
//TODO make it shorter
Mtmchkin :: Mtmchkin(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        throw DeckFileNotFound();
    }
	string line;
    printStartGameMessage();
	if (file.is_open()) {
		while (getline(file, line)) {
            //TODO: refactor
            if(line == "Mana"){
                m_cardsList.push_back(unique_ptr<Card>(new Mana()));
            } else if (line == "Merchant"){
                m_cardsList.push_back(unique_ptr<Card>(new Merchant()));
            } else if (line == "Well"){
                m_cardsList.push_back(unique_ptr<Card>(new Well()));
            } else if (line == "Barfight"){
                m_cardsList.push_back(unique_ptr<Card>(new Barfight()));
            } else if (line == "Treasure"){
                m_cardsList.push_back(unique_ptr<Card>(new Treasure()));
            } else if (line == "Dragon"){
                m_cardsList.push_back(unique_ptr<Card>(new Dragon()));
            } else if (line == "Witch"){
                m_cardsList.push_back(unique_ptr<Card>(new Witch()));
            } else if (line == "Gremlin"){
                m_cardsList.push_back(unique_ptr<Card>(new Gremlin()));
            } else{
                throw DeckFileFormatError(cardAmount + 1);
            }
            cardAmount++;
		}
        if (cardAmount < MIN_CARDS){
            throw DeckFileInvalidSize();
        }
        file.close();
	} else {
        cout << "Unable to open file" << endl;
    }

	printEnterTeamSizeMessage();
    while (true){
        std::string amountOfPlayers;
        int result;
        std::getline(std::cin, amountOfPlayers);
        try {
            result = std::stoi(amountOfPlayers);
        } catch (const std::invalid_argument &e) {
            printInvalidInput();
            continue;
        }
        if(result < MIN_PLAYERS || result > MAX_PLAYERS){
            printInvalidTeamSize();
            continue;
        } else {
            playerAmount = result;
            break;
        }
    }
    int counter = playerAmount;
    bool errorState = false;
    while (counter > 0){
        if (!errorState){
            printInsertPlayerMessage();
        }
        errorState = false;
        vector<string> playerInfo;
        string playerInput;

        getline(std::cin, playerInput);
        getPlayerInfo(playerInfo, playerInput, " ");
        if(playerInfo.size() != 2){
            errorState = true;
            printInvalidInput();
            continue;
        } else if(!playerNameIsValid(playerInfo[0])){
            errorState = true;
            printInvalidName();
            continue;
        } else if(!PlayerTypeIsValid(playerInfo[1])){
            errorState = true;
            printInvalidClass();
            continue;
        }

        if(playerInfo[1] == "Ninja"){
            m_playerList.push_back(unique_ptr<Player>(new Ninja(playerInfo[0])));
        } else if (playerInfo[1] == "Healer"){
            m_playerList.push_back(unique_ptr<Player>(new Healer(playerInfo[0])));
        } else {
            m_playerList.push_back(unique_ptr<Player>(new Warrior(playerInfo[0])));
        }
        counter--;
    }
}

void Mtmchkin::playRound(){
    roundNumber++;
    printRoundStartMessage(roundNumber);
    for(int i = 0; i< playerAmount; i++){
        if(m_playerList[i]->isInGame()){
            printTurnStartMessage(m_playerList[i]->getName());
            m_cardsList.front()->applyEncounter(*m_playerList[i]);
            if (m_playerList[i]->didPlayerWin()){
                m_winners.push_back(i);
            } else if (m_playerList[i]->didPlayerLose()){
                m_losers.push_back(i);
            }
            auto deckCard = std::move(m_cardsList.front());
            m_cardsList.pop_front();
            m_cardsList.push_back(std::move(deckCard));
        }
        if(isGameOver()){
            printGameEndMessage();
            return;
        }
    }

}

int Mtmchkin::getNumberOfRounds() const {
    return roundNumber;
}

bool Mtmchkin::isGameOver() const {
    int counter = 0;
    for(int i = 0; i< playerAmount; i++){
        if(m_playerList[i]->isInGame()){
            counter++;
        }
    }
    if(counter == 0){
        return true;
    }
    return false;
}

bool Mtmchkin::isInWinnersOrLosers(int playerIndex) const {
    int winnersSize = static_cast<int>(m_winners.size());
    int losersSize = static_cast<int>(m_losers.size());
    for (int i = 0; i < winnersSize; ++i) {
        if(playerIndex == m_winners[i]){
            return true;
        }
    }

    for (int i = 0; i < losersSize; ++i) {
        if(playerIndex == m_losers[i]){
            return true;
        }
    }
    return false;
}

void Mtmchkin::printLeaderBoard() const {
    int winnersSize = static_cast<int>(m_winners.size());
    int losersSize = static_cast<int>(m_losers.size());
    int ranking = 1;
    printLeaderBoardStartMessage();
    for(int i = 0; i < winnersSize; i++){
        printPlayerLeaderBoard(ranking, *m_playerList[m_winners[i]]);
        ranking++;
    }
    for(int i = 0; i < playerAmount; i++){
        if(isInWinnersOrLosers(i)){
            continue;
        }
        printPlayerLeaderBoard(ranking, *m_playerList[i]);
        ranking++;
    }
    for(int i = losersSize-1; i >= 0; i--){
        printPlayerLeaderBoard(ranking, *m_playerList[m_losers[i]]);
        ranking++;
    }
}