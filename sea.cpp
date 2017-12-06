#include <iostream>
#include "sea.h"
#include "penguin.h"
#include "fish.h"
#include "killerWhale.h"
using namespace std;

// Description: Assigns size of sea world to be default maximum of 25 
// Precondition: 
// Postcondition:    
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

// Description: Overloads insertion operator to print out sea grid 
// Precondition: 
// Postcondition: 
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