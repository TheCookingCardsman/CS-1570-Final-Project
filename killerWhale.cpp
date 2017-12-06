//Programmers: Allison Chan & Vai Deevi
//Student IDs: 12538820 & 12534907
//Section: D
//Instructor: Dr. Taylor

#include "killerWhale.h"
#include "sea.h"
#include "penguin.h"
#include "fish.h"
#include <iostream>
#include <cmath>
using namespace std;

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