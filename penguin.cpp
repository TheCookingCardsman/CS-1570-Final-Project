#include "penguin.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "sea.h"
#include "killerWhale.h"

using namespace std;

Penguin::Penguin()
{
  health = rand() % 21 + 60;
  alive = false;
  positionX = -1;
  positionY = -1;
}

// Description: Finds distance between penguin and a fish
// Precondition: NONE
// Postcondition: Returns the distance between the penguin and the fish
double Penguin::fishDistance(Fish fish, int x, int y)
{
  double dist = sqrt(pow(x - fish.getPositionX(),2) + pow(y - fish.getPositionY(),2));
  return dist;
}

// Description: Finds distance between penguin and a whale
// Precondition: NONE
// Postcondition: Returns the distance between the penguin and the whale
double Penguin::whaleDist(KillerWhale whale, int x, int y)
{
  double dist = sqrt(pow(x - whale.getPositionX(),2) + pow(y - whale.getPositionY(),2));
  return dist;
}

// Description: Determines number of moves penguin needs to take based on health
// Precondition: NONE
// Postcondition: Returns number of moves penguin will take
int Penguin::numMoves()
{
  if (health >= 81 && health <= 100)
  {
    return 5;
  }
  else if (health >= 61 && health <= 80)
  {
    return 4;
  }
  else if (health >= 41 && health <= 60)
  {
    return 3;
  }
  else if (health >= 21 && health <= 40)
  {
    return 2;
  }
  else if (health >= 1 && health <= 20)
  {
    return 1;
  }
  else
  {
    return -1;
  }
}
//------------------------
// Penguin::Penguin()
// {
//   health = rand() % 21 + 60;
//   positionX = -1;
//   positionY = -1;
//   alive = false;
// }

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

bool isAlive()
{
  return alive;
}

// Description: Moves the penguin a designated number of spaces (which is based on health) depending on it's condition
// Precondition: NONE
// Postcondition: Penguin has been moved
void Penguin::movePeng(Sea &seaGrid, Fish fishArr[], KillerWhale &whale1, KillerWhale &whale2)
{
  double distWhale1;
  double distWhale2;
  // Both whales within 8 units
  if (whaleDist(whale1, positionX, positionY) <= 8.00 && whaleDist(whale2, positionX, positionY) <= 8.00)
  {
    distWhale1 = whaleDist(whale1, positionX, positionY);
    distWhale2 = whaleDist(whale2, positionX, positionY);
    moveIfTwoWhales(seaGrid, whale1, whale2, distWhale1, distWhale2, fishArr);
  }
  else if (whaleDist(whale1, positionX, positionY) <= 8.00) // Whale1 is within 8 units
  {
    distWhale1 = whaleDist(whale1, positionX, positionY);
    moveIfOneWhale(seaGrid, whale1, distWhale1, fishArr);
  }
  else if (whaleDist(whale2, positionX, positionY) <= 8.00) // Whale2 is within 8 units
  {
    distWhale2 = whaleDist(whale2, positionX, positionY);
    moveIfOneWhale(seaGrid, whale2, distWhale2, fishArr);
  }
  else // Either there is only fish OR no fish or whales
  {
    // Finds the index number of the closest fish
    int fishIndex = -1;
    double distance = 8.00;

    for (int i = 0; i < 200; i++)
    {
      if (fishDistance(fishArr[i], positionX, positionY) <= 8.00) // Fish within 8 units
      {
        if (distance > fishDistance(fishArr[i], positionX, positionY))
        {
          distance = fishDistance(fishArr[i], positionX, positionY); // Adjusts distance to closest fish
          fishIndex = i;
        }
      }
    }

    if (fishIndex > 0)
    {
      moveToFish(seaGrid, fishArr, fishIndex, distance);
    }
    else // No fish or whales within 8 units
    {
      moveRandom(seaGrid);
    }
  }
}

// Description: Moves Pengin towards fish
// Preconditions: NONE
// Postcondition: Penguin has been moved
void Penguin::moveToFish(Sea &seaGrid, Fish fishArr[], int fishIndex, double distance)
{
  int loopNum = numMoves();
  int startX, startY;
  for (int i = 0; i < loopNum; i++)
  {
    startX = positionX;
    startY = positionY;
    if (seaGrid.filled(positionX-1, positionY) == false && fishDistance(fishArr[fishIndex], positionX-1, positionY) <= distance)
    {
      positionX -= 1;
    }
    else if (seaGrid.filled(positionX-1, positionY+1) == false && fishDistance(fishArr[fishIndex], positionX-1, positionY+1) <= distance)
    {
      positionX -= 1;
      positionY += 1;
    }
    else if (seaGrid.filled(positionX, positionY+1) == false && fishDistance(fishArr[fishIndex], positionX, positionY+1) <= distance)
    {
      positionY += 1;
    }
    else if (seaGrid.filled(positionX+1, positionY+1) == false && fishDistance(fishArr[fishIndex], positionX+1, positionY+1) <= distance)
    {
      positionX += 1;
      positionY += 1;
    }
    else if (seaGrid.filled(positionX+1, positionY) == false && fishDistance(fishArr[fishIndex], positionX+1, positionY) <= distance)
    {
      positionX += 1;
    }
    else if (seaGrid.filled(positionX+1, positionY-1) == false && fishDistance(fishArr[fishIndex], positionX+1, positionY-1) <= distance)
    {
      positionX += 1;
      positionY -= 1;
    }
    else if (seaGrid.filled(positionX, positionY-1) == false && fishDistance(fishArr[fishIndex], positionX, positionY-1) <= distance)
    {
      positionY -= 1;
    }
    else if (seaGrid.filled(positionX-1, positionY-1) == false && fishDistance(fishArr[fishIndex], positionX-1, positionY-1) <= distance)
    {
      positionX -= 1;
      positionY -= 1;
    }

    distance = fishDistance(fishArr[fishIndex], positionX, positionY);

    if (startX != positionX || startY != positionY)
    {
      health -= 1;
    }

    if (fishArr[fishIndex].getPositionX() == positionX && fishArr[fishIndex].getPositionY() == positionY)
    {
      seaGrid.place('P', positionX, positionY);
      health += fishArr[fishIndex].getFoodValue();
      fishArr[fishIndex].setDead();
      seaGrid.place('-', fishArr[fishIndex].getPositionX(), fishArr[fishIndex].getPositionY());
      break;
    }
    else
    {
      seaGrid.place('P', positionX, positionY);
    }

    if (health <= 0)
    {
      alive = false;
      positionX = -1;
      positionY = -1;
      break;
    }
  }
}

// Description: Moves penguin away from one whale
// Precondition: NONE
// Postcondition: Penguin has been moved
void Penguin::moveIfOneWhale(Sea &seaGrid, KillerWhale &whale, double distWhale, Fish fishArr[])
{
  int loopNum = numMoves();
  int seaSize = seaGrid.getSize();
  int startX, startY;
  bool fishEaten = false;

  for (int i = 0; i < loopNum; i++)
  {
    startX = positionX;
    startY = positionY;

    if (seaGrid.filled(positionX-1, positionY) == false && (whaleDist(whale, positionX-1, positionY) >= distWhale) && (positionX != 0))
    {
      positionX -= 1;
    }
    else if (seaGrid.filled(positionX-1, positionY+1) == false && (whaleDist(whale, positionX-1, positionY+1) >= distWhale) && (positionX != 0) && (positionY != seaSize-1))
    {
      positionX -= 1;
      positionY += 1;
    }
    else if (seaGrid.filled(positionX, positionY+1) == false && (whaleDist(whale, positionX, positionY+1) >= distWhale) && (positionY != seaSize-1))
    {
      positionY += 1;
    }
    else if (seaGrid.filled(positionX+1, positionY+1) == false && (whaleDist(whale, positionX+1, positionY+1) >= distWhale) && (positionX != seaSize-1) && (positionY != seaSize-1))
    {
      positionX += 1;
      positionY += 1;
    }
    else if (seaGrid.filled(positionX+1, positionY) == false && (whaleDist(whale, positionX+1, positionY) >= distWhale) && (positionX != seaSize-1))
    {
      positionX += 1;
    }
    else if (seaGrid.filled(positionX+1, positionY-1) == false && (whaleDist(whale, positionX+1, positionY-1) >= distWhale) && (positionX != seaSize-1) && (positionY != 0))
    {
      positionX += 1;
      positionY -= 1;
    }
    else if (seaGrid.filled(positionX, positionY-1) == false && (whaleDist(whale, positionX, positionY-1) >= distWhale) && (positionY != 0))
    {
      positionY -= 1;
    }
    else if (seaGrid.filled(positionX-1, positionY-1) == false && (whaleDist(whale, positionX-1, positionY-1) >= distWhale) && (positionX != 0) && (positionY != 0))
    {
      positionX -= 1;
      positionY -= 1;
    }

    distWhale = whaleDist(whale, positionX, positionY);

    if (startX != positionX || startY != positionY)
    {
      health -= 1;
    }

    for (int j = 0; j < 200; j++)
    {
      if (fishArr[j].getPositionX() == positionX && fishArr[j].getPositionY() == positionY)
      {
        seaGrid.place('P', positionX, positionY);
        health += fishArr[j].getFoodValue();
        fishArr[j].setDead();
        seaGrid.place('-', fishArr[j].getPositionX(), fishArr[j].getPositionY());
        fishEaten = true;
        break;
      }
    }

    if (fishEaten)
    {
      break;
    }

    seaGrid.place('P', positionX, positionY);

    if (health <= 0)
    {
      alive = false;
      positionX = -1;
      positionY = -1;
      break;
    }
  }
}

// Descrioption: Moves the penguin away from two whales
// Precondition: NONE
// Postcondition: Penguin has been moved
void Penguin::moveIfTwoWhales(Sea &seaGrid, KillerWhale &whale1, KillerWhale &whale2, double distWhale1, double distWhale2, Fish fishArr[])
{
  int loopNum = numMoves();
  int seaSize = seaGrid.getSize();
  int startX, startY;
  bool fishEaten = false;

  for (int i = 0; i < loopNum; i++)
  {
    startX = positionX;
    startY = positionY;

    if (seaGrid.filled(positionX-1, positionY) == false  && (whaleDist(whale1, positionX-1, positionY) >= distWhale1) && (whaleDist(whale2, positionX-1, positionY) >= distWhale2) && (positionX != 0))
    {
      positionX -= 1;
    }
    else if (seaGrid.filled(positionX-1, positionY+1) == false && (whaleDist(whale1, positionX-1, positionY+1) >= distWhale1) && (whaleDist(whale2, positionX-1, positionY+1) >= distWhale2) && (positionX != 0) && (positionY != seaSize-1))
    {
      positionX -= 1;
      positionY += 1;
    }
    else if (seaGrid.filled(positionX, positionY+1) == false && (whaleDist(whale1, positionX, positionY+1) >= distWhale1) && (whaleDist(whale2, positionX, positionY+1) >= distWhale2) && (positionY != seaSize-1))
    {
      positionY += 1;
    }
    else if (seaGrid.filled(positionX+1, positionY+1) == false && (whaleDist(whale1, positionX+1, positionY+1) >= distWhale1) && (whaleDist(whale2, positionX+1, positionY+1) >= distWhale2) && (positionX != seaSize-1) && (positionY != seaSize-1))
    {
      positionX += 1;
      positionY += 1;
    }
    else if (seaGrid.filled(positionX+1, positionY) == false && (whaleDist(whale1, positionX+1, positionY) >= distWhale1) && (whaleDist(whale2, positionX+1, positionY) >= distWhale2) && (positionX != seaSize-1))
    {
      positionX += 1;
    }
    else if (seaGrid.filled(positionX+1, positionY-1) == false && (whaleDist(whale1, positionX+1, positionY+1) >= distWhale1) && (whaleDist(whale2, positionX+1, positionY+1) >= distWhale2) && (positionX != seaSize-1) && (positionY != 0))
    {
      positionX += 1;
      positionY -= 1;
    }
    else if (seaGrid.filled(positionX, positionY-1) == false && (whaleDist(whale1, positionX, positionY-1) >= distWhale1) && (whaleDist(whale2, positionX, positionY-1) >= distWhale2) && (positionY != 0))
    {
      positionY -= 1;
    }
    else if (seaGrid.filled(positionX-1, positionY-1) == false && (whaleDist(whale1, positionX-1, positionY-1) >= distWhale1) && (whaleDist(whale2, positionX-1, positionY-1) >= distWhale2) && (positionX != 0) && (positionY != 0))
    {
      positionX -= 1;
      positionY -= 1;
    }

    distWhale1 = whaleDist(whale1, positionX, positionY);
    distWhale2 = whaleDist(whale2, positionX, positionY);

    if (startX != positionX || startY != positionY)
    {
      health -= 1;
    }

    for (int j = 0; j < 200; j++)
    {
      if (fishArr[j].getPositionX() == positionX && fishArr[j].getPositionY() == positionY)
      {
        seaGrid.place('P', positionX, positionY);
        health += fishArr[j].getFoodValue();
        fishArr[j].setDead();
        seaGrid.place('-', fishArr[j].getPositionX(), fishArr[j].getPositionY());
        fishEaten = true;
        break;
      }
    }

    if (fishEaten)
    {
      break;
    }

    seaGrid.place('P', positionX, positionY);

    if (health <= 0)
    {
      alive = false;
      positionX = -1;
      positionY = -1;
      break;
    }
  }
}

// Description: Moves the penguin in a random direction
// Precondition: NONE
// Postcondition: Penguin has been moved
void Penguin::moveRandom(Sea &seaGrid)
{
  int seaSize = seaGrid.getSize();
  bool turn;
  int randNum;
  int timesChecked = 0;
  int startX;
  int startY;
  int loopNum = numMoves();
  for (int i = 0; i < loopNum; i++)
  {
    startX = positionX;
    startY = positionY;
    turn = true;
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
          else 
          {
            timesChecked++;
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
    if (startX != positionX || startY != positionY)
    {
      health -= 1;
    }
    seaGrid.place('P', positionX, positionY);
  }
}