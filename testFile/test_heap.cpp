// Name: test Heap
// Date: 2017-06-02
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <map>
#include <sstream>
#include "function.h"
#include "heap.cpp"
#include "station.cpp"
#include "bst.cpp"
using namespace std;
ifstream testCaseIn, mapIn;
ofstream fileOut;
int main(int argc, char * argv[]) {

  HeapType a;
  BikePtr temp, b[10];
  b[0] = new BikeType();
  b[0]->Mileage = 50;
  a.Push(b[0]);
  a.show();
  b[1] = new BikeType();
  b[1]->Mileage = 20;
  a.Push(b[1]);
  a.show();
  b[2] = new BikeType();
  b[2]->Mileage = 30;
  a.Push(b[2]);
  a.show();
  b[3] = new BikeType();
  b[3]->Mileage = 19;
  a.Push(b[3]);
  a.show();
  b[4] = new BikeType();
  b[4]->Mileage = 19;
  a.Push(b[4]);
  a.show();
  b[5] = new BikeType();
  b[5]->Mileage = 8;
  a.Push(b[5]);
  a.show();

  a.Delete(b[1]);
  a.show();

}
