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
      allStations[i].name = i;
  }
  BikePtr a = NewBike("NTHU0", 10, Lady, allStations[mp["Jingmei"]], "Jingmei");
  cout << a->Cursor << "," << a->Station << endl;
  allStations[mp["Jingmei"]].HLady.show();
  cout << allStations[mp["Jingmei"]].HLady.Number;

  // cout << endl;
/*
  string cmd;
  while(testCaseIn >> cmd) {
    if(cmd == "NewBike")
    {




    }

    fileOut << "..." << endl;
  }*/


}
