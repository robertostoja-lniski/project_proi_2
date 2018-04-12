#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include "Workers.h"
using namespace std;
	
Workers :: Workers(){};
bool Workers::workerParams::operator< (const workerParams& a){
		return speed >= a.speed;	
}
Workers::~Workers() {
	workerVector.clear();
}
int Workers::getSpeedAt(int i) {
	if(i<workerVector.size())
		return workerVector[i].speed;
	else	
		return 0;
}
string Workers::getNameAt(int i) {
	if(i<workerVector.size())
		return workerVector[i].name;
	else
		return "";
}
bool Workers::getWorkingAt(int i) {
	if(i<workerVector.size())
		return workerVector[i].working;
	else
		return 0;
};
void Workers::setWorkingAt(int i, int val) {
	if(i<workerVector.size())
		workerVector[i].working = val;
	return;
};
void Workers::removeWorker(string name, int speed) {
	
		vector<workerParams>::iterator it = workerVector.begin();
		for(it; it != workerVector.end(); ++it) {
					if(it->name==name && it->speed == speed ) {
							workerVector.erase(it);
							cout << "worker is fired!" << endl;
							return;
					}
			}
		cout << "the worker you want to fire, is already fired!" << endl;
}
void Workers :: addWorker(string name, int speed) {
			workerVector.push_back({name, speed, false});
		}
		
void Workers :: sortWorkers() {
			sort(workerVector.begin(), workerVector.end());
		}
void Workers :: showWorkers() {
		
		vector<workerParams>::iterator it = workerVector.begin();
		for(it; it != workerVector.end(); ++it) {
					if(it->name!="") 
					cout << " name: " << it->name << " speed : "
						 << it->speed << " if working: " << it->working<< endl;
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

