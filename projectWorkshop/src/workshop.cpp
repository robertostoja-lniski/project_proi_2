#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include "Customers.h"
#include "Workshop.h"
#include "UserInteraction.h"
using namespace std;


Workshop::Workshop() {
	boxes = 0;
	open = 0;
}
Workshop::~Workshop() {
	workPlace.clear();
}
int Workshop::getOpen() {
	return open;
}

void Workshop::setBoxes(int num) {
	boxes = num;
	for(int i=0; i<boxes; i++ ) {
		workPlace.push_back({1,"#", "#",0,0});	
	}
}
void Workshop::simulateHour(Workers& w) {
	
	int tiresBefore, tiresNow;
	for(int i=0; i<boxes; i++){
		workPlace[i].time -= workPlace[i].workerSpeed;
		
		tiresBefore = max(0,workPlace[i].time + workPlace[i].workerSpeed);
		tiresNow = max(0,workPlace[i].time);
		//gdy juz nie ma opon do zmiany
		if(tiresBefore!=0) {
			cout << "In box " << i << " " << workPlace[i].custName  << " had " << tiresBefore
				<< " tires to change " << " ,now there are " << tiresNow  << " tires to change" << endl;
		}
			!tiresNow ? workPlace[i].available = 1 : workPlace[i].available =0;
			workPlace[i].workerName="#";
			
			w.setWorkingAt(i,0);
		}
	open++;
}

void Workshop::drawWorkshop() {
	for(int i=0; i<boxes*12+1; i++)
		cout << "-";
		
	cout << endl;
	cout << "|";
	for(int i=0; i<boxes; i++) {
		i>10 ? cout << i : cout << i << " ";
		if(!workPlace[i].available)
			cout << " /--\\    |";
			else
				cout<<"         |";
		//cout << "|0--0-|" << "      He is"; ptr->vip ? : cout << " not"; 
	}
	cout << endl << "|";
	for(int i=0; i<boxes; i++) {
		if(!workPlace[i].available)
			cout << "  |0--0-|  |"; 
			else
				cout<<"  empty    |";
			
	}
	cout << endl;
	
	
}
void Workshop::setCars(Customers<string>& c) {
	
	
	for(int i =0; i<boxes; i++) {
			// jesli box jest wolny to wjezdza nowy samochod
		if(workPlace[i].available && c.getFront()!=NULL) {
			workPlace[i].custName = c.getFront()->customerName;
			workPlace[i].time = c.getFront()->tiresToChange;
			
			// ustawia samochod w boxie, wiec box nie jest juz dostepny
			workPlace[i].available = 0;
			c.pop();
		}
	}
	cout << endl;	
}
bool Workshop::checkSuccess() {
	
	for(int i =0; i<boxes; i++) {
			
		if(!workPlace[i].available) {
			return 0;
		}
	}
}
void Workshop::leftCustomers() {

	for(int i =0; i<boxes; i++) {
			
		if(!workPlace[i].available) {
			cout << "These customers are : " <<  workPlace[i].custName <<" ";
		}
		cout << ". " <<  endl;
	}
}
void Workshop::setWorkers(Workers& w){
	int optimalDiff;
	
	// Po pierwsze, prawdopodobnie istnieje lepszy (wydajniejszy sposob) przydzielania pracownikow.
	// pierwsza petla sprawdza gdzie ustawic pierwszego ( z posortowanego
	// malejaco wektora pracownikow ) - najszybszego pracownika.
	// pracownik bedzie przydzielony do takiego samochodu, zeby (w najlepszej sytuacji)
	// cala godzine zmienial opony - tzn nie bylo takiej sytuacji ze "wykona swoja prace
	// przed koncem czasu". Np pracownik o szybkosci 5 powinien zostac przydzielony do 
	// samochodu, ktory ma 6 opon do zmiany, zamiast do samochodu z 3 oponami ( wtedy zmieni opony 
	// i bedzie "siedzial bezczynnie"). Po drugie, przykladowo, lepiej jest przydzielic pracownika
	// o szybkosci 5 do samochodu z 5 oponami do zmiany, niz z 6. (wtedy samochod szybciej opusci warsztat)
	for(int i=0; i<boxes; i++) {
		optimalDiff = 1000000000;
		for(int j=0; j<boxes; j++) {
			if(!workPlace[j].available && workPlace[j].workerName == "#" && w.getWorkingAt(i)==0) {
				optimalDiff=min(optimalDiff, w.getSpeedAt(i) - workPlace[j].time );	
			}
		}
		for(int j=0; j<boxes; j++) {
			if(!workPlace[j].available && workPlace[j].workerName == "#" && w.getWorkingAt(i)==0) {
				if(w.getSpeedAt(i) - workPlace[j].time == optimalDiff) {
						workPlace[j].workerName = w.getNameAt(i);
						workPlace[j].workerSpeed = w.getSpeedAt(i);
						w.setWorkingAt(i,1);
						if(w.getNameAt(i)!= "")
						cout << w.getNameAt(i) << " is set to " << j << " box with speed " << w.getSpeedAt(i) << endl;
				}
			}
		}
	}
	
}
