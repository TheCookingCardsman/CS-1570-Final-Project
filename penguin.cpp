#include "penguin.h"
#include "fish.h"
#include "killer_whale.h"
#include "sea.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

Penguin::Penguin()
{
  health = ((rand() % 20) + 1) + 60;
  alive = false;
  xCord = -1;
  yCord = -1;
}

// Description: Moves the pengin a designated number of spaces (which is based on health) depending on it's condition
// Precondition: NONE
// Postcondition: Penguin has been moved
void Penguin::move(Sea *seaGrid, Fish fishArr[], Killer_Whale *whale1, Killer_Whale *whale2)
{
  double distWhale1;
  double distWhale2;
  // Both whales within 8 units
  if (whaleDist(whale1) <= 8.00 && whaleDist(whale2) <= 8.00)
  {
    distWhale1 = whaleDist(whale1, xCord, yCord);
    distWhale2 = whaleDist(whale2, xCord, yCord);
    moveIfTwoWhales(seaGrid, whale1, whale2, distWhale1, distWhale2, fishArr);
  }
  else if (whaleDist(whale1) <= 8.00) // Whale1 is within 8 units
  {
    distWhale1 = whaleDist(whale1, xCord, yCord);
    moveIfOneWhale(seaGrid, whale1, distWhale1);
  }
  else if (whaleDist(whale2) <= 8.00) // Whale2 is within 8 units
  {
    distWhale2 = whaleDist(whale2, xCord, yCord);
    moveIfOneWhale(seaGrid, whale2, distWhale2);
  }
  else // Either there is only fish OR no fish or whales
  {
    // Finds the index number of the closest fish
    int fishIndex = -1;
    double distance = 8.00;

    for (int i = 0; i < fishArr.size(); i++)
    {
      if (fishDistance(fishArr[i], xCord, yCord) <= 8.00) // Fish within 8 units
      {
        if (distance > fishDistance(fishArr[i], xCord, yCord))
        {
          distance = fishDistance(fishArr[i], xCord, yCord) // Adjusts distance to closest fish
          fishIndex = i;
        }
      }
    }

    if (fishIndex > 0)
    {
      moveToFish(seaGrid, fishArr, fishIndex, distance)
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
void Penguin::moveToFish(Sea *seaGrid, Fish fishArr[], int fishIndex, double distance)
{
  int loopNum = numMoves();
  int startX, startY;
  for (int i = 0; i < loopNum; i++)
  {
    startX = xCord;
    startY = yCord;
    if (seaGrid.filled(xCord-1, yCord) == false && fishDistance(fishArr[fishIndex], xCord-1, yCord) <= distance)
    {
      xCord -= 1;
    }
    else if (seaGrid.filled(xCord-1, yCord+1) == false && fishDistance(fishArr[fishIndex], xCord-1, yCord+1) <= distance)
    {
      xCord -= 1;
      yCord += 1;
    }
    else if (seaGrid.filled(xCord, yCord+1) == false && fishDistance(fishArr[fishIndex], xCord, yCord+1) <= distance)
    {
      yCord += 1;
    }
    else if (seaGrid.filled(xCord+1, yCord+1) == false && fishDistance(fishArr[fishIndex], xCord+1, yCord+1) <= distance)
    {
      xCord += 1;
      yCord += 1;
    }
    else if (seaGrid.filled(xCord+1, yCord) == false && fishDistance(fishArr[fishIndex], xCord+1, yCord) <= distance)
    {
      xCord += 1;
    }
    else if (seaGrid.filled(xCord+1, yCord-1) == false && fishDistance(fishArr[fishIndex], xCord+1, yCord-1) <= distance)
    {
      xCord += 1;
      yCord -= 1;
    }
    else if (seaGrid.filled(xCord, yCord-1) == false && fishDistance(fishArr[fishIndex], xCord, yCord-1) <= distance)
    {
      yCord -= 1;
    }
    else if (seaGrid.filled(xCord-1, yCord-1) == false && fishDistance(fishArr[fishIndex], xCord-1, yCord-1) <= distance)
    {
      xCord -= 1;
      yCord -= 1;
    }

    distance = fishDistance(fishArr[fishIndex], xCord, yCord);

    if (startX != xCord || startY != yCord)
    {
      health -= 1;
    }

    if (fishArr[fishIndex].getXCord() == xCord && fishArr[fishIndex].getYCord() == yCord)
    {
      seaGrid.replace('P', xCord, yCord);
      health += fishArr[fishIndex].getHealth();
      fishArr[fishIndex].setDead(xCord, yCord);
      break;
    }
    else
    {
      seaGrid.replace('P', xCord, yCord);
    }

    if (health <= 0)
    {
      alive = false;
      xCord = -1;
      yCord = -1;
      break;
    }
  }
}

// Description: Moves penguin away from one whale
// Precondition: NONE
// Postcondition: Penguin has been moved
void Penguin::moveIfOneWhale(Sea *seaGrid, Killer_Whale *whale, double distWhale, Fish fishArr[])
{
  int loopNum = numMoves()
  int seaSize = seaGrid.getSize();
  int startX, startY;
  bool fishEaten = false;

  for (int i = 0; i < loopNum; i++)
  {
    startX = xCord;
    startY = yCord

    if (seaGrid.filled(xCord-1, yCord) == false && (whaleDist(whale, xCord-1, yCord) >= distWhale) && (xCord != 0))
    {
      xCord -= 1;
    }
    else if (seaGrid.filled(xCord-1, yCord+1) == false && (whaleDist(whale, xCord-1, yCord+1) >= distWhale) && (xCord != 0) && (yCord != seaSize-1))
    {
      xCord -= 1;
      yCord += 1;
    }
    else if (seaGrid.filled(xCord, yCord+1) == false && (whaleDist(whale, xCord, yCord+1) >= distWhale) && (yCord != seaSize-1))
    {
      yCord += 1;
    }
    else if (seaGrid.filled(xCord+1, yCord+1) == false && (whaleDist(whale, xCord+1, yCord+1) >= distWhale) && (xCord != seaSize-1) && (yCord != seaSize-1))
    {
      xCord += 1;
      yCord += 1;
    }
    else if (seaGrid.filled(xCord+1, yCord) == false && (whaleDist(whale, xCord+1, yCord) >= distWhale) && (xCord != seaSize-1))
    {
      xCord += 1;
    }
    else if (seaGrid.filled(xCord+1, yCord-1) == false && (whaleDist(whale, xCord+1, yCord-1) >= distWhale) && (xCord != seaSize-1) && (yCord != 0))
    {
      xCord += 1;
      yCord -= 1;
    }
    else if (seaGrid.filled(xCord, yCord-1) == false && (whaleDist(whale, xCord, yCord-1) >= distWhale) && (yCord != 0))
    {
      yCord -= 1;
    }
    else if (seaGrid.filled(xCord-1, yCord-1) == false && (whaleDist(whale, xCord-1, yCord-1) >= distWhale) && (xCord != 0) && (yCord != 0))
    {
      xCord -= 1;
      yCord -= 1;
    }

    distWhale = whaleDist(whale, xCord, yCord);

    if (startX != xCord || startY != yCord)
    {
      health -= 1;
    }

    for (int j = 0; j < fishArr.size(); j++)
    {
      if (fishArr[j].getXCord() == xCord && fishArr[j].getYCord() == yCord)
      {
        seaGrid.replace('P', xCord, yCord);
        health += fishArr[j].getHealth();
        fishArr[j].setDead(xCord, yCord);
        fishEaten = true;
        break;
      }
    }

    if (fishEaten)
    {
      break;
    }

    seaGrid.replace('P', xCord, yCord);

    if (health <= 0)
    {
      alive = false;
      xCord = -1;
      yCord = -1;
      break;
    }
  }
}

// Descrioption: Moves the penguin away from two whales
// Precondition: NONE
// Postcondition: Penguin has been moved
void Penguin::moveIfTwoWhales(Sea *seaGrid, Killer_Whale *whale1, Kille_Whale *whale2, double distWhale1, double distWhale2, Fish fishArr[]);
{
  int loopNum = numMoves();
  int seaSize = seaGrid.getSize();
  int startX, startY;
  bool fishEaten = false;

  for (int i = 0; i < loopNum; i++)
  {
    startX = xCord;
    startY = yCord

    if (seaGrid.filled(xCord-1, yCord) == false  && (whaleDist(whale1, xCord-1, yCord) >= distWhale1) && (whaleDist(whale2, xCord-1, yCord) >= distWhale2) && (xCord != 0))
    {
      xCord -= 1;
    }
    else if (seaGrid.filled(xCord-1, yCord+1) == false && (whaleDist(whale1, xCord-1, yCord+1) >= distWhale1) && (whaleDist(whale2, xCord-1, yCord+1) >= distWhale2) && (xCord != 0) && (yCord != seaSize-1))
    {
      xCord -= 1;
      yCord += 1;
    }
    else if (seaGrid.filled(xCord, yCord+1) == false && (whaleDist(whale1, xCord, yCord+1) >= distWhale1) && (whaleDist(whale2, xCord, yCord+1) >= distWhale2) && (yCord != seaSize-1))
    {
      yCord += 1;
    }
    else if (seaGrid.filled(xCord+1, yCord+1) == false && (whaleDist(whale1, xCord+1, yCord+1) >= distWhale1) && (whaleDist(whale2, xCord+1, yCord+1) >= distWhale2) && (xCord != seaSize-1) && (yCord != seaSize-1))
    {
      xCord += 1;
      yCord += 1;
    }
    else if (seaGrid.filled(xCord+1, yCord) == false && (whaleDist(whale1, xCord+1, yCord) >= distWhale1) && (whaleDist(whale2, xCord+1, yCord) >= distWhale2) && (xCord != seaSize-1))
    {
      xCord += 1;
    }
    else if (seaGrid.filled(xCord+1, yCord-1) == false && (whaleDist(whale1, xCord+1, yCord+1) >= distWhale1) && (whaleDist(whale2, xCord+1, yCord+1) >= distWhale2) && (xCord != seaSize-1) && (yCord != 0))
    {
      xCord += 1;
      yCord -= 1;
    }
    else if (seaGrid.filled(xCord, yCord-1) == false && (whaleDist(whale1, xCord, yCord-1) >= distWhale1) && (whaleDist(whale2, xCord, yCord-1) >= distWhale2) && (yCord != 0))
    {
      yCord -= 1;
    }
    else if (seaGrid.filled(xCord-1, yCord-1) == false && (whaleDist(whale1, xCord-1, yCord-1) >= distWhale1) && (whaleDist(whale2, xCord-1, yCord-1) >= distWhale2) && (xCord != 0) && (yCord != 0))
    {
      xCord -= 1;
      yCord -= 1;
    }

    distWhale1 = whaleDist(whale1, xCord, yCord);
    distWhale2 = whaleDist(whale2, xCord, yCord);

    if (startX != xCord || startY != yCord)
    {
      health -= 1;
    }

    for (int j = 0; j < fishArr.size(); j++)
    {
      if (fishArr[j].getXCord() == xCord && fishArr[j].getYCord() == yCord)
      {
        seaGrid.replace('P', xCord, yCord);
        health += fish[j].getHealth();
        fishArr[j].setDead(xCord, yCord);
        fishEaten = true;
        break;
      }
    }

    if (fishEaten)
    {
      break;
    }

    seaGrid.replace('P', xCord, yCord);

    if (health <= 0)
    {
      alive = false;
      xCord = -1;
      yCord = -1;
      break;
    }
  }
}

// Description: Moves the penguin in a random direction
// Precondition: NONE
// Postcondition: Penguin has been moved
void Penguin::moveRandom(Sea *seaGrid)
{
  int seaSize = seaGrid.getSize();
  int loopNum = numMoves();
  int startX;
  int startY;
  bool turn = true;
  int randNum;
  for (int i = 0; i < loopNum; i++)
  {
    startX = xCord;
    startY = yCord;
    while (turn)
    {
      randNum = (rand() % 8) + 1;
      switch(randNum)
      {
        case 1:
          if (seaGrid.filled(xCord-1, yCord) == false && (xCord != 0))
          {
            xCord -= 1;
            turn = false;
          }
          break;
        case 2:
          if (seaGrid.filled(xCord-1, yCord+1) == false && (xCord != 0) && (yCord != seaSize-1))
          {
            xCord -= 1;
            yCord += 1;
            turn = false;
          }
          break;
        case 3:
          if (seaGrid.filled(xCord, yCord+1) == false && (yCord != seaSize-1))
          {
            yCord += 1;
            turn = false;
          }
          break;
        case 4:
          if (seaGrid.filled(xCord+1, yCord+1) == false && (xCord != seaSize-1) && (yCord != seaSize-1))
          {
            xCord += 1;
            yCord += 1;
            turn = false;
          }
          break;
        case 5:
          if (seaGrid.filled(xCord+1, yCord) == false && (xCord != seaSize-1))
          {
            xCord += 1;
            turn = false;
          }
          break;
        case 6:
          if (seaGrid.filled(xCord+1, yCord-1) == false && (xCord != seaSize-1) && (yCord != 0))
          {
            xCord += 1;
            yCord -= 1;
            turn = false;
          }
          break;
        case 7:
          if (seaGrid.filled(xCord, yCord-1) == false && (yCord != 0))
          {
            yCord -= 1;
            turn = false;
          }
          break;
        case 8:
          if (seaGrid.filled(xCord-1, yCord-1) == false && (xCord != 0) && (yCord != 0))
          {
            xCord -= 1;
            yCord -= 1;
            turn = false;
          }
          break;
      }
    }
    if (startX != xCord || startY != yCord)
    {
      health -= 1;
      turn = false;
    }
    seaGrid.replace('P', xCord, yCord);
  }
}

// Description: Finds distance between penguin and a fish
// Precondition: NONE
// Postcondition: Returns the distance between the penguin and the fish
double Penguin::fishDistance(Fish fish, int x, int y)
{
  double dist = sqrt(pow(x - fish.getXCord(),2) + pow(y - fish.getYCord(),2))
  return dist;
}

// Description: Finds distance between penguin and a whale
// Precondition: NONE
// Postcondition: Returns the distance between the penguin and the whale
double Penguin::whaleDist(Killer_Whale whale, int x, int y)
{
  double dist = sqrt(pow(x - whale.getXCord(),2) + pow(y - whale.getYCord(),2))
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
}
