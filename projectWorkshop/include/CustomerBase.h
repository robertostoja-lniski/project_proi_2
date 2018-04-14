#ifndef CUSTOMERBASE_H_INCLUDED
#define CUSTOMERBASE_H_INCLUDED

class CustomerBase {
	
	protected:
		bool vip;
	private:
		int tiresToChange;	
    public:
    	CustomerBase( int, bool);
		CustomerBase();
		~CustomerBase();
		
        bool getVip();
        int getTiresToChange();
        
        void setVip(bool);
        void setTiresToChange(int);
		
		virtual void showCust(std::ostream& stream) const = 0;
		friend std::ostream& operator<< (std::ostream& stream, const CustomerBase& c ) {
   				 c.showCust(stream);
				 return stream;
		}	
};



#endif // CUSTOMER_H_INCLUDED
