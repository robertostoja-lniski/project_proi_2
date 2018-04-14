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
#include "Box.h"

class Workshop {
	
	private:
		int boxes;
		int open;
        std::vector<Box> workPlace;
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
        //obsluzeni klienci trafiaja do wektora klientow zadowolonych
        //(znajdujacym sie w obiekcie Customers)
        void simulateHour(Workers&, Customers&);
        //wyswietla layout warsztatu
        void drawWorkshop();
        //ustawia samochody w boxach
        void setCars(Customers&);
        //ustawia pracownikow do boxow
        void setWorkers(Workers&);
        // zamienia stringa na unsigned inta, lub zwraca -1 w wypadku niepowodzenia
        int stringToInt(std::string);
};

#endif // CUSTOMERS_H_INCLUDED
