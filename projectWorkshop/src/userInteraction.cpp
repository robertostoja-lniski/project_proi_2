#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <typeinfo>
#include <cstdlib>
#include <vector>
#include "Customers.h"
#include "Workshop.h"
#include "UserInteraction.h"
#include "Workers.h"

#define DEFAULT_BOX_NUM 3
#define MAX_OPENING_HOUR 23
#define MAX_CLOSING_HOUR 24

using namespace std;

UserInteraction :: UserInteraction() {
		
	Workshop workshopSetup;	
	workerGroup.sortWorkers();
}
UserInteraction :: ~UserInteraction() { cout << "everything destructed :)" << endl;}
void UserInteraction :: initialize() {
	
	  int speed,tires,vip;
	  string name;
	  
	  cout << "Welcome to Workshop Simulator" << endl;
	  cout << " 1. to use Default setup\n" << " 2. to use your Own\n";
	  int choice = readAll<int>( 1, 2);

	  if(choice){
		 workshopSetup.setBoxes(DEFAULT_BOX_NUM);
		 workshopSetup.setDefaultHours();
		 custList.setDefault();
		 workerGroup.setDefault();
	  }
	  else {
		int openingHour,closingHour;
	  	cout << "Enter the number of boxes ";
		choice = readAll<int>(1,6);
		workshopSetup.setBoxes(choice);
		cout << "Enter opening hour (number from 0 to 23) ";
		openingHour = readAll<int>(0,MAX_OPENING_HOUR);
		cout << "Enter closing hour ";
		closingHour = readAll<int>(openingHour, MAX_CLOSING_HOUR);	 
		workshopSetup.setOpeningHour(openingHour);
		workshopSetup.setClosingHour(closingHour);
	  }

}
int UserInteraction :: askForChoice() {
	
		cout<<" \nNow it is " << workshopSetup.getOpeningHour() + workshopSetup.getOpen() << ":00 " << endl; 
    	cout<<" 1.Add a customer\n";
        cout<<" 2.Add a worker\n";
        cout<<" 3.Remove a customer\n";
        cout<<" 4.Remove a worker\n";
        cout<<" 5.Simulate\n";
        cout<<" 6.Quit\n ";
        cout<<"Enter your choice : "; 
        return readAll<int>(1,6);
}
void UserInteraction :: addCustomer() {
	string name;
	int tires;
	bool vip;
	cout<<"Enter customer name ";
		cin>>name;
            if(name=="#") {
				name = "##";
				cout << "# forbiden - altered to ##" << endl;            
            }
            cout<<"Enter 1 if vip 0 if not ";
            vip = readAll<bool>(0,1);
            cout<<"Enter tires to change ";
            tires = readAll<int>(0,10);
            vip ? custList.insert(name, tires, vip) : custList.insert(name, tires);
}
void UserInteraction :: addWorker() {
	string name;
	int speed;
	 cout << "Enter worker name ";
		cin >> name;
            if(name=="#") {
				name = "##";
				cout << "# forbiden - altered to ##" << endl;            
            }
            cout << "Enter worker speed ";
            speed = readAll<int>(1, 50);
            workerGroup.addWorker(name, speed);
}
void UserInteraction :: removeCustomer() {
	string name;
	bool vip;
	int tires;
	cout << "Enter customer name to remove ";
		cin >> name;
			cout << "Enter 1 if vip 0 if not ";
			vip = readAll<bool>(0,1);
			cout << "Enter his tires to change ";
			tires= readAll<int>(0,10);			
			custList.remove(name,tires,vip);
}
void UserInteraction :: removeWorker() {
	string name;
	int speed;
	cout << "Enter worker name to remove ";
        	cin >> name;
        	cout << "Enter worker speed ";
        	cin >> speed;
        	workerGroup.removeWorker(name, speed);
}
void UserInteraction :: simulate() {
	workshopSetup.setCars(custList);
		workerGroup.sortWorkers();
        //	workerGroup.showWorkers();
        	workshopSetup.setWorkers(workerGroup);
        	workshopSetup.drawWorkshop();
        	custList.display();
        	workshopSetup.simulateHour(workerGroup, custList);
}

void UserInteraction :: start() {
	  
	  initialize();	  
	  
	  do {
    	int choice = askForChoice();
		makeAChoice(choice);
	  }
      while(workshopSetup.getOpeningHour() + workshopSetup.getOpen()
			 < workshopSetup.getClosingHour());
	  endDay();
   
}
void UserInteraction::makeAChoice(int choice) {
	
        switch(choice)
        {
        case 1: { addCustomer(); break; }
        case 2: { addWorker(); break; }
        case 3: { removeCustomer(); break; }
        case 4: { removeWorker(); break; }
        case 5: { simulate(); break; }
		case 6: { exit(0); }
        default :{ cout<<"Wrong choice\n"; break;}           
        }
}
void UserInteraction::endDay() {
	 cout<<" \nNow it is " << workshopSetup.getClosingHour() << ":00 " << endl;
    if(!workshopSetup.checkSuccess()) {
		cout << "The day has finished. Unfortunately, few customers have to leave their cars" << endl;
		cout << "in our workshop to have their tires changed :/" << endl;
		workshopSetup.drawWorkshop();
		workshopSetup.leftCustomers();			
    } else {
    	cout <<"The day has finished. Success! every customer is satisfied! :D" << endl;
    }
    cout << "Satisfied customers:" << endl;
    custList.printCustVector();
}
/* metoda wczytujaca dane dowolnego typu spelniajace waruenk,
ze naleza do przedzialu <bottom, top> */
template <typename T> T 
UserInteraction :: readAll(T bottom, T top) {
	T c;
	bool check;
   	do{
		check = 0;
	 	cin >> c;
	 	if(!cin) {
			check = 1;
			cout << "Wrong symbol" << endl;
	 	} else {
	 		if(c<bottom || c > top) {
				check = 1;
				cout << "Enter symbol between " << bottom << " and " << top << " \n";
			}
	 	}
	 	cin.clear();
		cin.ignore(256, '\n');

   }while(check);
   return c;
}
template <typename T> T 
UserInteraction :: readAll() {
	T c;
	bool check;
   	do{
		check = 0;
	 	cin >> c;
	 	if(!cin) {
			check = 1;
			cout << "Wrong symbol" << endl;
	 	}
	 	else {
				cout << "Wrong symbol\n";
			}
	 	
	 	cin.clear();
		cin.ignore(256, '\n');

   }while(check);
   return c;
}
