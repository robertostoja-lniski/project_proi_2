#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

class Workers {

		struct workerParams{
			std::string name;
			int speed;
			bool working;
			bool operator<(const workerParams&);
			
		};
		
		std::vector <workerParams> workerVector;
	public:
		//konstruktor
		Workers();
		//destruktor
		~Workers();
		//zwraca szybosc pracownika na i-tej pozycji
		int getSpeedAt(int);
		//zwaraca imie pracownika na i-tej pozycji
		std::string getNameAt(int);
		//zwraca czy pracownik na i-tej pozycji pracuje, czy sie leni
		bool getWorkingAt(int);
		// zagania i-tego pracownika do
		//pracy w n-tym boxie
		void setWorkingAt(int, int);
		//ustawia domyslnie pracownikow
		void setDefault(Workers&);
		//dodaje pracownika
		void addWorker(std::string , int );
		//wyrzuca pracownika z warsztatu
		void removeWorker(std::string , int);
		//sortuje pracownikow pod wzgledem ich szybkosci
		void sortWorkers();
		//pokazuje pracownikow
		void showWorkers();
};

#endif // EMPLOYEE_H_INCLUDED
