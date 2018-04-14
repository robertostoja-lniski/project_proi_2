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
Box::Box() {
	workerName = "#";
}
Box::Box(bool available, string custName, string workerName,
			int time, int workerSpeed) {
		this->available = available;
		this->custName = custName;
		this->workerName = workerName;
		this->time = time;
		this->workerSpeed = workerSpeed;
}
bool Box::getAvailable(){
	return available;
}
bool Box::getVip(){
	return vip;
}
string Box::getCustName(){
	return custName;
}
string Box::getWorkerName(){
	return workerName;
}
int Box::getTime(){
	return time;
}
int Box::getWorkerSpeed(){
	return workerSpeed;
}
void Box:: setAvailable(bool available){
	this->available = available;
}
void Box:: setVip(bool vip){
	this->vip = vip;
}
void Box::setCustName(string custName){
	this->custName = custName;
}
void Box::setWorkerName(string workerName){
	this->workerName = workerName;
}
void Box::setTime(int time){
	this->time = time;
}
void Box::setWorkerSpeed(int workerSpeed){
	this->workerSpeed = workerSpeed;
}

