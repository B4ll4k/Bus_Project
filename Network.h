#include <iostream>
#include "Line.h"

using namespace std;

class Network{
	 public:
	 int nbLines;       //no of lines.
    Line * lines; //dynamic array to hold lines in network
	 int avail;
	 int changed; //flag to control save status of network
	 Stations stns;
	 Network();
	~ Network();
int lineIndex(int lineId);
int buildNetwork(char netFileName[]);
int updateNetFile(char netFileName[]);
int noLinesPerStation(int stnId);
int LineThrStation();
int directLine(int stnId, int stnId2);
void displayLinesForward();
void displayLinesBackward();
double distance(int lineId, int stnId, int stnId2);
List<stationData> shortestPath();
};

int Network::lineIndex(int lineId){
			int j=0;

			while (j < nbLines) {
					if(lineId == lines[j].lineNb)
						return j;
						j++;
					}
			return -1;
};

int Network::buildNetwork(char netFileName[]) //build network from file
	{
				stationData p;
			int i, j, nbLns;
	ifstream netf;
	netf.open(netFileName, ios::in);
	if(!netf.fail()){
		netf >> nbLns;
		this->lines=new (nothrow) Line[nbLns + 10];
		if(! this->lines) {
			netf.close();
			return 0;
		}//no memory
		this->nbLines=nbLns;
//		prv = NULL;  // Initially, the linked list is empty
		for(i=0; i<=nbLns-1; i++) {
			netf >> this->lines[i].lineNb;
			netf >> this->lines[i].nbStations;
			for (j=1; j<=this->lines[i].nbStations; j++) {
						netf >> p.stnId;
						netf >> p.distance;
						this->lines[i].stationsList.insertAfter(this->lines[i].stationsList.back, p);
			}
		}
		netf.close();
		 return 1;
	}
	else{
		ofstream ofs;
		ofs.open(netFileName, ios::out);
		if(!ofs)  return 1;      //unable to open file
		ofs << 0 << '\n';
		 netf.clear();
		return Network::buildNetwork(netFileName);
			}
		}

//The function updates the network file
int Network::updateNetFile(char netFileName[]){
	 node<stationData> *p;
	 Line *  lns= this->lines;
	 int nbLns= this->nbLines;
	 ofstream ntf;
	 ntf.open(netFileName, ios::out);
	 if(ntf.fail()){
		ntf.clear();
		return 0;  //file not opened successfully
	 }
	 else{
		ntf << nbLns << endl;
		for(int i=0; i<=nbLns-1; i++) {
			ntf << lns[i].lineNb<< '\t'<<lns[i].nbStations<< "\t";
			p=lns[i].stationsList.front;
			while(p!= NULL) {
				ntf << p->Data.stnId << " " << p->Data.distance << " ";
				p=p->next;
			}
			ntf << "\n";
		}
		 ntf.close();
		return 1;

	 }
}

int Network::noLinesPerStation(int stnId){
	int j=0,count=0;
	node<stationData> * p = NULL;
		while (j < this->nbLines) {
			p = lines[j].stationsList.front;
				for (int i = 0; i < lines[j].nbStations; i++) {
						if(p->Data.stnId == stnId)
							count++;
						p = p->next;
				}
					j++;
		}
		return count;
}
int Network::LineThrStation(){

}

int Network::directLine(int stnId, int stnId2){
	if (stnId == stnId) {
		cout<<"Wrong Input! Please enter different stations!";
		return 0;
	}
	node<stationData> * p = NULL;
	int count=0,i=0;
	while (i < nbLines) {
		p = lines[i].stationsList.front;
		while(p != NULL){
			if(stnId == p->Data.stnId || stnId2 == p->Data.stnId)
				count++;
		}
		if(count = 2)
			return 1;
		else{
			count = 0;
			i++;
		}
	}
	return 0;
};
	//Displays all line information traversing lines in the forward direction

void Network::displayLinesForward() {
	 Line * lns=this->lines;
	int nbLns=this->nbLines;
	cout << "All Network Information"<< endl;
	cout <<"Number of lines: "<< this->nbLines<< endl;
	cout <<endl;
	cout << "All line information" << endl;
	for(int i=0; i< nbLns; i++)
		lns[i].traverseForward(stns);
}

 void Network::displayLinesBackward(){
	 Line * lns=this->lines;
	int nbLns=this->nbLines;
	cout << "All Network Information"<< endl;
	cout <<"Number of lines: "<< this->nbLines<< endl;
	cout <<endl;
	cout << "All line information" << endl;
	for(int i=0; i< nbLns; i++)
		lns[i].traverseBackward(stns);

 };
double Network::distance(int lineId, int stnId, int stnId2){
		if(stnId == stnId2)
			return 0;
			node<stationData> * p = NULL;
			double dis1=0,dis2=0;
				p = lines[lineId].stationsList.front;
				while(p != NULL){
					if(stnId == p->Data.stnId)
						dis1 = p->Data.distance;
						else if(stnId2 == p->Data.stnId)
							dis2 = p->Data.distance;
							p= p->next;
				}
				if(dis2 != 0)
					return dis2-dis1;
				else return 0;

};
List<stationData> Network::shortestPath(){

 };
