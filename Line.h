#include <iostream>
#include "List.h"

using namespace std;

class Line{    //structure for cityline.
	 public:
	int lineNb;       //Identification number for a line.
	int nbStations;   //Number of stations on a line
	List<stationData> stationsList; //Line of stations
	Line();
	~Line();
	List<stationData> getSubLine(node<stationData> * p, node<stationData> * t);
	void addStation(stationData P);
	void deleteStation(node<stationData> * P);
	void traverseForward(Stations stns);
	void traverseBackward(Stations stns);

};

List<stationData> Line::getSubLine(node<stationData> * p, node<stationData> * t){
	if(!stationsList.isEmpty()){
		List<stationData> newStationList;
		p->prev = NULL;
		t->next = NULL;
		newStationList.front = p;
		newStationList.back = t;
			return newStationList;
	}
	 List<stationData> newOne;
		return newOne;
}

void Line::addStation(stationData P){

};

void Line::deleteStation(node<stationData> * P){
	if(stationsList.isEmpty())
		return;
	else{
			node<stationData> * X = stationsList.front;
			while(X != NULL){
					if(X == P){
						 X->prev->next = P->next;
						 X->next->prev = P->prev;
						 delete P;
						 cout<< " Successfully Deleted!!"<<endl;
						 return;
					}
					cout<<" Deletion Failed!!"<<endl;
			}
	}
};

//Displays all informations of all stations when traversing a line in the forward direction
void Line::traverseForward(Stations stns) {
 node<stationData> * p=Line::stationsList.front;
cout<<"Line: " << this->lineNb << endl;
 cout<<"No Stations: "<< this->nbStations<< endl;
while (p  != NULL) {
	cout <<p->Data.stnId << "(" << stns.mapStation(p->Data.stnId )<<")";
	if (p->next) cout << " -> ";
	p=p->next;
}
cout << endl;
}

//Displays all informations of all stations when traversing a line in the backward direction

void Line::traverseBackward(Stations stns) {
 node<stationData> * p=Line::stationsList.back;
cout<<"Line:  "<< this->lineNb << endl;
 cout<<"No Stations: "<< this->nbStations<< endl;
while (p  != NULL) {
	cout <<p->Data.stnId << "( "<< stns.mapStation(p->Data.stnId )<<" )";
	if (p->next) cout << " -> ";
	p=p->prev;
}
cout << endl;

}
