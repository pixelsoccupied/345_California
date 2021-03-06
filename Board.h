#pragma once
#include "InfectionColors.h"
#include "CityGraph.h"
#include "City.h"
#include "Board.h"
#include "Player.h"
#include <vector>
#include <stack>
#include "PlayerCard.h"
#include "EventCard.h"

#define STARTING_INFECTION_CARD 9

class Board
{
public:

    Board(std::string saveFolder);
    ~Board();

    void save(std::string saveFolder);
    void generateGameContentAtStartOfGame();
    void addCity(City* city);
    City* getCity(int index);
    int getNumCities();
    //disease cure boolean
    //index value indicating disease according it's color...bool array if cured update bool value

    bool isCured[4];

    static void checkTurn();

    /*
    This is to change turn once the number of action is reach
    */
    bool playerTurnChange();
    /*
    This is to know the current turn of a player
    */
    Player& getCurrentTurnPlayer();
    Player& getPlayer(int index);
    int getNumberOfPlayers();

    ///change to currentPlayer attribute
    int currentTurnPlayer = 0;
    void drawCards(); // Draw 2 cards from the player deck
    std::vector<std::string> playerCardDeck;
    void tryStartGame();


    int getInfectionRate();
    void incremenetInfectionRate();

    int getActualInfectionRate();
    void setActualInfectionRate(int value);

    /*
    bank of all cities that can be infected
    the idea behind that is if the user decides to make
    his own city than we can make his own city's infectionCard
    and we have an discard pile
    */
    std::vector<int> infectionCityCards;
    std::vector<int> discardInfectionCard;
    void infectionCityCardsInitializor();
    void drawInfectionCard();

    bool isEditingMap();
    void submitMap();

    void changeCurrentPlayer();

private:
    CityGraph* _cities;
    std::vector<Player*> _players;
public:
    void set_players(const vector<Player *, std::allocator<Player *>> &_players);

private:
    std::vector<PlayerCard*> _playerWithdrawPile;

    int _infectionRate = 0;

    void loadBoardData(std::string boardFile);
    void saveBoardData(std::string boardFile);

    void loadNodes(std::string nodesFile);
    void saveNodes(std::string nodesFile);

    void loadPlayers(std::string playerFile);
    void savePlayers(std::string playerFile);

    void generatePlayerCards();

    Player* currentPlayer;
public:
    Player *getCurrentPlayer() const;

    void setCurrentPlayer(Player *currentPlayer);

    void setActionsAndRoles();
private:


    // Game properties.
    bool _editingMap = true;
    bool _startGame = false;
};

//this a free function to check turn