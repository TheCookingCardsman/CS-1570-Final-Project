#ifndef FISH_H
#define FISH_H

class Fish
{
public:
  Fish();
  void move();
  int getXCord();
  int getYCord();
private: 
  int food;
  int xCord;
  int yCord;
  bool alive;
};

#endi