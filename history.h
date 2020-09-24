#include<iostream>
using namespace std;

#ifndef HISTORY_H
#define HISTORY_H

class history{
private:
	char name[50];
	int time_s;
	int time_e;
	int count;
	double price;
	int thnum;		// 상영관 번호
public:
	history();
	history(const string &, int, int, int, double, int);
	void setthnum(int);
	int getthnum();
	void setname(const string &);
	void settime_s(int);
	void settime_e(int);
	void setcount(int);
	void setprice(double);
	string getname() const;
	int gettime_s();
	int gettime_e();
	int getcount();
	double getprice();
};

#endif