#ifndef SEA_H
#define SEA_H

class Sea
{
public:
  Sea(const short gridSize);
  friend ostream& operator<<(ostream &os, Sea &s);
  // Accessor and Mutator functions as needed go here
private: 
  char seaWorld[25][25]; // Array representing the sea 
  short seaWorldSize; // Actual size of sea world. Must be less than 25
  //Add any other member variables as needed
  void clear(); // Clears the entire sea
  void populate(Penguin pengArr[], Fish fishArr[],); // Place fish, penguins, and whales onto sea grid
};

#endif