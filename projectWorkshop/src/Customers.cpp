#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include "customers.h"
#include "workshop.h"
#include "userInteraction.h"
using namespace std;

Customers::Customers() {
            front = NULL;
        }
Customers::~Customers() {
    while(front!=NULL)
        pop();
}
void Customers::printCustVector() {
  
        vector<CustomerBase*>::iterator it;
		for(it = satisfiedCustomers.begin(); it != satisfiedCustomers.end(); ++it) {
               cout << (*(*it));
			}
}
void Customers::remove(std::string name, int tires, bool vip) {
            Customer<string> *q;
            q = front;
            if(name == q->getCustomerName() && tires == q->getTiresToChange()
                   && vip == q->getVip()) {
                        pop();
                        cout << "Customer went home!" << endl;
                        return;                     
                   } 
            while (q->getLink() != NULL ) {
                if(name == q->getLink()->getCustomerName() && tires == q->getLink()->getTiresToChange()
                   && vip == q->getLink()->getVip()) {
                        q->setLink(q->getLink()->getLink());
                        cout << "Customer went home!" << endl;

                        return;
                   }   
                q=q->getLink();
            }
        cout << "Customer not found " << endl;
    }
    
Customer<string>* Customers::getFront() {
                  return front;
        }

void Customers:: insert(std::string name, int tires, bool vip) {
            Customer<string> *tmp, *q;
            tmp = new Customer<string>(name, tires, vip);
         

            if (front == NULL || vip > front->getVip()){
          
                tmp->setLink(front);
                front = tmp;

            }
            else
            {

                q = front;
                while (q->getLink() != NULL && q->getLink()->getVip() >= vip) {
                       q=q->getLink();
                }
                    
                tmp->setLink(q->getLink());
                q->setLink(tmp);

            }
        }

void Customers:: insert(std::string name, int tires) {
           Customer<string> *tmp, *q;
            tmp = new Customer<string>(name, tires, 0);
            
                q = front;
                while (q->getLink() != NULL) {
                       q=q->getLink();
                }
                    
                tmp->setLink(q->getLink());
                q->setLink(tmp);

            }
         
void Customers:: pop() {

            if(front == NULL)
                cout<<"No customers in queue\n";
            else
            {
                front=front->getLink();
            }
        }

void Customers::drawCar(Customer<string> *ptr) {
            cout << " /--\\ " << "       It is " << ptr ->getCustomerName() << "'s car " << endl;
            cout << "|0--0-|" << "      He is"; ptr->getVip() ? : cout << " not"; 
            cout << " a vip and wants to change " << ptr ->getTiresToChange() << " tires " << endl << endl;
}

void Customers:: display() {
            Customer<string> *ptr;
            ptr = front;

            if (front == NULL)
                cout<<"No customers left\n";
            else               
            {	
                cout << endl;
                while(ptr != NULL)
                {
                    drawCar(ptr);
                    ptr=ptr->getLink();
                }
            }
        }

void Customers:: setDefault() {
     string nameTest = "customer X";
     for(int i =0; i < 4; i++) {
			nameTest += (char)(i*55);
			insert(nameTest, i*i*i%4 +1, i%2);
    	}
}
