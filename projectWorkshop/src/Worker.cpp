#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include "Workers.h"
#include "Worker.h"
using namespace std;
	
Worker::Worker(string name, int speed, bool working) {
	this->name = name;
	this->speed = speed;
	this->working = working;
}
Worker::~Worker() {}
string Worker::getName() {
	return name;
}
int Worker::getSpeed() {
	return speed;
}
bool Worker::getWorking() {
	return working;
}		
void Worker::setName(string name) {
	this->name = name;
}
void Worker::setSpeed(int speed) {
	this->speed = speed;
}
void Worker::setWorking(bool working) {
	this->working = working;
}
bool Worker::operator< (Worker& a){
		return speed >= a.getSpeed();	
}


