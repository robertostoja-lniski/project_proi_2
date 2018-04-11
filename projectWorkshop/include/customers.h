#ifndef CUSTOMERS_H_INCLUDED
#define CUSTOMERS_H_INCLUDED

#include <iostream>
#include <vector>

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <typeinfo>
#include <cstdlib>
using namespace std;
// kolejka priorytetowa klienkow
template <typename T>
class Customers {
	
	struct node {		
		bool vip;
		T customerName;
		int tiresToChange;
		node *link;
	};
	struct node *front;
	
    public:
        // zwraca wskaznik na poczatek kolejki
        node* getFront();
        // konstruktor kolejki
        Customers<T>();
        //destruktow
        ~Customers();
        //ustawia domyslna kolejke   
        void setDefault(Customers<T>& );
        //dodaje klienta ktory ma podana wartosc 1 gdy jest vipem
        void insert(T, int , bool );
        //dodaje klienta (nie vipa)
        void insert(T, int);
        //usuwa wybranego klienta z kolejki
        void remove(T, int, bool);
        //usuwa element z przodu kolejki
        void pop();
        //wypisuje pojedynczy samochodzik i dane o kliencie
        void drawCar(node*);
        //wypisuje cala kolejke
        void display();
};

template <typename T>
Customers<T>::Customers() {
            front = NULL;
        }
template <typename T> 
Customers<T>::~Customers() {
    while(front!=NULL)
        pop();
}
template <typename T> 
void Customers<T>::remove(T name, int tires, bool vip) {
            node *q, *toDel;
            q = front;
            if(name == q->customerName && tires == q->tiresToChange
                   && vip == q->vip) {
                        pop();
                        cout << "Customer went home!" << endl;
                        return;                     
                   } 
            while (q->link != NULL ) {
                if(name == q->link->customerName && tires == q->link->tiresToChange
                   && vip == q->link->vip) {
                        toDel=q->link;
                        q->link = q->link->link;
                        delete q->link;
                        cout << "Customer went home!" << endl;
                        return;
                   }   
                q=q->link;
            }
        cout << "Customer not found " << endl;
    }
     

template <typename T>
typename Customers<T>::node* Customers<T>::getFront() {
                  return front;
        }

template <typename T>
void Customers<T>:: insert(T name, int tires, bool vip) {
            node *tmp, *q;
            tmp = new node;
            tmp->customerName = name;
            tmp->tiresToChange = tires;
            tmp->vip = vip;
            if (front == NULL || vip > front->vip)
            {
                tmp->link = front;
                front = tmp;
            }
            else
            {
                q = front;
                while (q->link != NULL && q->link->vip >= vip)
                    q=q->link;
                tmp->link = q->link;
                q->link = tmp;
                //delete q;
            }
        }
template <typename T>
void Customers<T>:: insert(T name, int tires) {
            node *tmp;
            tmp = new node;
            tmp->customerName = name;
            tmp->tiresToChange = tires;
            tmp->vip = 0;
            if (front == NULL)
            {
                tmp->link = front;
                front = tmp;
            }
            else
            {
                node *q = front;
                while (q->link != NULL)
                    q=q->link;
                tmp->link = q->link;
                q->link = tmp;
            }
        }
template <typename T>
void Customers<T>:: pop() {
            node *tmp;
            if(front == NULL)
                cout<<"No customers in queue\n";
            else
            {
                tmp = front;
                front = front->link;
                delete tmp;
            }
        }
template <typename T>
void Customers<T>::drawCar(node *ptr) {
            cout << " /--\\ " << "       It is " << ptr ->customerName << "'s car " << endl;
            cout << "|0--0-|" << "      He is"; ptr->vip ? : cout << " not"; 
            cout << " a vip and wants to change " << ptr -> tiresToChange << " tires " << endl << endl;
}
template <typename T>
void Customers<T>:: display() {
            node *ptr;
            ptr = front;
            if (front == NULL)
                cout<<"No customers left\n";
            else
            {	cout << endl;
                while(ptr != NULL)
                {
                    drawCar(ptr);
                    ptr = ptr->link;
                }
            }
        }
template <typename T>
void Customers<T>:: setDefault(Customers& pq) {
     string nameTest = "customer X";
     for(int i =0; i < 4; i++) {
			nameTest += (char)(i*55);
			pq.insert(nameTest, i*i*i%4 +1, i%2);
    	}
}
#endif // CUSTOMERS_H_INCLUDED
