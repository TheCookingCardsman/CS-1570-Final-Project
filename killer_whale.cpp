#include "killer_whale.h"
#include <iostream>
using namespace std;

Killer_Whale::Killer_Whale()
{
  penguinsEaten = 0;
}

Killer_Whale::move() // Penguin Array or Sea can be passed in 
{
  // Move 3 cells
  // Always seek out closest penguin

}

int Killer_Whale::getXCord()
{
  return xCord;
}

int Killer_Whale::getYCord()
{
  return yCord;
}

// Other functions that may be needed in order to add to the kill tally