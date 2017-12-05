//Programmers: Allison Chan & Vai Deevi
//Student IDs: 12538820 & 12534907
//Section: D
//Instructor: Dr. Taylor

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <unistd.h>
#include "finalproject.h"

using namespace std;

Sea::Sea(short int gridSize, Penguin arrPeng[], Fish arrFish[], KillerWhale whale1, KillerWhale whale2)
{
  sizeOfSeaWorld = gridSize;
  populate(arrPeng, arrFish, whale1, whale2);
}

void Sea::clear(Sea &s)
{
  for(int i = 0; i < s.sizeOfSeaWorld; i++)
  {
    for(int j = 0; j < s.sizeOfSeaWorld; j++)
    {
      s.arr[i][j] = '\0';
    }
  }
}

void Sea::populate(Penguin arrPeng[], Fish arrFish[], KillerWhale whale1, KillerWhale whale2)
{
  int randWhale1X;
  int randWhale1Y;
  int randWhale2X;
  int randWhale2Y;
  int randFishX;
  int randFishY;
  int randPengX;
  int randPengY;
  randWhale1X = rand() % 17;
  randWhale1Y = rand() % 17;
  whale1.setPositionX(randWhale1X);
  whale1.setPositionY(randWhale1Y);
  arr[randWhale1X][randWhale1Y] = 'W';
  do
  {
    randWhale2X = rand() % 17;
    randWhale2Y = rand() % 17;
  }while(arr[randWhale2X][randWhale2Y] != '\0');
  whale2.setPositionX(randWhale2X);
  whale2.setPositionY(randWhale2Y);
  arr[randWhale2X][randWhale2Y] = 'W';
  for(int i = 0; i < 35; i++)
  {
    do
    {
      randFishX = rand() % 17;
      randFishY = rand() % 17;
    }while(arr[randFishX][randFishY] != '\0');
    arrFish[i].setPositionX(randFishX);
    arrFish[i].setPositionY(randFishY);
    arr[randFishX][randFishY] = 'F';
  }
  for(int j = 0; j < 20; j++)
  {
    do
    {
      randPengX = rand() % 17;
      randPengY = rand() % 17;
    }while(arr[randPengX][randPengY] != '\0');
    arrPeng[j].setPositionX(randPengX);
    arrPeng[j].setPositionY(randPengY);
    arr[randPengX][randPengY] = 'P';
  }
}

ostream &operator<<(ostream &out, Sea s)
{
  for(int i = 0; i < s.sizeOfSeaWorld; i++)
  {
   for(int j = 0; j < s.sizeOfSeaWorld; j++)
   {
     if(s.arr[i][j] == '\0')
     {
       out<<"- ";
     }
     else
     {
       out<<s.arr[i][j]<<" ";
     } 
   }
   cout<<endl;
  }
  return out;
}

Penguin::Penguin()
{
  health = rand() % 21 + 60;
  positionX = -1;
  positionY = -1;
  alive = false;
}

int Penguin::getPositionX()
{
  return positionX;
}

int Penguin::getPositionY()
{
 return positionY;
}

void Penguin::setPositionX(int change)
{
  positionX = change;
}

void Penguin::setPositionY(int change)
{
  positionY = change;
}

void Penguin::moveFishGetOutTheWayGetOutTheWayFishGetOutTheWay()
{
  if(health >= 81) //move 5 cells
  {

  }
  else if(health >= 61) //move 4 cells
  {

  }
  else if(health >= 41) //move 3 cells
  {

  }
  else if(health >= 21) //move 2 cells
  {

  }
  else if(health >= 1) //move 1 cells
  {

  }
  else //no health
  {
    
  }
}

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

KillerWhale::KillerWhale()
{
  positionX = -1;
  positionY = -1;
  killTally = 0;
}

int KillerWhale::getPositionX()
{
  return positionX;
}

int KillerWhale::getPositionY()
{
  return positionY;
}

void KillerWhale::setPositionX(int change)
{
  positionX = change;
}

void KillerWhale::setPositionY(int change)
{
  positionY = change;
}

void KillerWhale::moveFishGetOutTheWayGetOutTheWayFishGetOutTheWay(Penguin pengs[], int size)
{
  //move 3 cells
  Penguin closestPenguin = pengs[0];
  for(int i = 0; i < size; i++)
  {
    if(sqrt(pow(pengs[i].getPositionX() - getPositionX(), 2) + pow(pengs[i].getPositionY() - getPositionY(), 2)) <= 3 || sqrt(pow(pengs[i].getPositionX() - getPositionX(), 2) + pow(pengs[i].getPositionY() - getPositionY(), 2)) == sqrt(18))
    {
      setPositionX(pengs[i].getPositionX());
      setPositionY(pengs[i].getPositionY());
      killTally++;

      return;
    }
    else
    {
      if(sqrt(pow(pengs[i].getPositionX() - getPositionX(), 2) + pow(pengs[i].getPositionY() - getPositionY(), 2)) < sqrt(pow(closestPenguin.getPositionX() - getPositionX(), 2) + pow(closestPenguin.getPositionY() - getPositionY(), 2)))
      {
        closestPenguin = pengs[i];
      }
    }
  }
  //something about closest penguin and the whale and the whale going towards it idk
  if(getPositionX() < closestPenguin.getPositionX() && getPositionY() < closestPenguin.getPositionY())
  {
    for(int j = 0; j < 3; j++)
    {
      if(getPositionX() != closestPenguin.getPositionX() && getPositionY() != closestPenguin.getPositionY())
      {
        setPositionX(getPositionX() + 1);
        setPositionY(getPositionY() + 1);
      }
      else
      {
        if(getPositionX() == closestPenguin.getPositionX() && getPositionY() != closestPenguin.getPositionY())
        {
          setPositionY(getPositionY() + 1);
        }
        else if(getPositionX() != closestPenguin.getPositionX() && getPositionY() == closestPenguin.getPositionY())
        {
          setPositionX(getPositionX() + 1);
        }
      }
    }
  }
  else if(getPositionX() < closestPenguin.getPositionX() && getPositionY() > closestPenguin.getPositionY())
  {

  }
  else if(getPositionX() > closestPenguin.getPositionX() && getPositionY() < closestPenguin.getPositionY())
  {

  }
  else if(getPositionX() > closestPenguin.getPositionX() && getPositionY() > closestPenguin.getPositionY())
  {

  }
  else if(getPositionX() == closestPenguin.getPositionX() && getPositionY() < closestPenguin.getPositionY())
  {
    for(int j = 0; j < 3; j++)
    {

    }
  }
  else if(getPositionX() == closestPenguin.getPositionX() && getPositionY() < closestPenguin.getPositionY())
  {
    
  }
  else if(getPositionX() < closestPenguin.getPositionX() && getPositionY() == closestPenguin.getPositionY())
  {
    
  }
  else if(getPositionX() > closestPenguin.getPositionX() && getPositionY() == closestPenguin.getPositionY())
  {
    
  }

  return;
}