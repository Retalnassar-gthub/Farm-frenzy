#include "Animal.h"
#include "../Config/GameConfig.h"
#include "../Core/Game.h"
#include <iostream>
using namespace std;

Animal::Animal(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : Drawable(r_pGame, r_point, r_width, r_height)
{
	image_path = img_path;
	curr_pos = r_point;
	curr_vel.x = 1;
	curr_vel.y = 1;
}

void Animal::draw() const
{
	//draw image of this object
	window* pWind = pGame->getWind();
	pWind->DrawImage(image_path, RefPoint.x, RefPoint.y, width, height);
}

Chick::Chick(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : Animal(r_pGame, r_point, r_width, r_height, img_path)
{}

void Chick::moveStep()
{
	//TO DO: add code for cleanup and game exit here
	cout << "Icon Chick Clicked" << endl;
}

Cow::Cow(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : Animal(r_pGame, r_point, r_width, r_height, img_path)
{
	isSick = false;
}

void Cow::moveStep()
{
	// منطق حركة البقرة
}

void Cow::draw() const
{
	window* pWind = pGame->getWind();

	if (isSick)
	{
		pWind->DrawImage("images\\cow_sick.jpg", curr_pos.x, curr_pos.y, 60, 60);
	}
	else
	{
		pWind->DrawImage("images\\cow_normal.jpg", curr_pos.x, curr_pos.y, 60, 60);
	}
}

void Cow::setSick(bool sick)
{
	isSick = sick;
}

bool Cow::getSick() const
{
	return isSick;
}

Wolf::Wolf(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : Animal(r_pGame, r_point, r_width, r_height, img_path)
{
}

void Wolf::moveStep()
{
	// منطق حركة الذئب
}

void Wolf::draw() const
{
	window* pWind = pGame->getWind();
	pWind->DrawImage(image_path, curr_pos.x, curr_pos.y, 60, 60);
}
