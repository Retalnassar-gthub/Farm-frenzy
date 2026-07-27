#pragma once
#include "../Core/Drawable.h"

class ToolbarIcon :public Drawable
{
private:
	string image_path;
public:
	ToolbarIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path);
	virtual void draw() const override;
	virtual void onClick() = 0;
};

class ExitIcon : public ToolbarIcon
{
public:
	ExitIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path);
	virtual void onClick();
};

enum ICONS
{
	ICON_EXIT,

	ICON_COUNT
};

class Toolbar : public Drawable
{
private:
	ToolbarIcon** iconsList;
	string iconsImages[ICON_COUNT];

public:
	Toolbar(Game* r_pGame, point r_point, int r_width, int r_height);
	~Toolbar();
	void draw() const override;
	bool handleClick(int x, int y);
};
