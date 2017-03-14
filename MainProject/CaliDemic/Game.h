#pragma once
#include "Board.h"
#include <string>

enum GameState : int
{
	MainMenu,
	InGame,
	Closed,
	GameState_Length
};

class Game
{
public:
	static void loadOrCreate(std::string savename);
	static void destroy();
	static void save();

	static void changeState(GameState state);
	static GameState getState();

	static Board* getGameBoard();
	
	//return the number of cubes left for each color
	void numOfCubeLeft();

	//total number of cubes which is 24
	static int numOfCube;
	/*
	attribute to number of cube for each color
	*/
	static int numOfYellowCube;
	static int numOfBlackCube;
	static int numOfBlueCube;
	static int numOfRedCube;

private:
	static Board* _gameBoard;
	static GameState _state;
	static std::string _saveFolder;

	static void checkDirectories();
	static void gameloop();
};

