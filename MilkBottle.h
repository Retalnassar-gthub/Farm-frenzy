#pragma once
#include "Drawable.h"

class MilkBottle : public Drawable {
private:
    int x;
    int y;

public:
    MilkBottle(int posX, int posY);
    virtual void Draw() override;
    int getX() const;
    int getY() const;
};
