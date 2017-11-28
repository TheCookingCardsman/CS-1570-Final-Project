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

// pass by reference?
void Penguin::move(Sea seaArr[], Fish fishArr[], Killer_Whale whale1, Killer_Whale whale2)
{
  
}