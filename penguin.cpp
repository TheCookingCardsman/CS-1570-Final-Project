#include "penguin.h"
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

void Penguin::move(Sea seaArr[], Fish fishArr[], Killer_Whale *whale1, Killer_Whale *whale2)
{
  // First check to see if whale is near by. Same code for. If whale exists or fish and whale exist
  if (sqrt(pow(xCord - whale1.getXCord(),2) + pow(yCord - whale1.getYCord(),2)) <= 8 && sqrt(pow(xCord - whale1.getXCord(),2) + pow(yCord - whale1.getYCord(),2)) <= 8) // Both whales within 8 units
  {

  } 
  else if (sqrt(pow(xCord - whale1.getXCord(),2) + pow(yCord - whale1.getYCord(),2)) <= 8) // Only whale1 is within 8 units
  {

  }
  else if (sqrt(pow(xCord - whale1.getXCord(),2) + pow(yCord - whale1.getYCord(),2)) <= 8) // Only whale2 is within 8 units
  {

  }
  else // Check to see if at least one fish exists fish within 8 units. The index number of the closest fish is saved.
  {
    int closeFish = -1; // Index of the closest fish. By default set to -1, based on the assumption no fish is within 8 units to start.
    int distance = 8; // The distance between the penguin and the closest fish. By default set to 8.
    for (int i = 0; i < fishArr.size(); i++) // Cycling through all fish in the array
    {
      if (sqrt(pow(xCord - fishArr[i].getXCord(),2) + pow(yCord - fishArr[i].getYCord(),2)) <= 8) // Checking to see if 
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
      moveToFish(closeFish, seaArr[], fishArr[], health); // Function to move the penguin closer to the closest fish. IN PROGRESS
    }
  }
}

void Penguin::moveToFish(int closeFish, Sea seaArr[], Fish fishArr[], health)
{
  if (fishArr[closeFish].getXCord() > xCord && fishArr[closeFish].getYCord() > yCord)
  {
    xCord += 1;
    yCord += 1;
  }
  else if ()
  {

  }
  else if()
  {

  }


}
