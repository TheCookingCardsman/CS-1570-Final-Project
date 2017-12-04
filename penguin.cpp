#include "penguin.h"
#include "fish.h"
#include "killer_whale.h"
#include "sea.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

// BIG PROBLEM: HOW TO CODE FOR THE AMOUNT OF TIMES THE PENGUIN IS MOVING ACCURATELY BY STILL UPDATING EVERYTHING AFTER EACH TURN??

Penguin::Penguin()
{
  health = ((rand() % 20) + 1) + 60;  
  alive = false;
  xCord = -1; 
  yCord = -1;
}

// Description: 
// Precondition: 
// Postcondition: 
void Penguin::move(Sea seaArr[], Fish fishArr[], Killer_Whale *whale1, Killer_Whale *whale2)
{
  // First check to see if whale is near by. Same code for whether a whale exists or fish and whale exist
  if (sqrt(pow(xCord - whale1.getXCord(),2) + pow(yCord - whale1.getYCord(),2)) <= 8 && sqrt(pow(xCord - whale1.getXCord(),2) + pow(yCord - whale1.getYCord(),2)) <= 8) // Both whales within 8 units
  {
    moveIfTwoWhales(seaArr[], whale1, whale2);
  } 
  else if (sqrt(pow(xCord - whale1.getXCord(),2) + pow(yCord - whale1.getYCord(),2)) <= 8) // Only whale1 is within 8 units
  {
    moveIfOneWhale(seaArr[], whale1);
  }
  else if (sqrt(pow(xCord - whale2.getXCord(),2) + pow(yCord - whale2.getYCord(),2)) <= 8) // Only whale2 is within 8 units
  {
    moveIfOneWhale(seaArr[], whale2);
  }
  else // Check to see if at least one fish exists fish within 8 units. The index number of the closest fish is saved.
  {
    int closeFish = -1; // Index of the closest fish. By default set to -1, based on the assumption no fish is within 8 units to start.
    double distance = 8.0; // The distance between the penguin and the closest fish. By default set to 8.
    
    for (int i = 0; i < fishArr.size(); i++) // Cycling through all fish in the array
    {
      if (sqrt(pow(xCord - fishArr[i].getXCord(),2) + pow(yCord - fishArr[i].getYCord(),2)) <= 8) // Checking to see if the fish is within 8 units 
      {
        if (distance > sqrt(pow(xCord - whale1.getXCord(),2) + pow(yCord - whale1.getYCord(),2)));
        {
          distance = sqrt(pow(xCord - whale1.getXCord(),2) + pow(yCord - whale1.getYCord(),2));
          closeFish = i;
        }
      }
    }

    if (closeFish > 0) 
    {
      moveToFish(closeFish, seaArr[], fishArr[]); // Function to move the penguin closer to the closest fish. IN PROGRESS
    }                                                                                                                                                                                   
  }
}

//-------------------------------------------------------------------------------------------------------
// Description: Moves penguin a designated number of times towards the closest fish available
// Precondition: 
// Postcondition: 

// NOTE: CURRENTLY NOT CODED TO HANDLE INTERFERING PENGUINS AND STOPPING PENGUIN MOVEMENT WHEN FISH IS EATEN
void Penguin::moveToFish(int closeFish, Sea seaArr[], Fish fishArr[])
{
  int loopNum = numMoves()
  
  for (int i = 0; i < loopNum; i++)
  {
    if (xCord != fishArr[closeFish].getXCord() && yCord != fishArr[closeFish].getYCord())
    {
      if (fishArr[closeFish].getXCord() < xCord && fishArr[closeFish].getYCord() > yCord)
      {
        xCord -= 1;
        yCord += 1;
      }
      else if (fishArr[closeFish].getXCord() > xCord && fishArr[closeFish].getYCord() > yCord)
      {
        xCord += 1;
        yCord += 1;
      }
      else if (fishArr[closeFish].getXCord() < xCord && fishArr[closeFish].getYCord() < yCord)
      {
        xCord -= 1;
        yCord -= 1;
      }
      else if (fishArr[closeFish].getXCord() > xCord && fishArr[closeFish].getYCord() < yCord)
      {
        xCord += 1;
        yCord -= 1;
      }
    }
    else
    {
      if (xCord == fishArr[closeFish].getXCord())
      {
        if (fishArr[closeFish].getYCord() < yCord)
        {
          yCord -= 1;
        }
        else if (fishArr[closeFish].getYCord() > yCord)
        {
          yCord += 1;
        }
      }
      else if (yCord == fishArr[closeFish].getYCord())
      {
        if (fishArr[closeFish].getXCord() > xCord)
        {
          xCord += 1;
        }
        else if(fishArr[closeFish].getXCord() < xCord) 
        {
          xCord -= 1;
        }
      }
    }
  }
}

//-------------------------------------------------------------------------------------------------------

// Description: 
// Precondition: 
// Postcondition: 

// NOTE: CURRENTLY NOT CODED TO HANDLE INTERFERING PENGUINS 
void Penguin::moveIfOneWhale(Sea seaArr[], Killer_Whale *whale)
{
  if (whale.getXCord() == xCord)
  {
    if (whale.getYcord() < yCord)
    {
      yCord += 1;
    }
    else if (whale.getYCord() > yCord)
    {
      yCord -= 1;
    }
  }
  else if (whale.getYCod() == yCord)
  {
    if (whale.getXcord() < xCord)
    {
      xCord += 1;
    }
    else if (whale.getXCord() > xCord)
    {
      xCord -= 1;
    }
  }
  else if ((whale.getXCord() > xCord && whale.getYCord() > yCord) || (whale.getXCord() < xCord && whale.getYCord() > yCord))
  {
    yCord -= 1;
  }
  else if ((whale.getXCord() < xCord && whale.getYCord() < yCord) || (whale.getXCord() > xCord && whale.getYCord() < yCord))
  {
    yCord += 1;
  }
}

//-------------------------------------------------------------------------------------------------------

// Description: 
// Precondition: 
// Postcondition: 
void moveIfTwoWhales(Sea seaArr[], Killer_Whale *whale1, Kille_Whale *whale2)
{
  if (whale1.getXCord() < xCord && whale2.getXCord() < xCord)
  {
    xCord += 1;
  }
  else if (whale1.getXCord() > xCord && whale2.getXCord() > xCord)
  {
    xCord -= 1;
  }
  else if (whale1.getXCord() == xCord && whale2.getXCord() == xCord)
  {
    xCord += 1; // Code code be going up or down based on prefrence
  }
  else if ((whale1.getXCord() < xCord && whale1.getYCord() < yCord && whale2.getXCord() > xCord && whale2.yCord() > yCord) || (whale2.getXCord() < xCord && whale2.getYCord() < yCord && whale1.getXCord() > xCord && whale1.yCord() > yCord))
  {
    xCord -= 1;
    yCord += 1; 
    // Coded to go diagonal to the right upward. Can be coded to go left as well
  }
  else if ((whale1.getXCord() > xCord && whale1.getYCord() < yCord && whale2.getXCord() < xCord && whale2.yCord() > yCord) || (whale2.getXCord() < xCord && whale2.getYCord() < yCord && whale1.getXCord() > xCord && whale1.yCord() > yCord))
  {
    xCord += 1;
    yCord += 1;
    // Coded to go diagional to the right downward. Can be coded to go left as well
  }
  else if ((whale1.getXCord() == yCord && whale2.getYCord() > yCord) || (whale2.getXCord() == yCord && whale1.getYCord() > yCord))
  {
    yCord -= 1;
  }
  else if ((whale1.getXCord() == yCord && whale2.getYCord < yCord) || (whale2.getXCord() == yCord && whale1.getYCord() < yCord))
  {
    yCord += 1;
  }
  else if ()
}

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
