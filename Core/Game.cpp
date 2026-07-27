#include "Game.h"
#include "../Config/GameConfig.h"

Game::Game()
{
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	createToolbar();
	createBudgetbar();
	createStatusBar();

	drawBudgetBarTexts();
	drawStatusBar();
	drawWarehouse();
}

Game::~Game()
{
}

clicktype Game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);

}

string Game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)
			return "";
		if (Key == 13)
			return Label;
		if (Key == 8)
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

window* Game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}

void Game::createToolbar()
{
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new Toolbar(this, toolbarUpperleft, 0, config.toolBarHeight);
	gameToolbar->draw();
}

void Game::createBudgetbar()
{
	point budgetbarUpperleft;
	budgetbarUpperleft.x = 0;
	budgetbarUpperleft.y = config.toolBarHeight;

	gameBudgetbar = new Budgetbar(this, budgetbarUpperleft, 0, config.toolBarHeight);
	gameBudgetbar->draw();
}

void Game::createStatusBar()
{
	point statusBarUpperleft;
	statusBarUpperleft.x = 0;
	statusBarUpperleft.y = config.windHeight - config.statusBarHeight;

	gameStatusBar = new StatusBar(this, statusBarUpperleft, config.windWidth, config.statusBarHeight);
	gameStatusBar->draw();
}


void Game::clearBudget() const
{
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(ANIMAL_COUNT * config.iconWidth + 10, config.toolBarHeight, config.windWidth, 2 * config.toolBarHeight);
}

void Game::printBudget(string msg) const
{
	clearBudget();

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.windWidth - 200, config.toolBarHeight + 10, msg);

}

void Game::clearStatusBar() const
{
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

void Game::drawStatusBar() const
{
	gameStatusBar->drawStatusTexts(timer, goal, level, animalCount);
}

void Game::drawBudgetBarTexts() const
{
	clearBudget();

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");

	int textStartX = ANIMAL_COUNT * config.iconWidth + 30;
	int y = config.toolBarHeight + 15;

	pWind->DrawString(textStartX, y, "Budget: $" + to_string(budget));
	pWind->DrawString(textStartX + 280, y, "Animals Bought: " + to_string(animalsBought));
	pWind->DrawString(textStartX + 580, y, "Water Bought: " + to_string(waterBought));
}

void Game::drawWarehouse() const
{
	window* pWind = getWind();

	int warehouseX = config.windWidth - 220;
	int warehouseY = config.windHeight - config.statusBarHeight - 160;
	int warehouseW = 180;
	int warehouseH = 120;

	// Warehouse body
	pWind->SetBrush(SADDLEBROWN);
	pWind->SetPen(BLACK, 2);
	pWind->DrawRectangle(warehouseX, warehouseY, warehouseX + warehouseW, warehouseY + warehouseH);

	// Roof (triangle)
	int roofPeakX = warehouseX + warehouseW / 2;
	int roofPeakY = warehouseY - 50;
	int xArr[3] = { warehouseX - 10, roofPeakX, warehouseX + warehouseW + 10 };
	int yArr[3] = { warehouseY, roofPeakY, warehouseY };
	pWind->SetBrush(MAROON);
	pWind->SetPen(BLACK, 2);
	pWind->DrawPolygon(xArr, yArr, 3);

	// Door
	int doorW = 40;
	int doorH = 60;
	int doorX = warehouseX + (warehouseW - doorW) / 2;
	int doorY = warehouseY + warehouseH - doorH;
	pWind->SetBrush(BROWN);
	pWind->SetPen(BLACK, 2);
	pWind->DrawRectangle(doorX, doorY, doorX + doorW, doorY + doorH);

	// Windows
	int winW = 30;
	int winH = 25;
	pWind->SetBrush(LIGHTBLUE);
	pWind->SetPen(BLACK, 1);
	pWind->DrawRectangle(warehouseX + 15, warehouseY + 20, warehouseX + 15 + winW, warehouseY + 20 + winH);
	pWind->DrawRectangle(warehouseX + warehouseW - 15 - winW, warehouseY + 20, warehouseX + warehouseW - 15, warehouseY + 20 + winH);

	// Label
	pWind->SetPen(WHITE, 50);
	pWind->SetFont(16, BOLD, BY_NAME, "Arial");
	pWind->DrawString(warehouseX + 40, warehouseY + warehouseH + 5, "Warehouse");
}

void Game::printMessage(string msg) const
{
	clearStatusBar();

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);

}

window* Game::getWind() const
{
	return pWind;
}

void Game::go()
{
	int x, y;
	bool isExit = false;

	pWind->ChangeTitle("- - - - - - - - - - Farm Frenzy (CIE101-project) - - - - - - - - - -");

	drawStatusBar();
	drawBudgetBarTexts();
	drawWarehouse();

	do
	{
		getMouseClick(x, y);

		if (y >= 0 && y < config.toolBarHeight)
		{
			isExit = gameToolbar->handleClick(x, y);
		}
		else if (y >= config.toolBarHeight && y < 2 * config.toolBarHeight)
		{
			isExit = gameBudgetbar->handleClick(x, y);
			drawStatusBar();
			drawBudgetBarTexts();
		}

	} while (!isExit);
}
