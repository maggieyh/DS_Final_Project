
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
extern ofstream fileOut;

//HeapType
HeapType::HeapType()
{
  Number = 0;
  memset(Elem, 0, sizeof(BikePtr) * 256);
}
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
int HeapType::Search(const BikePtr bike)
{
  int i = 1;
  for(; i <= Number; i++) {
    if(Elem[i] == bike)
      break;
  }
  return i;
}
void HeapType::Delete(BikePtr bike)
{
  int toBeDelete = Search(bike);
  if(Number != 0)
  {
    int lastB = Number;
    if(toBeDelete <= Number) {
      //found
      if(lastB == toBeDelete) {
        Elem[lastB] = NULL;
        Number--;
      } else {
        //bubble up
        int currentNode = toBeDelete;
        while(currentNode != 1 && Elem[currentNode / 2]->Mileage < Elem[lastB]->Mileage)
        {
          Elem[currentNode] = Elem[currentNode/2];
          currentNode /= 2;
        }
        Elem[currentNode] = Elem[lastB];

        //bubble down
        int child = currentNode * 2;
        while(child <= Number - 1 )
        {
          if(child < Number - 1 && Elem[child]->Mileage < Elem[child + 1]->Mileage) child++;

          if(Elem[lastB]->Mileage >= Elem[child]->Mileage) break;

          Elem[currentNode] = Elem[child];
          currentNode = child;
          child *= 2;
        }
        Elem[currentNode] = Elem[lastB];
        Elem[lastB] = NULL;
        Number--;


      }

    }

  }
}

void HeapType::show()
{

  for(int i = 1; i <= Number; i++)
    std::cout << Elem[i]->Mileage << " ";
  std::cout << std::endl;
}
