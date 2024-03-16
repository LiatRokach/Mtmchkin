#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <list>
#include <vector>
#include <memory>
#include "Cards/Card.h"
#include "Players/Player.h"

class Mtmchkin{
    int cardAmount = 0;
    int playerAmount = 0;
    int roundNumber = 0;
    std::list<std::unique_ptr<Card>> m_cardsList;
    std::vector<std::unique_ptr<Player>> m_playerList;
    std::vector<int> m_winners;
    std::vector<int> m_losers;
    bool isInWinnersOrLosers(int playerIndex) const;
public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
};



#endif /* MTMCHKIN_H_ */
