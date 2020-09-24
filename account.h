#include<iostream>
#include"history.h"
using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class account{
private:
	char id[15];
	char email[40];
	bool authority;
public:
	account();
	account(const string &, const string &, bool);
	void setid(const string &);
	void setemail(const string &);
	void setauthority(bool);
	string getid() const;
	string getemail() const;
	bool getauthority();
};

#endif