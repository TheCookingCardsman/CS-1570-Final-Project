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

Sea::Sea(short int gridSize)
{
  sizeOfSeaWorld = gridSize;
}

void Sea::clear(Sea &s)
{
  for(int i = 0; i < s.sizeOfSeaWorld; i++)
  {
    for(int j = 0; j < s.sizeOfSeaWorld; j++)
    {
      s.arr[i][j] = '-';
    }
  }
}

void Sea::populate(Penguin arrPeng[], Fish arrFish[], KillerWhale whale1, KillerWhale whale2)
{
  int randWhale1X = rand() % 17;
  int randWhale1Y = rand() % 17;
  whale1.positionX = randWhale1X;
  whale1.positionY = randWhale1Y;
  int randWhale2X = rand() % 17;
  int randWhale2Y = rand() % 17;
  whale2.positionX = randWhale2X;
  whale2.positionY = randWhale2Y;
  for(int i = 0; i < 35; i++)
  {
    int randFishX = rand() % 17;
    int randFishY = rand() % 17;
    arrFish[i].positionX = randFishX;
    arrFish[i].positionY = randFishY;
  }
  for(int j = 0; j < 20; j++)
  {
    int randPengX = rand % 17;
    int randPengY = rand % 17;
    arrPeng[j].positionX = randPengX;
    arrPeng[j].positionY = randPengY;
  }
}

// friend ostream & operator<<(ostream &out, const Sea s)
// {
//   for(int i = 0; i < s.sizeOfSeaWorld; i++)
      //{
      //  for(int j = 0; j < s.sizeOfSeaWorld; j++)
      //  {
      //    out<<s.arr[i][j]<<" ";
      //  }
      //  cout<<endl;
      //}
      //return out;
// }

Penguin::Penguin()
{
  health = rand() % 21 + 60;
  positionX = -1;
  positionY = -1;
  alive = false;
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

void Fish::moveFishGetOutTheWayGetOutTheWayFishGetOutTheWay()
{
  int direction = rand() % 8;

  if(direction % 8 == 0) //north
  {
    positionX = positionX - 1;
  }
  else if(direction % 8 == 1) //east
  {
    positionY = positionY + 1;
  }
  else if(direction % 8 == 2) //south
  {
    positionX = positionX + 1;
  }
  else if(direction % 8 == 3) //west
  {
    positionY = positionY - 1;
  }
  else if(direction % 8 == 4) //north east
  {
    positionX = positionX - 1;
    positionY = positionY + 1;
  }
  else if(direction % 8 == 5) //south east
  {
    positionX = positionX + 1;
    positionY = positionY + 1;
  }
  else if(direction % 8 == 6) //south west
  {
    positionX = positionX + 1;
    positionY = positionY - 1;
  }
  else if(direction % 8 == 7) //north west
  {
    positionX = positionX - 1;
    positionY = positionY - 1;
  }
}

KillerWhale::KillerWhale()
{
  positionX = -1;
  positionY = -1;
  killTally = 0;
}

void KillerWhale::moveFishGetOutTheWayGetOutTheWayFishGetOutTheWay(Penguin &arr[])
{
  //move 3 cells
  Penguin closestPenguin = arr[0];
  for(int i = 0; i < arr.size(); i++)
  {
    if(sqrt(pow(arr[i].positionX - positionX, 2) + pow(arr[i].positionY - positionY, 2)) <= 3 || sqrt(pow(arr[i].positionX - positionX, 2) + pow(arr[i].positionY - positionY, 2)) == sqrt(18))
    {
      positionX = arr[i].positionX;
      positionY = arr[i].positionY;
      killTally++;

      return;
    }
    else
    {
      if(sqrt(pow(arr[i].positionX - positionX, 2) + pow(arr[i].positionY - positionY, 2)) < sqrt(pow(closestPenguin.positionX - positionX, 2) + pow(closestPenguin.positionY - positionY, 2)))
      {
        closestPenguin = arr[i];
      }
    }
  }
  //something about closest penguin and the whale and the whale going towards it idk
  if(positionX < closestPenguin.positionX && positionY < closestPenguin.positionY)
  {
    for(int i = 0; i < 3; i++)
    {

    }
  }
  else if(positionX < closestPenguin.positionX && positionY > closestPenguin.positionY)
  {

  }
  else if(positionX > closestPenguin.positionX && positionY < closestPenguin.positionY)
  {

  }
  else if(positionX > closestPenguin.positionX && positionY > closestPenguin.positionY)
  {

  }
  else if(positionX == closestPenguin.positionX && positionY < closestPenguin.positionY)
  {

  }
  else if(positionX == closestPenguin.positionX && positionY < closestPenguin.positionY)
  {
    
  }
  else if(positionX < closestPenguin.positionX && positionY == closestPenguin.positionY)
  {
    
  }
  else if(positionX > closestPenguin.positionX && positionY == closestPenguin.positionY)
  {
    
  }

  return;
}