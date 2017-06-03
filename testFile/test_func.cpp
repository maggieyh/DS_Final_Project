// Name: test func
// Date: 2017-06-03
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

  BikePtr a = NewBike("NTHU0", 10, Lady, allStations[mp["Jingmei"]], "Jingmei");
  cout << "," << a->Station << endl;
  allStations[mp["Jingmei"]].HLady.show();
  cout << allStations[mp["Jingmei"]].HLady.Number << endl;
  TransBikePtr("Hongshulin", "NTHU0");
  cout <<" trans--------" << endl;
  cout <<  "," << a->Station << endl;
  allStations[mp["Jingmei"]].HLady.show();
  cout << allStations[mp["Jingmei"]].HLady.Number << endl;

  allStations[mp["Hongshulin"]].HLady.show();
  cout << allStations[mp["Hongshulin"]].HLady.Number << endl;
  cout <<"--------" << endl;

  JunkBikePtr("NTHU0");
  allStations[mp["Jingmei"]].HLady.show();
  cout << allStations[mp["Jingmei"]].HLady.Number << endl;
  cout << endl;
  bikeBST.show(bikeBST.root);
}
