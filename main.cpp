#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include "function.h"
#include "heap.cpp"
#include "station.cpp"
using namespace std;
ifstream testCaseIn, mapIn;
ofstream fileOut;

int main(int argc, char * argv[]) {
  //argv[1] is the name of the transaction file
  //argv[2] is the name of map fileOut
  //argv[3] is the name of output fileOut
  fileOut.open(argv[3], ifstream::out);
  mapIn.open(argv[2], ifstream::in);
  testCaseIn.open(argv[1], ifstream::in);

  string s, t, dist;
  StationType allStations[12];


  /*while(mapIn >> s >> t >> dist)
  {



  }

  string cmd;
  while(testCaseIn >> cmd) {
    if(cmd == "NewBike")
    {




    }

    fileOut << "..." << endl;
  }*/


}



/*
//test heap
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
*/
