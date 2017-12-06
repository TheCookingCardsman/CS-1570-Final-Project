#ifndef SEA_H
#define SEA_H
#include <iostream>
using namespace std;
class Penguin;
class Fish;
class KillerWhale;

class Sea
{
  private: 
    char arr[25][25];
    short sizeOfSeaWorld;
    void clear(Sea &s);
    void populate(Penguin arrPeng[], Fish arrFish[], KillerWhale whale1, KillerWhale whale2);
  public:
    Sea(short gridSize, Penguin arrPeng[], Fish arrFish[], KillerWhale whale1, KillerWhale whale2);
    friend ostream & operator<<(ostream &out, Sea s);
    int getSize();
    bool filled(int x, int y);
    void place(char c, int x, int y);
};

#include "penguin.h"
#include "fish.h"
#include "killerWhale.h"

#endif