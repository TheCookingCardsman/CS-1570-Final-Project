#ifndef PENGUIN_H
#define PENGUIN_H

class Penguin
{
  public:
    Penguin();
    void move(Sea seaWorld, Fish fishArr[], KillerWhale *whale1, KillerWhale *whale2);
    int getPositionX();
    int getPositionY();
    void setPositionX(int change);
    void setPositionY(int change);
  private:
    int health;
    int positionX;
    int positionY;
    bool alive;
    
    void moveToFish(Sea *seaGrid, Fish fishArr[], int fishIndex, double distance);
    void moveIfBlockedFish(Sea *seaGrid, Fish fishArr[], int fishIndex, double distance);
    double fishDistance(Fish fish, int x, int y);
    double whaleDist(KillerWhale whale, int x, int y);
    int numMoves();
    void moveIfOneWhale(Sea *seaGrid, KillerWhale *whale, double distWhale, Fish fishArr[]);
    void moveIfTwoWhales(Sea *seaGrid, KillerWhale *whale1, KillerWhale *whale2, double distWhale1, double distWhale2, Fish fishArr[]);
    void moveRandom(Sea *seaGrid);
};

#endif