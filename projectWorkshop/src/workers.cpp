#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include "Workers.h"
#include "Worker.h"
using namespace std;
	
Workers :: Workers(){};

Workers::~Workers() {
	workerVector.clear();
}
int Workers::getSpeedAt(int i) {
	if(i<workerVector.size())
		return workerVector[i].getSpeed();
	else	
		return 0;
}
string Workers::getNameAt(int i) {
	if(i<workerVector.size())
		return workerVector[i].getName();
	else
		return "#";
}
bool Workers::getWorkingAt(int i) {
	if(i<workerVector.size())
		return workerVector[i].getWorking();
	else
		return 0;
};
void Workers::setWorkingAt(int i, int val) {
	if(i<workerVector.size())
		workerVector[i].setWorking(val);
	return;
};
void Workers::removeWorker(string name, int speed) {
	
		vector<Worker>::iterator it = workerVector.begin();
		for(it; it != workerVector.end(); ++it) {
					if(it->getName()==name && it->getSpeed() == speed ) {
							workerVector.erase(it);
							cout << "worker is fired!" << endl;
							return;
					}
			}
		cout << "probably, the worker you want to fire, is already fired!" << endl;
}
void Workers :: addWorker(string name, int speed) {
			Worker w(name,speed,false);
			workerVector.push_back(w);
		}		
void Workers :: sortWorkers() {
			sort(workerVector.begin(), workerVector.end());
		}
void Workers :: showWorkers() {		
		vector<Worker>::iterator it = workerVector.begin();
		for(it; it != workerVector.end(); ++it) {
					if(it->getName()!="#") 
					cout << " name: " << it->getName() << " speed : "
						 << it->getSpeed() << " if working: " << it->getWorking()<< endl;
			}
		}
void Workers :: setDefault(Workers& w) {
	string name;
	 for(int i =0; i < 4; i++) {
			switch(i) {
				case 1: w.addWorker("Janek", 1);  break;
				case 2: w.addWorker("Marek", 2); break;
				case 3: w.addWorker("Tomek", 3); break;
				case 4: w.addWorker("Jozek", 0); break;
			}

    	}	
}

