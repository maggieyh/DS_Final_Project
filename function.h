#include <iostream>
#include <string>
enum StatusType {Free, Rented};
enum ClassType { Electric, Lady, Road, Hybrid};
enum StationName {
Danshui, Hongshulin, Beitou, Shilin, Zhongshan, Xinpu,
Ximen, Liuzhangli, Muzha, Guting, Gongguan, Jingmei };
typedef char LicenseType[5];

struct BikeType {
  LicenseType License;
  StatusType Status;
  int Mileage; /* most recently rented mileage */
  int Cursor; /* cursor to the entry in heap where there is a pointer to this node */
  StationName Station;
  ClassType Class;
  // BikeType();
  // BikeType(LicenseType l, StatusType s, int mile, StationName name, ClassType cl);
};
typedef struct BikeType *BikePtr;

//heap.cpp
struct HeapType{
  BikePtr Elem[256];
  /*use array to implement heap, and each node in the heap is a
pointer*/
  int Number; //number of nodes
//last elemen is Elem[Number-1];
  BikePtr Top() const;
  void Push(const BikePtr bike);
  void Delete(BikePtr bike);
  int Search(const BikePtr bike);
  void show();
};

int BikeNum; //the number of bikes in the system
HeapType bikesBinaryTree;


//station cpp
class StationType {
public:
  int Net; /* total income of station */
  int NetElectric;
  int NetLady;
  int NetRoad;
  int NetHybrid;
  int NumElectric; /* number of electric bikes */
  int NumLady; /* number of lady bikes */
  int NumRoad; /* number of road bikes */
  int NumHybrid; /* number of hybrid bikes */
  HeapType HRent;
  HeapType HElectric;
  HeapType HLady;
  HeapType HRoad;
  HeapType HHybrid;
  int Distance[12];

  StationType();

};

//
//
// BikePtr NewBike(LicenseType Licence, int Mile, ClassType Class, StationType Station);
// SearchBike
// void JunkBikePtr(LicenseType licence);
// void TransBikePtr(LicenseType licence, string stationName);
// void RentBikePtr(LicenseType licence); //rent bike
// void Returns(string stationName, LicenseType licence, int mile);
// void Inquire(LicenseType licence); //print info about the licence
// void StationReport
// UbikeReport
// NetSearch
// BReport
