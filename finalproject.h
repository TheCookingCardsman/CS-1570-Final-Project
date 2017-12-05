//Programmers: Allison Chan & Vai Deevi
//Student IDs: 12538820 & 12534907
//Section: D
//Instructor: Dr. Taylor

#ifndef FINALPROJECT_H
#define FINALPROJECT_H
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <unistd.h>

using namespace std;

class Penguin
{
  private: 
    int health;
    int positionX;
    int positionY;
    bool alive;
  public:
    Penguin();
    int getPositionX();
    int getPositionY();
    void setPositionX(int change);
    void setPositionY(int change);
    void moveFishGetOutTheWayGetOutTheWayFishGetOutTheWay();
};

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
    void setPositionX(int change);
    void setPositionY(int change);
    void moveFishGetOutTheWayGetOutTheWayFishGetOutTheWay();
};

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
    void setPositionX(int change);
    void setPositionY(int change);
    void moveFishGetOutTheWayGetOutTheWayFishGetOutTheWay(Penguin arr[], int size);
};

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
};

#endif