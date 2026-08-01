#include "FoodArea.h"

FoodArea::FoodArea(int posX, int posY) : x(posX), y(posY) {}

void FoodArea::Draw() {
    // pGUI->DrawImage("Images\\Grass.png", x, y, 40, 40);
}

int FoodArea::getX() const { return x; }
int FoodArea::getY() const { return y; }
