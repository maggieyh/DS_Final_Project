
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
extern ofstream fileOut;

//StationType
StationType::StationType(): Net(0), NetElectric(0),
NetLady(0), NetRoad(0), NetHybrid(0), NumElectric(0),
NumLady(0), NumRoad(0), NumHybrid(0), HRent(HeapType()),
HLady(HeapType()), HRoad(HeapType()), HHybrid(HeapType())
{
}


BikePtr NewBike(LicenseType License, int Mile, ClassType Class, StationType &Station, string StationName)
{
  // License, Mile, Class -> for a new bike
  BikePtr newBike = new BikeType();
  newBike -> License = License;
  newBike -> Mileage = Mile;
  newBike -> Class = Class;
  newBike -> Status = Free;
  newBike -> Station = mp[StationName];
  bikeBST.ins(newBike);
  switch(Class){
  case Electric:
    Station.HElectric.Push(newBike);
    newBike -> Cursor = Station.HElectric.Number;
    break;
  case Lady:
    Station.HLady.Push(newBike);
    newBike -> Cursor = Station.HLady.Number;
    break;
  case Road:
    Station.HRoad.Push(newBike);
    newBike -> Cursor = Station.HRoad.Number;
    break;
  case Hybrid:
    Station.HHybrid.Push(newBike);
    newBike -> Cursor = Station.HHybrid.Number;
    break;
  }
  return newBike;
}
