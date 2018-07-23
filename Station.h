#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

template <class T>
struct node{
		T Data;
		node<T> * prev;
		node<T> * next;
};

struct stationData{
	int  stnId; // station number
	float distance;   // distance from the beginning
};


struct station{
	int stnId;        //A number for identification of a station
	char name[20];   // Name for a station
};

class Stations {
	 public:
	int nbStations;       //no of stations in the network.
	int avail; //no of slot avaliable to add new slot
	int changed;
	station * stationList; //dynamic array to hold the stations in the network
	 Stations(); //constructor
	 Station(char fileName[]){
		 if(!buildStations(fileName))
			 system("cls");
			 cout<<"Error something occured reading the file!!";
			 system("pause");
			 exit(1);
	 }
	~ Stations(); //destructor
	int addStation();
	int deleteStation();
	int buildStations(char stnFileName[]);
    int updateNetFile(char stnFileName[]);
    string mapStation(int stNo);
    int mapStation(char stName[]);
	void displayStations();

};
  int Stations::buildStations(char stnFileName[]){
  	int i,nbStns;
  	ifstream stnf;
  	stnf.open(stnFileName, ios::in);
  	if(!stnf.fail()){
  		stnf.seekg(0, ios::beg);
  		stnf >> nbStns;
  		 this->stationList=new (nothrow) station [nbStns+ 10];
  		if(!this->stationList) return 0; //not enough memory
  		 this->nbStations =nbStns;
  		this->avail=10; //10more space to addnew stations
  		for(int i=0; i< nbStns; i++){
  			stnf >>this->stationList[i].stnId;
  			stnf >>this->stationList [i].name;
  		}
  		return 1; //success
  	}else{
  		ofstream ofs(stnFileName);
  		if(!ofs)  return 1;      //unable to open file
  		ofs << 0 << '\n';
  		stnf.close();
  		return Stations::buildStations(stnFileName);
  }
  	return 0;
    }

  //The function updates the stations file

  int Stations::updateNetFile(char stnFileName[]){
  	 node<stationData> * p;
  	 station *  stationList= this->stationList;
  	 int nbStns= this->nbStations;
  	 ofstream stnf;
  	 stnf.open(stnFileName, ios::out);
  	 if(!stnf){
  		stnf.clear();
  		return 0;  //file not opened successfully.update failed
  	 }else{
  		stnf<<nbStns<< endl;
  		for(int i=0; i<=nbStns-1; i++) {
  			stnf << this->stationList[i].stnId<<"\t"<<this->stationList[i].name<<"\n";
  		}
  		 stnf.close();
  	 	return 1; // update success

  	 }
  }

	void Stations::displayStations(){
		if(this->stationList != NULL){
			for (int i = 0; i < this->nbStations; i++) {
					cout<< "Station Name: " << this->stationList[i].name;
					cout<< "Station Id: "<< this->stationList[i].stnId;
					cout<<endl<<endl;
			}
		}
	};

	string Stations::mapStation(int stNo){
			if (this->stationList != NULL) {
				for (int i = 0; i < nbStations; i++) {
					if(stNo == this->stationList[i].stnId)
						return this->stationList[i].name; //must convert
				}
				return NULL;
			}
	}
	int Stations::mapStation(char stName[]){
		if(this->stationList != NULL){
				for (int i = 0; i < nbStations; i++) {
						if(strcmp(stName, this->stationList[i].name))
								return this->stationList[i].stnId;
				}
		}
		return 0;
	}
