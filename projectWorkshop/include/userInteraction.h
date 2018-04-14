#ifndef USERINTERACTION_H_INCLUDED
#define USERINTERACTION_H_INCLUDED
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include "Workers.h"
#include "Customers.h"
#include "Workshop.h"

class UserInteraction{

	private:
		Customers custList;
		Workers workerGroup;
		Workshop workshopSetup;
		
	public:
		UserInteraction();
		~UserInteraction();
		void start();
		void initialize();
		void addCustomer();
		void addWorker();
		void removeCustomer();
		void removeWorker();
		void simulate();
		void endDay();
		void makeAChoice(int);
		int askForChoice();
		template <typename T> T readAll(T bottom, T top);
		template <typename T> T readAll();
};


#endif // USERINTERACTION_H_INCLUDED
