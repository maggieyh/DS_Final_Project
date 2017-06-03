
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
    // newBike -> Cursor = Station.HElectric.Number;
    break;
  case Lady:
    Station.HLady.Push(newBike);
    // newBike -> Cursor = Station.HLady.Number;
    break;
  case Road:
    Station.HRoad.Push(newBike);
    // newBike -> Cursor = Station.HRoad.Number;
    break;
  case Hybrid:
    Station.HHybrid.Push(newBike);
    // newBike -> Cursor = Station.HHybrid.Number;
    break;
  }
  return newBike;
}

BikePtr SearchBike(LicenseType License)
{
  return bikeBST.search(License);
}

int JunkBikePtr(LicenseType License)
{
  BikePtr p = SearchBike(License);

  if(p == NULL) {
    return -1;
  }
  if(p->Status == Rented) {
    return -2;
  }

  StationName st = p -> Station;
  // std::cout << st << ":" << std::endl;
  switch(p->Class) {
    case Electric:
      allStations[st].HElectric.Delete(p);
      break;
    case Lady:
      allStations[st].HLady.Delete(p);
      break;
    case Road:
      allStations[st].HRoad.Delete(p);
      break;
    case Hybrid:
      allStations[st].HHybrid.Delete(p);
      break;
  }
  bikeBST.del(p);

  return p -> Station;

}

int TransBikePtr (string stationName, LicenseType License)
{
  BikePtr p = SearchBike(License);
  if (p == NULL)
    return 0;
  if (p -> Status == Rented)
    return 1;
  if (p -> Station == mp[stationName])
    return 2;
  //delete from original station
  switch(p->Class) {
    case Electric:
      allStations[p->Station].HElectric.Delete(p);
      allStations[mp[stationName]].HElectric.Push(p);
      break;
    case Lady:
      allStations[p->Station].HLady.Delete(p);
      allStations[mp[stationName]].HLady.Push(p);
      break;
    case Road:
      allStations[p->Station].HRoad.Delete(p);
      allStations[mp[stationName]].HRoad.Push(p);
      break;
    case Hybrid:
      allStations[p->Station].HHybrid.Delete(p);
      allStations[mp[stationName]].HHybrid.Push(p);
      break;
  }
  p->Station = mp[stationName];
  return 2;

}


int RentBikePtr(string stationName, ClassType Class)
{
  StationName nm = mp[stationName];
  BikePtr p = NULL;
  switch(Class) {
    case Electric:
      p = allStations[nm].HElectric.Top();
      allStations[nm].HElectric.Pop();
      break;
    case Lady:
      p = allStations[nm].HLady.Top();
      allStations[nm].HLady.Pop();
      break;
    case Road:
      p = allStations[nm].HRoad.Top();
      allStations[nm].HRoad.Pop();
      break;
    case Hybrid:
      p = allStations[nm].HHybrid.Top();
      allStations[nm].HHybrid.Pop();

      break;
  }
  if (p == NULL)
    return 0;
  p -> Status = Rented;
  allStations[nm].HRent.Push(p);

  return 1;

}



int Returns(string stationName, LicenseType License, int mile)
{
  //mile -> total Mileage
  BikePtr p = SearchBike(License);
  if (p == NULL) return 0;
  StationName s = p->Station;
  int shortest = dp[mp[stationName]][s], delta = mile - p->Mileage, charge = 0;
  int rate_o[4] = {40, 30, 20, 25};
  int rate_dis[4] = {30, 25, 15, 20};
  if (delta > shortest)
    charge = rate_o[p->Class] * delta;
  else
    charge = rate_dis[p->Class] * delta;
  allStations[s].Net += charge;

  allStations[s].HRent.Delete(p);
  p->Status = Free;

  switch(p->Class) {
    case Electric:
      allStations[s].HElectric.Push(p);
      allStations[s].NetElectric += charge;
      break;
    case Lady:
      allStations[s].HLady.Push(p);
      allStations[s].NetLady += charge;
      break;
    case Road:
      allStations[s].HRoad.Push(p);
      allStations[s].NetRoad += charge;
      break;
    case Hybrid:
      allStations[s].HHybrid.Push(p);
      allStations[s].NetRoad += charge;
      break;
  }
  p->Mileage = mile;
  return 1;
}
