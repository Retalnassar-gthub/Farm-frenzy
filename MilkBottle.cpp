#include "MilkBottle.h"

MilkBottle::MilkBottle(int posX, int posY) : x(posX), y(posY) {}

void MilkBottle::Draw() {
    // pGUI->DrawImage("Images\\Milk.png", x, y, 30, 30);
}

int MilkBottle::getX() const { return x; }
int MilkBottle::getY() const { return y; }
