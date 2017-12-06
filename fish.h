//Programmers: Allison Chan & Vai Deevi
//Student IDs: 12538820 & 12534907
//Section: D
//Instructor: Dr. Taylor

#ifndef FISH_H
#define FISH_H
class Sea;

class Fish
{
  private:
    int foodValue;
    int positionX;
    int positionY;
    bool alive;
  public:
    Fish();
    int getPositionX();
    int getPositionY();
    bool isAlive();
    void setPositionX(int change);
    void setPositionY(int change);
    void moveFish(Sea &seaGrid);
    int getFoodValue();
    void setDead();
};

#include "sea.h"

#endif