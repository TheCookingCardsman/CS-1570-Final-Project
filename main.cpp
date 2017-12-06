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
  for(int i = 0; i < 15; i++)
  {
    usleep(20000);
    cout<<seaWorld<<endl;
  }
  

  return 0;
}