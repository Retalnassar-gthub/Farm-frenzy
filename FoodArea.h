#pragma once
#include "Drawable.h"

class FoodArea : public Drawable {
private:
    int x;
    int y;

public:
    FoodArea(int posX, int posY);
    virtual void Draw() override;
    int getX() const;
    int getY() const;
};
