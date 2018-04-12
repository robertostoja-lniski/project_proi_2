#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

class Box {
	
		bool available;
		std::string custName;
		std::string workerName;
		int time;
		int workerSpeed;
public:
		Box();
		Box(bool, string, string, int, int);
		bool getAvailable();
		std::string getCustName();
		std::string getWorkerName();
		int getTime();
		int getWorkerSpeed();
		void setAvailable(bool);
		void setCustName(string);
		void setWorkerName(string);
		void setTime(int);
		void setWorkerSpeed(int);		
};

#endif // BOX_H_INCLUDED
