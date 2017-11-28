#include "fish.h"
#include <iostream>
using namespace std;

Fish::Fish()
{
	food = (rand() % 10) + 1;
  xCord = -1;
  yCord = -1;
}

void Fish::move()
{ 
  int directionNum = (rand() % 8) + 1;

  if (directionNum == 1)
  {
    xCord += 1; 
  }  
  else if (directionNum == 2)
  {
    xCord -= 1;
  }
  else if (directionNum == 3)
  {
    yCord += 1;
  }
  else if (directionNum == 4)
  {
    yCord -= 1;
  }
  else if (directionNum == 5)
  {
    xCord += 1;
    yCord += 1;
  }
  else if (directionNum == 6)
  {
    xCord -= 1;
    yCord+= 1;
  }
  else if (directionNum == 7)
  {
    xCord += 1;
    yCord -= 1;
  }
  else if (directionNum == 8)
  {
    xCord -= 1;
    yCord -= 1;
  }
}

int Fish::getXCord()
{
  return xCord;
}

int Fish::getYCord()
{
  return yoCord;
}