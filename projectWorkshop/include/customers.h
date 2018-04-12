#ifndef CUSTOMERS_H_INCLUDED
#define CUSTOMERS_H_INCLUDED

#include <iostream>
#include <vector>

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <typeinfo>
#include <cstdlib>
#include "Customer.h"
using namespace std;
// kolejka priorytetowa klienkow

class Customers {
	
	
	Customer<string> *front;
	
    public:
        // zwraca wskaznik na poczatek kolejki
        Customer<string>* getFront();
        // konstruktor kolejki
        Customers();
        //destruktow
        ~Customers();
        //ustawia domyslna kolejke   
        void setDefault(Customers&);
        //dodaje klienta ktory ma podana wartosc 1 gdy jest vipem
        void insert(std::string, int , bool );
        //dodaje klienta (nie vipa)
        void insert(std::string, int);
        //usuwa wybranego klienta z kolejki
        void remove(std::string, int, bool);
        //usuwa element z przodu kolejki
        void pop();
        //wypisuje pojedynczy samochodzik i dane o kliencie
        void drawCar(Customer<string>*);
        //wypisuje cala kolejke
        void display();
};

#endif // CUSTOMERS_H_INCLUDED
