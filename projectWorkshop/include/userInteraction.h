#ifndef USERINTERACTION_H_INCLUDED
#define USERINTERACTION_H_INCLUDED
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include "workers.h"
#include "customers.h"
#include "workshop.h"

class userInteraction{

	private:
		Customers<string> custList;
		Workers workerGroup;
		Workshop workshopSetup;
		
	public:
		userInteraction();
		~userInteraction();
		void drawMenu();
		template <typename T> T readAll(T bottom, T top);
		template <typename T> T readAll();
};


#endif // USERINTERACTION_H_INCLUDED
