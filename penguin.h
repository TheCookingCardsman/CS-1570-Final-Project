#ifndef PENGUIN_H
#define PENGUIN_H

class Penguin
{
public:
  Penguin();
  void move(Sea seaWorld, Fish fishArr[], Killer_Whale *whale1, Killer_Whale *whale2);
private:
  int health;
  int xCord;
  int yCord;
  bool alive;

  void moveToFish(Sea *seaGrid, Fish fishArr[], int fishIndex, double distance);
  void moveIfBlockedFish(Sea *seaGrid, Fish fishArr[], int fishIndex, double distance);
  double fishDistance(Fish fish, int x, int y);
  double whaleDist(Killer_Whale whale, int x, int y);
  int numMoves();
  void moveIfOneWhale(Sea *seaGrid, Killer_Whale *whale, double distWhale, Fish fishArr[]);
  void moveIfTwoWhales(Sea *seaGrid, Killer_Whale *whale1, Kille_Whale *whale2, double distWhale1, double distWhale2, Fish fishArr[]);
  void moveRandom(Sea *seaGrid);
}
