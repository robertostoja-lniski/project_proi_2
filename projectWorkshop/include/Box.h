#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

class Box {
	
		bool available;
		bool vip;
		std::string custName;
		std::string workerName;
		int time;
		int workerSpeed;
public:
		Box();
		Box(bool, std::string, std::string, int, int);
		bool getAvailable();
		bool getVip();
		std::string getCustName();
		std::string getWorkerName();
		int getTime();
		int getWorkerSpeed();
		void setAvailable(bool);
		void setVip(bool);
		void setCustName(std::string);
		void setWorkerName(std::string);
		void setTime(int);
		void setWorkerSpeed(int);		
};

#endif // BOX_H_INCLUDED
