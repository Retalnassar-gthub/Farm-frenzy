#pragma once
#include "../Core/Drawable.h"

class StatusBar : public Drawable
{
public:
	StatusBar(Game* r_pGame, point r_point, int r_width, int r_height);
	void draw() const override;
	void drawStatusTexts(int timer, string goal, int level, int animalCount) const;
};
