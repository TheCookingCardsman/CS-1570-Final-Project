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
#include "sea.h"
#include "fish.h"
#include "killerWhale.h"
#include "penguin.h"
using namespace std;

int main()
{
  srand(time(NULL));

  
  //bool takenSpace[MAX][MAX];
  Penguin penguinos[50];
  KillerWhale orca1;
  KillerWhale orca2;
  Fish fishies[200];
  Sea seaWorld(17, penguinos, fishies, orca1, orca2);
  /*for(int i = 0; i < takenSpace.size(); i++)
  {
    for(int j = 0; j < takenSpace[0].size(); i++)
    {
      takenSpace[i][j] = false;
    }
  }*/
  cout<<seaWorld<<endl;
  cout<<orca1.getPositionX()<<endl;
  cout<<orca1.getPositionY()<<endl;
  cout<<orca2.getPositionX()<<endl;
  cout<<orca2.getPositionY()<<endl;
  for(int i = 0; i < 15; i++)
  {
    for(int g = 0; g < 200; g++)
    {
      fishies[g].moveFish(seaWorld);
    }
    usleep(20000);
    cout<<seaWorld<<endl;
    for(int l = 0; l < 50; l++)
    {
      penguinos[l].movePeng(seaWorld, fishies, orca1, orca2);
    }
    usleep(20000);
    cout<<seaWorld<<endl;
    orca1.moveWhale(seaWorld, penguinos, fishies, 50, 200);
    usleep(20000);
    cout<<seaWorld<<endl;
    orca2.moveWhale(seaWorld, penguinos, fishies, 50, 200);
    usleep(20000);
    cout<<seaWorld<<endl;
  }
  

  return 0;
}