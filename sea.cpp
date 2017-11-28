#include <iostream>
#include "sea.h"
#include "penguin.h"
#include "fish.h"
#include "killer_whale.h"
using namespace std;

// Description: Assigns size of sea world to be default maximum of 25 
// Precondition: 
// Postcondition:    
Sea::Sea(const short gridSize, Penguin pengArr[], Fish fishArr[], Killer_Whale *whale1, Killer_Whale *whale2)
{
  seaWorldSize = gridSize;
  clear();
  populate(pengArr[], fishArr[], whale1, whale2);
}

// Description: Overloads insertion operator to print out sea grid 
// Precondition: 
// Postcondition: 
ostream& operator<<(ostream &os, Sea &s);
{
  for (int i = 0; i < s.seaWorldSize; i++)
  {
    for (int j = 0; j < s.seaWorldSize; j++)
    {
      out << s.seaWorld[i][j] << endl;
    }
  }  
  return os;
}

Sea::clear()
{

}

Sea::populate(Penguin pengArr[], Fish fishArr[], Killer_Whale *whale1, Killer_Whale *whale2)
{
  
}

// Accessor and Mutator functions