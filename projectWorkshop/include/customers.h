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
// kolejka priorytetowa klienkow

class Customers {
	
	std::vector<CustomerBase*> satisfiedCustomers;
	Customer<std::string> *front;
	
    public:
        // zwraca wskaznik na poczatek kolejki
        Customer<std::string>* getFront();
        // konstruktor kolejki
        Customers();
        //destruktow
        ~Customers();
        //dodaje klienca do wektora
        template <typename T> void addCustomer(T, int, bool); 
        //wypisuje wektor zadowolonych klientow
        void printCustVector();
        //ustawia domyslna kolejke   
        void setDefault();
        //dodaje klienta ktory ma podana wartosc 1 gdy jest vipem
        void insert(std::string, int , bool );
        //dodaje klienta (nie vipa)
        void insert(std::string, int);
        //usuwa wybranego klienta z kolejki
        void remove(std::string, int, bool);
        //usuwa element z przodu kolejki
        void pop();
        //wypisuje pojedynczy samochodzik i dane o kliencie
        void drawCar(Customer<std::string>*);
        //wypisuje cala kolejke
        void display();
};
template <typename T>
void Customers::addCustomer(T name, int tiresToChange, bool vip) // adds a new item to the list with a specific type
        {
            Customer<T>* nextCustomer = new Customer<T>(name, tiresToChange, vip);
            satisfiedCustomers.push_back(nextCustomer);
        }
#endif // CUSTOMERS_H_INCLUDED
