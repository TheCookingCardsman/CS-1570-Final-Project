#ifndef FISH_H
#define FISH_H

class Fish
{
  private:
    int foodValue;
    int positionX;
    int positionY;
    bool alive;
  public:
    Fish();
    int getPositionX();
    int getPositionY();
    void setPositionX(int change);
    void setPositionY(int change);
    void moveFishGetOutTheWayGetOutTheWayFishGetOutTheWay();
};

#endif