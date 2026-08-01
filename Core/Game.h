#pragma once
#include "../CMUgraphicsLib/CMUgraphics.h"
#include "../UI/Toolbar.h"
#include "../UI/BudgetBar.h"
#include "../UI/StatusBar.h"
#include "Drawable.h"
#include <string>
using std::string;

class Game
{
private:
	window* pWind;	//Pointer to the CMU graphics window
	Toolbar* gameToolbar;
	Budgetbar* gameBudgetbar;
	StatusBar* gameStatusBar;

public:
	int budget = 2000;
    bool isPaused = false;
	int animalsBought = 0;
	int waterBought = 0;
	int timer = 0;
	int level = 1;
	int animalCount = 0;
	string goal = "Collect $5000";


	void drawFieldBackground() const;
	Game();
	~Game();

	clicktype getMouseClick(int& x, int& y) const;
	string getSrting() const;

	window* CreateWind(int, int, int, int) const;
    void AddAnimalRandomly();
	void createToolbar();
	void createBudgetbar();
	void createStatusBar();
	void clearBudget() const;
	void printBudget(string msg) const;
	void clearStatusBar() const;
	void drawStatusBar() const;
	void drawBudgetBarTexts() const;
	void drawWarehouse() const;

	void printMessage(string msg) const;

	void go() const;
    void pauseGame();
	void resumeGame();
	void saveGame() const;
	void loadGame();
	void restartGame();
window* getWind() const;
};
