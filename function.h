#include <iostream>
#include <string>
#include <map>
using namespace std;
#define INF 0x3f3f3f
enum StatusType {Free, Rented};
enum ClassType { Electric, Lady, Road, Hybrid};
enum StationName  {
Danshui, Hongshulin, Beitou, Shilin, Zhongshan, Xinpu,
Ximen, Liuzhangli, Muzha, Guting, Gongguan, Jingmei };
std::map<std::string, StationName>mp = {
  {"Danshui", Danshui},
  {"Hongshulin", Hongshulin},
  {"Beitou", Beitou},
  {"Shilin", Shilin},
  {"Zhongshan", Zhongshan},
  {"Xinpu", Xinpu},
  {"Ximen", Ximen},
  {"Liuzhangli", Liuzhangli},
  {"Muzha", Muzha},
  {"Guting", Guting},
  {"Gongguan", Gongguan},
  {"Jingmei", Jingmei}
};
int lengthMap[12][12] = {0x3f3f3f};
int dp[12][12] = {0x3f3f3f};
typedef string LicenseType;

struct BikeType {
  LicenseType License;
  StatusType Status;
  int Mileage; /* most recently rented mileage */
  int Cursor; /* cursor to the entry in heap where there is a pointer to this node */
  StationName Station;
  ClassType Class;
};
typedef struct BikeType *BikePtr;

//heap.cpp
struct HeapType{
  BikePtr Elem[256]; // last elemen is Elem[Number]
  /*use array to implement heap, and each node in the heap is a pointer*/
  int Number; // number of nodes
  BikePtr Top() const;
  void Push(const BikePtr bike);
  void Delete(BikePtr bike);
  int Search(const BikePtr bike);
  void show();
  HeapType();

};

int BikeNum; //the number of bikes in the system
//bst.cpp

struct _node {
  BikePtr bike;
  struct _node *left, *right;
  _node():bike(NULL), left(NULL), right(NULL) {}
};

class _BST {
public:
  _node *root;
  _BST(): root(NULL) {};
  void ins(BikePtr bike);
  void del(BikePtr bike);
  BikePtr search(LicenseType licence);
  void show(_node *n);
} bikeBST;

void shortestPath()
{
  for(int k = 0; k < 12; k++) {
    for(int i = 0; i < 12; i++) {
      for(int j = 0; j < 12; j++) {
        if(dp[i][k] + dp[k][j] < dp[i][j])
          dp[i][j] = dp[i][k] + dp[k][j];
      }
    }
  }
}
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
  int name;

  StationType();

};
StationType allStations[12];

//
// creates a new node for the bike and inserts the
// node to appropriate positions in the binary search tree
// and the corresponding heap (HElectric, HLady, HRoad and HHybrid)
// of Station. Return the newly created node.
BikePtr NewBike(LicenseType License, int Mile, ClassType Class, StationType &Station, string StationName);

BikePtr SearchBike (LicenseType License);


// void JunkBikePtr(LicenseType licence);
// void TransBikePtr(LicenseType licence, string stationName);
// void RentBikePtr(LicenseType licence); //rent bike
// void Returns(string stationName, LicenseType licence, int mile);
// void Inquire(LicenseType licence); //print info about the licence
// void StationReport
// UbikeReport
// NetSearch
// BReport
