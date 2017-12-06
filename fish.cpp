//Programmers: Allison Chan & Vai Deevi
//Student IDs: 12538820 & 12534907
//Section: D
//Instructor: Dr. Taylor

#include "fish.h"
#include <iostream>
using namespace std;

Fish::Fish()
{
  foodValue = rand() % 10 + 1;
  positionX = -1;
  positionY = -1;
  alive = false;
}

int Fish::getPositionX()
{
  return positionX;
}

int Fish::getPositionY()
{
 return positionY;
}

void Fish::setPositionX(int change)
{
  positionX = change;
}

void Fish::setPositionY(int change)
{
  positionY = change;
}

void Fish::moveFishGetOutTheWayGetOutTheWayFishGetOutTheWay()
{
  int direction = rand() % 8;

  if(direction % 8 == 0) //north
  {
    setPositionX(getPositionX() - 1);
  }
  else if(direction % 8 == 1) //east
  {
    setPositionY(getPositionY() + 1);
  }
  else if(direction % 8 == 2) //south
  {
    setPositionX(getPositionX() + 1);
  }
  else if(direction % 8 == 3) //west
  {
    setPositionY(getPositionY() - 1);
  }
  else if(direction % 8 == 4) //north east
  {
    setPositionX(getPositionX() - 1);
    setPositionY(getPositionY() + 1);
  }
  else if(direction % 8 == 5) //south east
  {
    setPositionX(getPositionX() + 1);
    setPositionY(getPositionY() + 1);
  }
  else if(direction % 8 == 6) //south west
  {
    setPositionX(getPositionX() + 1);
    setPositionY(getPositionY() - 1);
  }
  else if(direction % 8 == 7) //north west
  {
    setPositionX(getPositionX() - 1);
    setPositionY(getPositionY() - 1);
  }
}