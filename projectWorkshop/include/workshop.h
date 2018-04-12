#ifndef WORKSHOP_H_INCLUDED
#define WORKSHOP_H_INCLUDED

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include "Workers.h"
#include "Customers.h"


class Workshop {
	
	private:
		int boxes;
		int open;
	struct Work {
			bool available;
			std::string custName;
			std::string workerName;
			int time;
			int workerSpeed;
		};
        std::vector<Work> workPlace;
    public:   
    	//konstruktor 	
        Workshop();
        //destruktor
        ~Workshop();
        //zwraca ilosc godzin otwarcia warsztatu
        int getOpen();
        //sprawdza czy dzien zakonczyl sie sukcesem
        //(czy kazdy klient zostal obsluzony)
        bool checkSuccess();
        //zwraca ktorzy klienci zostali w kolejce (w razie braku sukcesu)
        void leftCustomers();
        //ustawia (generuje) boxy - stanowiska pracy
        void setBoxes(int);
        //symuluje godzine pracy - nowi klienci "wjezdzaja do boxow"
        //najlepsi pracownicy przydzielani sa do samochodow
        void simulateHour(Workers&);
        //wyswietla layout warsztatu
        void drawWorkshop();
        //ustawia samochody w boxach
        void setCars(Customers<string>&);
        //ustawia pracownikow do boxow
        void setWorkers(Workers&);
};

#endif // CUSTOMERS_H_INCLUDED
