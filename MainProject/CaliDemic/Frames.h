#pragma once
#include "UIFrame.h"
#include "PlayerActions.h"

// The frame that holds all UI elements whilst in game.
class GameFrame : public UIFrame
{
public:
	GameFrame();
	void onMouseDown(std::string button, int x, int y);
	void onMouseMove(int x, int y);
	void onKeyDown(std::string key);
	void onKeyUp(std::string key);

private:
#ifdef ADMIN_EDITOR
	bool _connectNode = false;
	bool _moveMode = false;
	bool _teleportNode = false;
	bool _addNode = false;
#endif
};

// The frame that holds all player-action buttons in game.
struct PlayerActionsFrame : public UIFrame
{
	PlayerActionsFrame();
	void onMouseDown(std::string button, int x, int y);
};


// The frame that holds all UI elements for the main menu.
struct MainMenuFrame : public UIFrame
{
	MainMenuFrame();
};


// The frame that handles the rendering of player cards.
struct PlayerCardsFrame : public UIFrame
{
	PlayerCardsFrame();
	void draw();
	void onMouseDown(std::string button, int x, int y);

	void show(PlayerActions action);
	void resetShow();

private:
	PlayerActions _currentAction;
	std::vector<int> _actionVector;
};