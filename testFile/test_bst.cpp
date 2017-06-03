// Name: test BST
// Date: 2017-06-02
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <map>
#include <sstream>
#include "../function.h"
#include "../heap.cpp"
#include "../station.cpp"
#include "../bst.cpp"
using namespace std;
ifstream testCaseIn, mapIn;
ofstream fileOut;
int main(int argc, char * argv[]) {

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
  aTree.ins(garage[1]);
  aTree.ins(garage[2]);
  aTree.ins(garage[3]);
  aTree.ins(garage[4]);
  aTree.ins(garage[5]);
  aTree.preord();
  cout << endl;
  aTree.inord();
  
  // aTree.del(garage[3]);
  // aTree.show(aTree.root);
  // cout << endl;
  aTree.del(garage[2]);
  aTree.show(aTree.root);
  if(aTree.search("AAAA1") != NULL)
    cout << "who~";

}
