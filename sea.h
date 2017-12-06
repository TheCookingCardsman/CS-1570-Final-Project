#ifndef SEA_H
#define SEA_H

class Sea
{
  private: 
    char arr[25][25];
    short sizeOfSeaWorld;
    void clear(Sea &s);
    void populate(Penguin arrPeng[], Fish arrFish[], KillerWhale whale1, KillerWhale whale2);
  public:
    Sea(short gridSize, Penguin arrPeng[], Fish arrFish[], KillerWhale whale1, KillerWhale whale2);


    friend ostream & operator<<(ostream &out, Sea s);
};

#endif