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
  //argv[2] is the name of map fileOut
  //argv[3] is the name of output fileOut
  fileOut.open(argv[3], ifstream::out);
  mapIn.open(argv[2], ifstream::in);
  testCaseIn.open(argv[1], ifstream::in);
  BikePtr garage[10];
  for(int i = 0; i < 10; i++)
    garage[i] = new BikeType();
  garage[0]->License = "0579A";
  garage[1]->License = "01B2F";
  garage[2]->License = "AAAA1";
  garage[3]->License = "BE51O";
  garage[4]->License = "A0001";
  garage[5]->License = "A00Z0";
  _BST aTree;
  aTree.ins(garage[0]);
  aTree.show(aTree.root);
/*
  string s, t, dist;
  StationType allStations[12];

  while(mapIn >> s >> t >> dist)
  {
    stringstream ss(dist);
    ss >> lengthMap[mp[s]][mp[t]];
    lengthMap[mp[t]][mp[s]] = lengthMap[mp[s]][mp[t]];
    dp[mp[s]][mp[t]] = lengthMap[mp[s]][mp[t]];
    dp[mp[t]][mp[s]] = lengthMap[mp[s]][mp[t]];
  }

  //all pair shortest path
  for(int k = 0; k < 12; k++) {
    for(int i = 0; i < 12; i++) {
      for(int j = 0; j < 12; j++) {
        if(dp[i][k] + dp[k][j] < dp[i][j])
          dp[i][j] = dp[i][k] + dp[k][j];
      }
    }
  }

*/
/*
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
