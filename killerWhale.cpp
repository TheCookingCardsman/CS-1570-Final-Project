//Programmers: Allison Chan & Vai Deevi
//Student IDs: 12538820 & 12534907
//Section: D
//Instructor: Dr. Taylor

#include "killerWhale.h"
#include "sea.h"
#include "penguin.h"
#include "fish.h"
#include <iostream>
#include <cmath>
using namespace std;

KillerWhale::KillerWhale()
{
  positionX = -1;
  positionY = -1;
  killTally = 0;
}

int KillerWhale::getPositionX()
{
  return positionX;
}

int KillerWhale::getPositionY()
{
  return positionY;
}

void KillerWhale::setPositionX(int x)
{
  positionX = x;
}

void KillerWhale::setPositionY(int y)
{
  positionY = y;
}

void KillerWhale::moveWhale(Sea &seaGrid, Penguin pengs[], Fish fishies[], int sizeOfPengs, int sizeOfFishies)
{
  //move 3 cells
  
  for(int m = 0; m < 3; m++)
  {
    for(int p = 0; p < sizeOfPengs; p++)
    {
      for(int f = 0; f < sizeOfFishies; f++)
      {
        //if there's a penguin within 3 spaces -- diagonal or straight
        if(sqrt(pow(pengs[p].getPositionX() - getPositionX(), 2) + pow(pengs[p].getPositionY() - getPositionY(), 2)) <= 3 || sqrt(pow(pengs[p].getPositionX() - getPositionX(), 2) + pow(pengs[p].getPositionY() - getPositionY(), 2)) == sqrt(18))
        {
          if(sqrt(pow(pengs[p].getPositionX() - getPositionX(), 2) + pow(pengs[p].getPositionY() - getPositionY(), 2)) <= 3)
          {
            //if the whale is north of the penguin
            if(getPositionX() < pengs[p].getPositionX() && getPositionY() == pengs[p].getPositionY())
            {
              if(getPositionX() == 0 && getPositionY() == 0) //if the whale is in the top left corner
              {
                //if the spot south of the whale is open
                if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot southeast of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()+1);
                } //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                }
              }
              else if(getPositionX() == 0 && getPositionY() == 16) //if the whale is in the top right corner
              {
                //if the spot south of the whale is open
                if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot southwest of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()-1);
                } //if the spot west of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                }
              }
              else
              {
                //if the spot south of the whale is open
                if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot southeast of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()+1);
                } //if the spot southwest of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()-1);
                } //if the spot north of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                } //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                } //if the spot west of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                } //if the spot northwest of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()-1);
                } //if the spot northeast of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()+1);
                }
              }
            } //if the whale is east of the penguin
            else if(getPositionX() == pengs[p].getPositionX() && getPositionY() > pengs[p].getPositionY())
            {
              if(getPositionX() == 0 && getPositionY() == 16) //if the whale is in the top right corner
              {
                //if the spot south of the whale is open
                if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot southwest of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()-1);
                } //if the spot west of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                }
              }
              else if(getPositionX() == 16 && getPositionY() == 16) //if the whale is in the bottom right corner
              {
                //if the spot west of the whale is open
                if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                } //if the spot northwest of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()-1);
                } //if the spot north of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                }
              }
              else
              {
                //if the spot west of the whale is open
                if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                } //if the spot northwest of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()-1);
                } //if the spot southwest of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()-1);
                } //if the spot south of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot north of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                } //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                } //if the spot southeast of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()+1);
                } //if the spot northeast of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()+1);
                }
              }
            } //if the whale is south of the penguin
            else if(getPositionX() > pengs[p].getPositionX() && getPositionY() == pengs[p].getPositionY())
            {
              if(getPositionX() == 16 && getPositionY() == 0) //if the whale is in the bottom left corner
              {
                //if the spot north of the whale is open
                if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                }
                //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                }
                //if the spot northeast of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()+1);
                }
              }
              else if(getPositionX() == 16 && getPositionY() == 16) //if the whale is in the bottom right corner
              {
                //if the spot west of the whale is open
                if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                } //if the spot northwest of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()-1);
                } //if the spot north of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                }
              }
              else
              {
                //if the spot north of the whale is open
                if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                } //if the spot northwest of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()-1);
                } //if the spot northeast of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()+1);
                } //if the spot south of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                } //if the spot west of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                } //if the spot southeast of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()+1);
                } //if the spot southwest of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()-1);
                }
              }              
            } //if the whale is west of the penguin
            else if(getPositionX() == pengs[p].getPositionX() && getPositionY() < pengs[p].getPositionY())
            {
              if(getPositionX() == 0 && getPositionY() == 0) //if the whale is in the top left corner
              {
                //if the spot south of the whale is open
                if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot southeast of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()+1);
                } //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                }
              }
              else if(getPositionX() == 16 && getPositionY() == 0) //if the whale is in the bottom left corner
              {
                //if the spot north of the whale is open
                if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                }
                //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                }
                //if the spot northeast of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()+1);
                }
              }
              else
              {
                //if the spot east of the whale is open
                if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                } //if the spot southeast of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()+1);
                } //if the spot northeast of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()+1);
                } //if the spot south of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot north of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                } //if the spot west of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                } //if the spot southwest of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()-1);
                } //if the spot northwest of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()-1);
                }
              }
            }
          }
          else if(sqrt(pow(pengs[p].getPositionX() - getPositionX(), 2) + pow(pengs[p].getPositionY() - getPositionY(), 2)) == sqrt(18))
          {
            //if the penguin that's 3 away is north east (Q1)
            if(getPositionX() > pengs[p].getPositionX() && getPositionY() < pengs[p].getPositionY())
            {
              if(getPositionX() == 16 && getPositionY() == 0) //if the whale is in the bottom left corner
              {
                //if the spot north of the whale is open
                if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                }
                //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                }
                //if the spot northeast of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()+1);
                }
              }
              else
              {
                //if the spot northeast of the whale is open
                if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()+1);
                } //if the spot north of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                } //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                } //if the spot northwest of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()-1);
                } //if the spot south of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot west of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                } //if the spot southeast of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()+1);
                } //if the spot southwest of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()-1);
                }
              }
            } //if the penguin that's 3 away is south east (Q4)
            else if(getPositionX() < pengs[p].getPositionX() && getPositionY() < pengs[p].getPositionY())
            {
              if(getPositionX() == 0 && getPositionY() == 0) //if the whale is in the top left corner
              {
                //if the spot south of the whale is open
                if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot southeast of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()+1);
                } //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                }
              }
              else
              {
                //if the spot southeast of the whale is open
                if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()+1);
                } //if the spot south of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                } //if the spot southwest of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()-1);
                } //if the spot north of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                } //if the spot west of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                } //if the spot northwest of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()-1);
                } //if the spot northeast of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()+1);
                }
              } 
            } //if the penguin that's 3 away is south west (Q3)
            else if(getPositionX() < pengs[p].getPositionX() && getPositionY() > pengs[p].getPositionY())
            {
              if(getPositionX() == 0 && getPositionY() == 16) //if the whale is in the top right corner
              {
                //if the spot south of the whale is open
                if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot southwest of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()-1);
                } //if the spot west of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                }
              }
              else
              {
                //if the spot southwest of the whale is open
                if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()-1);
                } //if the spot south of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot west of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                } //if the spot southeast of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()+1);
                } //if the spot north of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                } //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                } //if the spot northwest of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()-1);
                } //if the spot northeast of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()+1);
                }
              }
            } //if the penguin that's 3 away is north west (Q2)
            else if(getPositionX() > pengs[p].getPositionX() && getPositionY() > pengs[p].getPositionY())
            {
              if(getPositionX() == 16 && getPositionY() == 16) //if the whale is in the bottom right corner
              {
                //if the spot west of the whale is open
                if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                } //if the spot northwest of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()-1);
                } //if the spot north of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                }
              }
              else
              {
                //if the spot northwest of the whale is open
                if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()-1);
                } //if the spot north of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                } //if the spot west of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()-1);
                } //if the spot northeast of the whale is open
                else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()-1);
                  setPositionY(getPositionY()+1);
                } //if the spot south of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                } //if the spot east of the whale is open
                else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionY(getPositionY()+1);
                } //if the spot southeast of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()+1);
                } //if the spot southwest of the whale is open
                else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                {
                  setPositionX(getPositionX()+1);
                  setPositionY(getPositionY()-1);
                }
              }
            }
          }
        }
        else //if there is no penguin within 3 units
        {
          Penguin closestPenguin = pengs[0];
          //finds the closest penguin
          for(int h = 0; h < sizeOfPengs; h++)
          {
            if(sqrt(pow(pengs[h].getPositionX() - getPositionX(), 2) + pow(pengs[h].getPositionY() - getPositionY(), 2)) < sqrt(pow(closestPenguin.getPositionX() - getPositionX(), 2) + pow(closestPenguin.getPositionY() - getPositionY(), 2)))
            {
              closestPenguin = pengs[h];
            }
          }
          for(int t = 0; t < 3; t++)
          {
            for(int p = 0; p < sizeOfPengs; p++)
            {
              for(int r = 0; r < sizeOfFishies; r++)
              {
                //if the whale is north of the penguin
                if(getPositionX() < closestPenguin.getPositionX() && getPositionY() == closestPenguin.getPositionY())
                {
                  if(getPositionX() == 0 && getPositionY() == 0) //if the whale is in the top left corner
                  {
                    //if the spot south of the whale is open
                    if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot southeast of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()+1);
                    } //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    }
                  }
                  else if(getPositionX() == 0 && getPositionY() == 16) //if the whale is in the top right corner
                  {
                    //if the spot south of the whale is open
                    if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot southwest of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()-1);
                    } //if the spot west of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    }
                  }
                  else
                  {
                    //if the spot south of the whale is open
                    if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot southeast of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()+1);
                    } //if the spot southwest of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()-1);
                    } //if the spot north of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    } //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    } //if the spot west of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    } //if the spot northwest of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()-1);
                    } //if the spot northeast of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()+1);
                    }
                  }              
                } //if the whale is east of the penguin
                else if(getPositionX() == closestPenguin.getPositionX() && getPositionY() > closestPenguin.getPositionY())
                {
                  if(getPositionX() == 0 && getPositionY() == 16) //if the whale is in the top right corner
                  {
                    //if the spot south of the whale is open
                    if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot southwest of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()-1);
                    } //if the spot west of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    }
                  }
                  else if(getPositionX() == 16 && getPositionY() == 16) //if the whale is in the bottom right corner
                  {
                    //if the spot west of the whale is open
                    if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    } //if the spot northwest of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()-1);
                    } //if the spot north of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    }
                  }
                  else
                  {
                    //if the spot west of the whale is open
                    if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    } //if the spot northwest of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()-1);
                    } //if the spot southwest of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()-1);
                    } //if the spot south of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot north of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    } //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    } //if the spot southeast of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()+1);
                    } //if the spot northeast of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()+1);
                    }
                  }
                } //if the whale is south of the penguin
                else if(getPositionX() > closestPenguin.getPositionX() && getPositionY() == closestPenguin.getPositionY())
                {
                  if(getPositionX() == 16 && getPositionY() == 0) //if the whale is in the bottom left corner
                  {
                    //if the spot north of the whale is open
                    if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    }
                    //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    }
                    //if the spot northeast of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()+1);
                    }
                  }
                  else if(getPositionX() == 16 && getPositionY() == 16) //if the whale is in the bottom right corner
                  {
                    //if the spot west of the whale is open
                    if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    } //if the spot northwest of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()-1);
                    } //if the spot north of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    }
                  }
                  else
                  {
                    //if the spot north of the whale is open
                    if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    } //if the spot northwest of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()-1);
                    } //if the spot northeast of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()+1);
                    } //if the spot south of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    } //if the spot west of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    } //if the spot southeast of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()+1);
                    } //if the spot southwest of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()-1);
                    }
                  }
                } //if the whale is west of the penguin
                else if(getPositionX() == closestPenguin.getPositionX() && getPositionY() < closestPenguin.getPositionY())
                {
                  if(getPositionX() == 0 && getPositionY() == 0) //if the whale is in the top left corner
                  {
                    //if the spot south of the whale is open
                    if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot southeast of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()+1);
                    } //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    }
                  }
                  else if(getPositionX() == 16 && getPositionY() == 0) //if the whale is in the bottom left corner
                  {
                    //if the spot north of the whale is open
                    if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    }
                    //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    }
                    //if the spot northeast of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()+1);
                    }
                  }
                  else
                  {
                    //if the spot east of the whale is open
                    if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    } //if the spot southeast of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()+1);
                    } //if the spot northeast of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()+1);
                    } //if the spot south of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot north of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    } //if the spot west of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    } //if the spot southwest of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()-1);
                    } //if the spot northwest of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()-1);
                    }
                  }
                } //if the penguin that's 3 away is north east (Q1)
                else if(getPositionX() > closestPenguin.getPositionX() && getPositionY() < closestPenguin.getPositionY())
                {
                  if(getPositionX() == 16 && getPositionY() == 0) //if the whale is in the bottom left corner
                  {
                    //if the spot north of the whale is open
                    if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    }
                    //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    }
                    //if the spot northeast of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()+1);
                    }
                  }
                  else
                  {
                    //if the spot northeast of the whale is open
                    if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()+1);
                    } //if the spot north of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    } //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    } //if the spot northwest of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()-1);
                    } //if the spot south of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot west of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    } //if the spot southeast of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()+1);
                    } //if the spot southwest of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()-1);
                    }
                  }
                } //if the penguin that's 3 away is south east (Q4)
                else if(getPositionX() < closestPenguin.getPositionX() && getPositionY() < closestPenguin.getPositionY())
                {
                  if(getPositionX() == 0 && getPositionY() == 0) //if the whale is in the top left corner
                  {
                    //if the spot south of the whale is open
                    if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot southeast of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()+1);
                    } //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    }
                  }
                  else
                  {
                    //if the spot southeast of the whale is open
                    if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()+1);
                    } //if the spot south of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    } //if the spot southwest of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()-1);
                    } //if the spot north of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    } //if the spot west of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    } //if the spot northwest of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()-1);
                    } //if the spot northeast of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()+1);
                    }
                  }
                } //if the penguin that's 3 away is south west (Q3)
                else if(getPositionX() < closestPenguin.getPositionX() && getPositionY() > closestPenguin.getPositionY())
                {
                  if(getPositionX() == 0 && getPositionY() == 16) //if the whale is in the top right corner
                  {
                    //if the spot south of the whale is open
                    if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot southwest of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()-1);
                    } //if the spot west of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    }
                  }
                  else
                  {
                    //if the spot southwest of the whale is open
                    if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()-1);
                    } //if the spot south of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot west of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    } //if the spot southeast of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()+1);
                    } //if the spot north of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    } //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    } //if the spot northwest of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()-1);
                    } //if the spot northeast of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()+1);
                    }
                  }
                } //if the penguin that's 3 away is north west (Q2)
                else if(getPositionX() > closestPenguin.getPositionX() && getPositionY() > closestPenguin.getPositionY())
                {
                  if(getPositionX() == 16 && getPositionY() == 16) //if the whale is in the bottom right corner
                  {
                    //if the spot west of the whale is open
                    if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    } //if the spot northwest of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()-1);
                    } //if the spot north of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    }
                  }
                  else
                  {
                    //if the spot northwest of the whale is open
                    if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()-1);
                    } //if the spot north of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY() != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                    } //if the spot west of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX() != fishies[r].getPositionX() && getPositionY()-1 != fishies[r].getPositionY())
                    {
                      setPositionY(getPositionY()-1);
                    } //if the spot northeast of the whale is open
                    else if(getPositionX()-1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()-1 != fishies[r].getPositionX() && getPositionY()+1 != fishies[r].getPositionY())
                    {
                      setPositionX(getPositionX()-1);
                      setPositionY(getPositionY()+1);
                    } //if the spot south of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY() != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY() != fishies[f].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                    } //if the spot east of the whale is open
                    else if(getPositionX() != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX() != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                    {
                      setPositionY(getPositionY()+1);
                    } //if the spot southeast of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()+1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()+1 != fishies[f].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()+1);
                    } //if the spot southwest of the whale is open
                    else if(getPositionX()+1 != pengs[p].getPositionX() && getPositionY()-1 != pengs[p].getPositionY() && getPositionX()+1 != fishies[f].getPositionX() && getPositionY()-1 != fishies[f].getPositionY())
                    {
                      setPositionX(getPositionX()+1);
                      setPositionY(getPositionY()-1);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    seaGrid.place('W', getPositionX(), getPositionY());
  }
  return;
}