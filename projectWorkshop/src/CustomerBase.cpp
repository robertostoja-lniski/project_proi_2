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
#include "CustomerBase.h"
using namespace std;

	
CustomerBase::CustomerBase( int tiresToChange, bool vip) {
	this->vip = vip;
	this->tiresToChange = tiresToChange;
}
CustomerBase::~CustomerBase() {}
CustomerBase::CustomerBase() {}
bool CustomerBase::getVip() { 
	return this->vip;
}
int CustomerBase::getTiresToChange() { 
	return this->tiresToChange;
}
void CustomerBase::setVip(bool vip) { 
	this->vip = vip;
}
void CustomerBase::setTiresToChange(int tiresToChange) { 
	this->tiresToChange = tiresToChange;
}

