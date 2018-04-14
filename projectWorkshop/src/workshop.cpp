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
int Workshop::stringToInt(string s) {
	int result=0;
	
	for(int i=0; i<s.size(); i++){
			result*=10;
		if(!isdigit(s[i])) {
			return -1;		
		}else {
			result+=(int)s[i]-48;
		}
	}
	return result;
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
void Workshop::simulateHour(Workers& w, Customers& c) {
	
	int tiresBefore, tiresNow;
	for(int i=0; i<boxes; i++){
		workPlace[i].setTime(workPlace[i].getTime()- workPlace[i].getWorkerSpeed());
		
		tiresBefore = max(0,workPlace[i].getTime() + workPlace[i].getWorkerSpeed());
		tiresNow = max(0,workPlace[i].getTime());
		//gdy juz nie ma opon do zmiany
		if(tiresBefore!=0) {
			cout << "In box " << i << " " << workPlace[i].getCustName()  << " had " << tiresBefore
				<< " tires to change " << " ,now there are " << tiresNow  << " tires to change" << endl;
		}
		// jesli nie ma juz opon do zmiany w danym boxie, ale byl w nim klient
		if(tiresNow==0 && workPlace[i].getCustName()!="#") {
				// zwolnij box
			workPlace[i].setAvailable(true);
			// proba rzutowania stringa na inta
			int customerCode = stringToInt(workPlace[i].getCustName());
			// korzysta z szablonu klasy Customer 
			if(customerCode >=0) {
				c.addCustomer(customerCode, tiresNow, workPlace[i].getVip());			
			} else {
				c.addCustomer(workPlace[i].getCustName(),tiresNow, workPlace[i].getVip());
			}
			// po wpisaniu klienta do wektora, opuszcza warszata
			// stad jego imie zamieniane jest na "#
			workPlace[i].setCustName("#");
		} else {
			// jesli sa opony do zmiany, to utrzymaj niedostepnosc boxu
			// (nowy klient nie bedzie mogl wjechac)
			workPlace[i].setAvailable(0);
		}
			// usun kazdego pracownika z boxu
			// mozliwe, ze przy kolejnym przejsciu, bedzie istnialo
			// bardziej wydajne ustawienie
			workPlace[i].setWorkerName("#");
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
		if(!workPlace[i].getAvailable())
			cout << " /--\\    |";
			else
				cout<<"         |";
	}
	cout << endl << "|";
	for(int i=0; i<boxes; i++) {
		if(!workPlace[i].getAvailable())
			cout << "  |0--0-|  |"; 
			else
				cout<<"  empty    |";
			
	}
	cout << endl;
}
void Workshop::setCars(Customers& c) {
		
	for(int i =0; i<boxes; i++) {
			// jesli box jest wolny to wjezdza nowy samochod
		if(workPlace[i].getAvailable() && c.getFront()!=NULL) {
			workPlace[i].setCustName(c.getFront()->getCustomerName());
			workPlace[i].setTime(c.getFront()->getTiresToChange());
			workPlace[i].setVip(c.getFront()->getVip());
			// ustawia samochod w boxie, wiec box nie jest juz dostepny
			workPlace[i].setAvailable(0);
			c.pop();
		}
	}
	cout << endl;	
}
bool Workshop::checkSuccess() {
	
	for(int i =0; i<boxes; i++) {		
		if(!workPlace[i].getAvailable()) {
			return 0;
		}
	}
	return 1;
}
void Workshop::leftCustomers() {

	for(int i =0; i<boxes; i++) {
			
		if(!workPlace[i].getAvailable() && workPlace[i].getCustName()!="#") {
			cout << "These customers are : " <<  workPlace[i].getCustName() <<" ";
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
			if(!workPlace[j].getAvailable() && workPlace[j].getWorkerName() == "#" && w.getWorkingAt(i)==0) {
				optimalDiff=min(optimalDiff, w.getSpeedAt(i) - workPlace[j].getTime() );	
			}
		}
		for(int j=0; j<boxes; j++) {
			if(!workPlace[j].getAvailable() && workPlace[j].getWorkerName() == "#" && w.getWorkingAt(i)==0) {
				if(w.getSpeedAt(i) - workPlace[j].getTime() == optimalDiff) {
						workPlace[j].setWorkerName(w.getNameAt(i));
						workPlace[j].setWorkerSpeed(w.getSpeedAt(i));
						w.setWorkingAt(i,1);
						//cout << w.getNameAt(i) << endl;
						if(w.getNameAt(i)!= "#")
						cout << w.getNameAt(i) << " is set to " << j << " box with speed " << w.getSpeedAt(i) << endl;
				}
			}
		}
	}
	
}
