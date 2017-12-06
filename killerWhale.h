//Programmers: Allison Chan & Vai Deevi
//Student IDs: 12538820 & 12534907
//Section: D
//Instructor: Dr. Taylor

#ifndef KILLERWHALE_H
#define KILLERWHALE_H
class Penguin;
class Fish;
class Sea;

class KillerWhale
{
  private:
    int positionX;
    int positionY;
    int killTally;
  public:
    KillerWhale();
    int getPositionX();
    int getPositionY();
    void setPositionX(int x);
    void setPositionY(int y);
    void moveWhale(Sea &seaGrid, Penguin pengs[], Fish fishies[], int sizeOfPengs, int sizeOfFishies);
};

#include "penguin.h"
#include "fish.h"
#include "sea.h"

#endif