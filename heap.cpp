// #include "function.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
extern ofstream fileOut;

//HeapType
BikePtr HeapType::Top() const
{
  if(Number != 0)  return Elem[1];
  else             return NULL;
}

void HeapType::Push(const BikePtr bike)
{
  Number++;
  int currentNode = Number;
  while(currentNode != 1 && Elem[currentNode / 2]->Mileage < bike->Mileage) {
    Elem[currentNode] = Elem[currentNode/2];
    currentNode /= 2;
  }
  Elem[currentNode] = bike;
}
//Pop top
void HeapType::Delete(BikePtr bike)
{
  int toBeDelete;
  if(Number != 0)
  {
    BikePtr lastB = Elem[Number];
    Number--;
    for(toBeDelete = 1; toBeDelete <= Number; toBeDelete++)
      if(Elem[toBeDelete] == bike)
        break;
    if(toBeDelete <= Number) {
      //found


    }

  }
}
