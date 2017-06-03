#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <map>
#include <sstream>
#include <iomanip>
#include "function.h"
#include "heap.cpp"
#include "station.cpp"
#include "bst.cpp"
using namespace std;
ifstream testCaseIn, mapIn;
ofstream fileOut;
int main(int argc, char * argv[]) {
  //argv[1] is the name of the transaction file
  //argv[2] is the name of map
  //argv[3] is the name of output fileOut
  fileOut.open(argv[3], ifstream::out);
  mapIn.open(argv[2], ifstream::in);
  testCaseIn.open(argv[1], ifstream::in);

  string s, t, dist;
  for(int i = 0; i < 12; i++){
    memset(dp[i], 0x3f3f3f, 12 * sizeof(int));
    dp[i][i] = 0;
  }
  while(mapIn >> s >> t >> dist)
  {
    stringstream ss(dist);
    ss >> lengthMap[mp[s]][mp[t]];
    lengthMap[mp[t]][mp[s]] = lengthMap[mp[s]][mp[t]];
    dp[mp[s]][mp[t]] = lengthMap[mp[s]][mp[t]];
    dp[mp[t]][mp[s]] = lengthMap[mp[s]][mp[t]];
  }
  shortestPath();
  for(int i = 0; i < 12; i++) {
      allStations[i] = StationType();
  }


  string cmd, stationName, classOfBike;
  int mile;
  StationName nm;
  LicenseType License;
  ClassType Class;
  while(testCaseIn >> cmd) {
    if(cmd == "NewBike") {
      testCaseIn >> classOfBike >> License >> mile >> stationName;
      fileOut << "New bike is received by Station " << stationName << ".\n";
      NewBike(License, mile, mpclass[classOfBike], allStations[mp[stationName]], stationName);
    }

    if(cmd == "JunkIt") {
      testCaseIn >> License;
      fileOut << "Bike " << License;
      int r = JunkBikePtr(License);
      if(r == -1)
          fileOut << " does not belong to our company.\n";
      else if (r == -2)
          fileOut << " is now being rented.\n";
      else
          fileOut << " is deleted from " << namesOfStations[r] << ".\n";
    }


    if(cmd == "Rent") {
      testCaseIn >> stationName >> classOfBike;
      if(RentBikePtr(stationName, mpclass[classOfBike]))
        fileOut << "A bike is rented from " << stationName << ".\n";
      else
        fileOut << "No free bike is available.\n";
    }
    if(cmd == "Trans") {
      testCaseIn >> stationName >> License;
      int r = TransBikePtr(stationName, License);
      if(r == 0)
        fileOut << "Bike " << License << " does not belong to our company.\n";
      else if(r == 1)
        fileOut << "Bike " << License << " is now being rented.\n";
      else
        fileOut << "Bike " << License << " is transferred to " << stationName << ".\n";

    }

    if(cmd == "Inquire") {
      testCaseIn >> License;
      BikePtr p = SearchBike(License);
      if(p == NULL)  fileOut << "Bike " << License << " does not belong to our company.\n";
      else {
        fileOut << "        License        Mileage          Class        Station\n";
        fileOut << "============================================================\n";
        fileOut << setw(15) << License << setw(15) << p->Mileage << setw(15) << bclassnames[p->Class] << setw(15) << namesOfStations[p->Station] << endl << endl;
      }

    }

    if(cmd == "StationReport") {
      testCaseIn >> stationName;
      fileOut << setw(30) << stationName << endl;
      fileOut << "                    Free Bikes\n";
      fileOut << "        License        Mileage          Class        Station\n";
      fileOut << "============================================================\n";

    }

    if(cmd == "BReport") {
      fileOut << "Binary Search Tree\n";
      bikeBST.preord();
      fileOut << endl;
      bikeBST.inord();
      fileOut << endl;
    }
  }


}
