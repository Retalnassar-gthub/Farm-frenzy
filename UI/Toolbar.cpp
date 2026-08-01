#include "Toolbar.h"
#include "../Config/GameConfig.h"
#include "../Core/Game.h"
#undef LoadIcon

ToolbarIcon::ToolbarIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : Drawable(r_pGame, r_point, r_width, r_height)
{
    image_path = img_path;
}

void ToolbarIcon::draw() const
{
    window* pWind = pGame->getWind();
    pWind->DrawImage(image_path, RefPoint.x, RefPoint.y, width, height);
}

RestartIcon::RestartIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{
}

void RestartIcon::onClick()
{
    pGame->restartGame();
}

ExitIcon::ExitIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{
}

void ExitIcon::onClick()
{
    //TO DO: add code for cleanup and game exit here
}

PauseIcon::PauseIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{
}

void PauseIcon::onClick()
{
    pGame->pauseGame();
}

ResumeIcon::ResumeIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{
}

void ResumeIcon::onClick()
{
    pGame->resumeGame();
}

SaveIcon::SaveIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{
}

void SaveIcon::onClick()
{
    pGame->saveGame();
}

LoadIcon::LoadIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{
}

void LoadIcon::onClick()
{
    pGame->loadGame();
}

Toolbar::Toolbar(Game* r_pGame, point r_point, int r_width, int r_height) : Drawable(r_pGame, r_point, r_width, r_height)
{
    iconsImages[ICON_RESTART] = "images\\RESTART.jpg";
    iconsImages[ICON_EXIT] = "images\\EXIT.jpg";
    iconsImages[ICON_PAUSE] = "images\\PAUSE.jpg";
    iconsImages[ICON_RESUME] = "images\\RESUME.jpg";
    iconsImages[ICON_SAVE] = "images\\SAVE.jpg";
    iconsImages[ICON_LOAD] = "images\\LOAD.jpg";

    point p;
    p.x = 0;
    p.y = 0;

    iconsList = new ToolbarIcon * [ICON_COUNT];

    iconsList[ICON_RESTART] = new RestartIcon(pGame, p, config.iconWidth, config.toolBarHeight, iconsImages[ICON_RESTART]);
    p.x += config.iconWidth;

    iconsList[ICON_PAUSE] = new PauseIcon(pGame, p, config.iconWidth, config.toolBarHeight, iconsImages[ICON_PAUSE]);
    p.x += config.iconWidth;

    iconsList[ICON_RESUME] = new ResumeIcon(pGame, p, config.iconWidth, config.toolBarHeight, iconsImages[ICON_RESUME]);
    p.x += config.iconWidth;

    iconsList[ICON_SAVE] = new SaveIcon(pGame, p, config.iconWidth, config.toolBarHeight, iconsImages[ICON_SAVE]);
    p.x += config.iconWidth;

    iconsList[ICON_LOAD] = new LoadIcon(pGame, p, config.iconWidth, config.toolBarHeight, iconsImages[ICON_LOAD]);
    p.x += config.iconWidth;

    iconsList[ICON_EXIT] = new ExitIcon(pGame, p, config.iconWidth, config.toolBarHeight, iconsImages[ICON_EXIT]);
}

Toolbar::~Toolbar()
{
    for (int i = 0; i < ICON_COUNT; i++)
        delete iconsList[i];
    delete iconsList;
}

void Toolbar::draw() const
{
    for (int i = 0; i < ICON_COUNT; i++)
        iconsList[i]->draw();
    window* pWind = pGame->getWind();
    pWind->SetPen(BLACK, 3);
    pWind->DrawLine(0, config.toolBarHeight, pWind->GetWidth(), config.toolBarHeight);
}

bool Toolbar::handleClick(int x, int y)
{
    if (x > ICON_COUNT * config.iconWidth)
        return false;
    
    int clickedIconIndex = (x / config.iconWidth);
    iconsList[clickedIconIndex]->onClick();

    if (clickedIconIndex == ICON_EXIT) return true;

    return false;
}