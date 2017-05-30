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
  HeapType a;
  BikeType b1,b2,b3,b4;

  // a.Push()
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
