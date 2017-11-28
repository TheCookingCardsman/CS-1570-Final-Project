#ifndef KILLER_WHALE_H
#define KILLER_WHALE_H

class Killer_Whale
{
public:
  Killer_Whale();
  void move();
  int getXCord();
  int getYCord();
  
private:
  int xCord;
  int yCord;
  int penguinsEaten;
}