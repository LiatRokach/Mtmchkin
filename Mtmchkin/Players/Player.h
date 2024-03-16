#ifndef EX4_player_H
#define EX4_player_H

#include <string>

using namespace std;

class Player {
private:
    static const int  DEFAULT_MAX_HP = 100;
    static const int  DEFAULT_FORCE = 5;
    static const int MAX_LEVEL = 10;
    int m_maxHP;

protected:
    int m_force;
    int m_level = 1;
    int m_coins = 10;
    int m_hp;
    string m_name;

public:
    Player(string name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);
    /*
     * Gets the health that a player has.
     *
     * @return The health that a player has.
     */
    int getHealth();
    /*
     * Gets the maximum level that a player can reach.
     *
     * @return The maximum level that a player can reach.
     */
    static int getMaxLevel();
    /*
     *
     * This function prints info of the player such as name, level, hp, force, and coin amount.
     * @return
     *     void
     */
    virtual void getPlayerInfo(ostream& os) const = 0;
    /*
     *
     * As long as the player's level is below maximum, this function raises it by 1.
     * @return
     *     void
     */
    void levelUp();
    /*
     * This function returns the game status of the player.
     *
     * @return The current game status of the player character.
     */
    bool isInGame();
    /*
     * This function returns of the player won.
     *
     * @return The current game status of the player character.
     */
    bool didPlayerWin();
    /*
     * This function returns if the player lost.
     *
     * @return The current game status of the player character.
     */
    bool didPlayerLose();
    /*
     * This function returns the player character's name.
     *
     * @return The current name of the player character.
     */
    string getName();
    /*
     * This function returns the player character's current level.
     *
     * @return The current level of the player character.
     */
    int getLevel();
    /*
     * This function returns the current coin amount of the player character.
     *
	 * @return The current coin amount of the player character.
	 */
    int getCoins();
    /*
     * @param toDecrease The amount of force to take from the player.
     *              Must be a positive value.
     *
     * decreases force by toDecrease amount of points for the player character.
     *
     * @return
     *     void
     */
    void weaken(int toDecrease);
    /*
     * @param toAdd The amount of force to add to the player.
     *              Must be a positive value.
     *
     * increases force by toAdd amount of points for the player character.
     *
     * @return
     *     void
     */
    void buff(int toAdd);
    /*
     * @param healingPoints The amount of healing points to add to the player's health.
     *                      Must be a positive integer.
     *
     * This function increases the player's health.
     * The player's health is capped at the maximum value if it exceeds their maximum health..
     * @return
     *     void
     */
    virtual void heal(int healingPoints);
    /*
     * @param pointsToRemove The amount of health points to remove from the player's health.
     *                       Must be a positive integer.
     *
     * Removes the specified amount of health points from the player character.
     * If the player's health goes under 0 it resets to 0.
     * @return
     *     void
     */
    void damage(int pointsToRemove);
    /*
     * This function determines whether the player is knocked out if their health is 0.
     *
     * @return True if the player character is knocked out, false otherwise.
     */
    bool isKnockedOut();
    /*
     * @param coinsToAdd The amount of coins to add to the player's inventory.
     *                   Must be a positive integer.
     *
     * Adds the specified amount of coins to the player.
     *
     * @return
     *     void
     */
    virtual void addCoins(int coinsToAdd);
    /*
     * Removes the specified amount of coins from the player.
     * If the player does not have enough coins to pay, the function returns false and does not modify the player.
     *
     * @param amountToPay The amount of coins to remove from the player.
     *                     Must be a positive integer.
     * @return True if the player had enough coins to pay, false otherwise.
     */
    bool pay(int amountToPay);
    /*
     * This function returns the force of the player character.
     *
     * @return The force of the player character.
     */
    virtual int getAttackStrength();

    friend ostream& operator<<(ostream& os, const Player& currentPlayer);
    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    virtual ~Player() = default;
    Player(const Player& other) = default;
    Player& operator=(const Player& other) = default;
};
#endif //EX4_player_H