#include "StatusBar.h"
#include "../Config/GameConfig.h"
#include "../Core/Game.h"

StatusBar::StatusBar(Game* r_pGame, point r_point, int r_width, int r_height) : Drawable(r_pGame, r_point, r_width, r_height)
{}

void StatusBar::draw() const
{
	window* pWind = pGame->getWind();
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
	pWind->SetPen(WHITE, 3);
	pWind->DrawLine(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight - config.statusBarHeight);
}

void StatusBar::drawStatusTexts(int timer, string goal, int level, int animalCount) const
{
	draw();

	window* pWind = pGame->getWind();
	pWind->SetPen(WHITE, 50);
	pWind->SetFont(18, BOLD, BY_NAME, "Arial");

	int y = config.windHeight - (int)(0.65 * config.statusBarHeight);
	int sectionWidth = config.windWidth / 4;

	pWind->DrawString(20, y, "Timer: " + to_string(timer) + "s");
	pWind->DrawString(sectionWidth, y, "Goal: " + goal);
	pWind->DrawString(2 * sectionWidth, y, "Level: " + to_string(level));
	pWind->DrawString(3 * sectionWidth, y, "Animals: " + to_string(animalCount));
}
