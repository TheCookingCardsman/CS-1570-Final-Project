#ifndef KILLERWHALE_H
#define KILLERWHALE_H
class Penguin;

class KillerWhale
{
  private:
    int positionX;
    int positionY;
    int killTally;
  public:
    KillerWhale();
    int getPositionX();
    int getPositionY();
    void setPositionX(int change);
    void setPositionY(int change);
    void moveFishGetOutTheWayGetOutTheWayFishGetOutTheWay(Penguin arr[], int size);
};

#endif