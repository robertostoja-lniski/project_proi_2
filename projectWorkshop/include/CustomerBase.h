#ifndef CUSTOMERBASE_H_INCLUDED
#define CUSTOMERBASE_H_INCLUDED

class CustomerBase {
	
		bool vip;
		int tiresToChange;	
    public:
    	CustomerBase( int, bool);
		CustomerBase();
		~CustomerBase();
		
        bool getVip();
        int getTiresToChange();
        
        void setVip(bool);
        void setTiresToChange(int);
                
};



#endif // CUSTOMER_H_INCLUDED
