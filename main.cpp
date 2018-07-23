#include<iostream>
#include "Network.h"

using namespace std;

int menu(){
  int choice;

  cout<<"MAIN SWITCH BORD"<<endl;
  cout<<"1. Network Information"<<endl;
  cout<<"2. Edit Network"<<endl;
  cout<<"3. Network Changed. Save Changes"<<endl; //appears if network changed
  cout<<"4. Undo All Changes"<<endl;
	 //appears if network changed
   cout<<"5. Exit"<<endl;
   cin>>choice;

   return choice;
}

int netInfoMenu(){
  int choice;

  cout<<"Network Information"<<endl;
  cout<<"1. All Network Information"<<endl;
  cout<<"2. Line Information"<<endl;
  cout<<"3. Station Information"<<endl;
  cout<<"4. Shortest Path Information"<<endl;
  cout<<"5. Network Changed. Save Changes //appears if network changed '\n'
        Undo All Changes //appears if network changed."<<endl;
  cout<<"6. Back To Main Switch Board."<<endl;
  cout<<"7. Exit"<<endl;
  cin>>choice;

  return choice;
}

int editNetMenu(){
  int choice;

cout<<"EDIT NETWORK"<<endl;
cout<<"1. Introduce A New Station"<<endl;
cout<<"2. Change Station Name"<<endl;
cout<<"3. Change Station Number"<<endl;
cout<<"4. Insert A New Station On A Line"<<endl;
cout<<"5. Delete Station From Line"<<endl;
cout<<"6. Delete Station From Network"<<endl;
cout<<"7. Introduce A New Line"<<endl;
cout<<"8. Change Line Number"<<endl;
cout<<"9. Delete A line"<<endl;
cout<<"10. Network Changed. Save Changes. //appears if network changed '\n'
        Undo All Changes. //appears if network changed"<<endl;
cout<<"11. Back To Main Switch Board"<<endl;
cout<<"12. Exit"<<endl;
cin>>choice;

  return choice;
}
int main() {
  Station stn;
  stn.buildStations("stations.txt");
  Network ntw;
  ntw.buildNetwork("network.txt");
  Line ln;
  do {

    int choice = menu();

      switch (choice) {
        case 1:{
          system("cls");
          choice = netInfoMenu();
            switch (choice) {
              case 1:{
                system("cls");
              ntw.displayLinesForward();
                break;
              }
              case 2:{
                system("cls");
                Station stat;
                ln.traverseForward(stat);
                break;
              }
              case 3:{
                system("cls");
                stn.displayStations();
                break;
              }
              case 4:{
                system("cls");
                break;
              }
              case 5:{

                break;
              }
              case 6:{

                break;
              }
            }
          break;
        }
        case 2:{
          system("cls");
          choice = editNetMenu();

          switch (choice) {
            case 1:{
              break;
            }
            case 2:{
              break;
            }
            case 3:{
              break;
            }
            case 5:{
              break;
            }
            case 7:{
              break;
            }
            case 8:{
              break;
            }
            case 9:{
              break;
            }
            case 10:{
              break;
            }
            case 11:{
              break;
            }
            case 12:{
              break;
            }

          }

          break;
        }
        case 3:{

          break;
        }
        case 5:{

          break;
        }
      }
  } while(/* condition */);
  return 0;
}
