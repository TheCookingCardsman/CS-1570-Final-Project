#ifndef PENGUIN_H
#define PENGUIN_H

// Do you want a two seperate coordinates or a struct? Your Choice.
class Penguin 
{
public: 
  Penguin();
  void move(Sea seaArr[], Fish fishArr[]);
private:
  int health;
  int xCord;
  int yCord;
  bool alive;
  void fishMove();
  void whaleMove();
  char closestAnimal();  
}