
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
    break;
  case Lady:
    Station.HLady.Push(newBike);
    break;
  case Road:
    Station.HRoad.Push(newBike);
    break;
  case Hybrid:
    Station.HHybrid.Push(newBike);
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
  p->Mileage = mile;

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

  return charge;
}
void UbikeReport()
{
  fileOut << "                 Taipei U-bike\n                    Free Bikes\n     License     Mileage       Class     Station       Total\n============================================================\n";
  int e = 0, l = 0, r = 0, h = 0;
  int net = 0;
  for(int i = 0; i < 12; i++) {
    allStations[i].HElectric.show(12, 1);
    allStations[i].HLady.show(12, 1);
    allStations[i].HRoad.show(12, 1);
    allStations[i].HHybrid.show(12, 1);
    e += allStations[i].HElectric.Number;
    l += allStations[i].HLady.Number;
    r += allStations[i].HRoad.Number;
    h += allStations[i].HHybrid.Number;
    net += allStations[i].Net;
  }
  fileOut << "============================================================\n" << setw(60) << (e + l + r + h) << endl << endl;
  fileOut << "                  Rented Bikes\n     License     Mileage       Class     Station       Total\n============================================================\n";
  int rt = 0;
  for(int i = 0; i < 12; i++) {
    allStations[i].HRent.show(12, 1);
    for(int j = 1; j <= allStations[i].HRent.Number; j++) {
      switch(allStations[i].HRent.Elem[j]->Class) {
        case Electric: e++; break;
        case Lady: l++; break;
        case Road: r++; break;
        case Hybrid: h++; break;
      }
    }
    rt += allStations[i].HRent.Number;
  }
  fileOut << "============================================================\n";
  fileOut << setw(60) << rt << endl << endl;
  fileOut << "         Net    Electric        Lady        Road      Hybrid\n============================================================\n";
  fileOut << setw(12) << net << setw(12) << e << setw(12) << l << setw(12) << r << setw(12) << h << endl;
  fileOut << "============================================================\n\n";

}
void stationReport(string stationName)
{
  fileOut << setw(30) << stationName << endl;
  fileOut << "                    Free Bikes\n";
  fileOut << "        License        Mileage          Class       SubTotal\n";
  fileOut << "============================================================\n";
  allStations[mp[stationName]].HElectric.show(15, 0);
  allStations[mp[stationName]].HLady.show(15, 0);
  allStations[mp[stationName]].HRoad.show(15, 0);
  allStations[mp[stationName]].HHybrid.show(15, 0);
  fileOut << "============================================================\n";
  int r = allStations[mp[stationName]].HElectric.Number +
          allStations[mp[stationName]].HLady.Number +
          allStations[mp[stationName]].HRoad.Number +
          allStations[mp[stationName]].HHybrid.Number;
  fileOut << setw(60) << r << endl << endl;
  fileOut << "                  Rented Bikes\n";
  fileOut << "        License        Mileage          Class       SubTotal\n";
  fileOut << "============================================================\n";
  allStations[mp[stationName]].HRent.show(15, 0);
  fileOut << "============================================================\n";
  fileOut << setw(60) << allStations[mp[stationName]].HRent.Number << endl << endl;
  fileOut << "         Net    Electric        Lady        Road      Hybrid\n";
  fileOut <<"============================================================\n";
  int e = allStations[mp[stationName]].HElectric.Number;
  int l = allStations[mp[stationName]].HLady.Number;
  int rd = allStations[mp[stationName]].HRoad.Number;
  int hy = allStations[mp[stationName]].HHybrid.Number;
  for(int i = 1; i <= allStations[mp[stationName]].HRent.Number; i++) {
    switch(allStations[mp[stationName]].HRent.Elem[i]->Class) {
      case Electric: e++; break;
      case Lady: l++; break;
      case Road: rd++; break;
      case Hybrid: hy++; break;
    }
  }
  fileOut << setw(12) << allStations[mp[stationName]].Net << setw(12) << e << setw(12) << l << setw(12) << rd << setw(12) << hy << endl;
  fileOut << "============================================================\n\n";


}
