#ifndef PENGUIN_H
#define PENGUIN_H

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
  void moveToFish(closeFish, seaArr[], fishArr[]);
  void moveIfOneWhale(Sea seaArr[], Killer_Whale *whale); 
}
