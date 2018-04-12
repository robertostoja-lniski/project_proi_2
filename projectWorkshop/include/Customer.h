#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include "CustomerBase.h"
template <typename T>
class Customer : public CustomerBase {
	
private:
	
		T customerName;
		Customer<T> *link;
	
public:
    	Customer( T, int, bool);
		Customer();
		~Customer();
		
		T getCustomerName();
        Customer<T>* getLink();
        
        void setCustomerName(T);
        void setLink(Customer<T>*);
                
};
template <typename T>
Customer<T>::Customer( T Name, int tiresToChange, bool vip)
		: CustomerBase( tiresToChange,  vip){
				this->customerName = Name;
}
template <typename T>
Customer<T>::Customer() {}

template <typename T>
Customer<T>* Customer<T>::getLink() {
	return this->link;
}
template <typename T>
T Customer<T>::getCustomerName() { 
	return this->customerName;
}
template <typename T>
void Customer<T>::setLink(Customer<T>* link) {
	 this->link = link;
}
template <typename T>
void Customer<T>::setCustomerName(T name) { 
	this->customerName = customerName;
}


#endif // CUSTOMER_H_INCLUDED
