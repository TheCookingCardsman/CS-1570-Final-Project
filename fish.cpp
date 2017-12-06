//Programmers: Allison Chan & Vai Deevi
//Student IDs: 12538820 & 12534907
//Section: D
//Instructor: Dr. Taylor

#include "fish.h"
#include "sea.h"
#include "penguin.h"
#include "killerWhale.h"
#include <iostream>

#include <ctime>
#include <cstdlib>
#include <ctime>
using namespace std;

Fish::Fish()
{
  foodValue = rand() % 10 + 1;
  positionX = -1;
  positionY = -1;
  alive = false;
}

void Fish::setDead()
{
  positionX = -1;
  positionY = -1;
  alive = false;
}
int Fish::getFoodValue()
{
  return foodValue;
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

void Fish::moveFish(Sea &seaGrid)
{
  int seaSize = seaGrid.getSize();
  bool turn = true;
  int timesChecked = 0;
  int randNum;
  if(alive)
  {
    while (turn)
    {
      randNum = (rand() % 8) + 1;
      switch(randNum)
      {
        case 1:
          if (seaGrid.filled(positionX-1, positionY) == false && (positionX != 0))
          {
            positionX -= 1;
            turn = false;
          }
          else
          {
            timesChecked++;
          }
          break;
        case 2:
          if (seaGrid.filled(positionX-1, positionY+1) == false && (positionX != 0) && (positionY != seaSize-1))
          {
            positionX -= 1;
            positionY += 1;
            turn = false;
          }
          break;
        case 3:
          if (seaGrid.filled(positionX, positionY+1) == false && (positionY != seaSize-1))
          {
            positionY += 1;
            turn = false;
          }
          else
          {
            timesChecked++;
          }
          break;
        case 4:
          if (seaGrid.filled(positionX+1, positionY+1) == false && (positionX != seaSize-1) && (positionY != seaSize-1))
          {
            positionX += 1;
            positionY += 1;
            turn = false;
          }
          else
          {
            timesChecked++;
          }
          break;
        case 5:
          if (seaGrid.filled(positionX+1, positionY) == false && (positionX != seaSize-1))
          {
            positionX += 1;
            turn = false;
          }
          else
          {
            timesChecked++;
          }
          break;
        case 6:
          if (seaGrid.filled(positionX+1, positionY-1) == false && (positionX != seaSize-1) && (positionY != 0))
          {
            positionX += 1;
            positionY -= 1;
            turn = false;
          }
          else
          {
            timesChecked++;
          }
          break;
        case 7:
          if (seaGrid.filled(positionX, positionY-1) == false && (positionY != 0))
          {
            positionY -= 1;
            turn = false;
          }
          else
          {
            timesChecked++;
          }
          break;
        case 8:
          if (seaGrid.filled(positionX-1, positionY-1) == false && (positionX != 0) && (positionY != 0))
          {
            positionX -= 1;
            positionY -= 1;
            turn = false;
          }
          else
          {
            timesChecked++;
          }
          break;
        default:
          if (timesChecked >= 8)
          {
            turn = false;
          }
          break;
      }
    }
  }
  
  seaGrid.place('F', positionX, positionY);
}