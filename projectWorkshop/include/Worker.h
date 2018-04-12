#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED

class Worker {

		std::string name;
		int speed;
		bool working;
		
public:
		Worker();
		Worker(std::string , int, bool);
		~Worker();
		std::string getName();
		int getSpeed();
		bool getWorking();
		
		void setName(std::string);
		void setSpeed(int);
		void setWorking(bool);
		bool operator< ( Worker&);	
};


#endif // WORKER_H_INCLUDED
