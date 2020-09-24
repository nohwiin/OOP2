#include<iostream>
using namespace std;

#ifndef PASS_H
#define PASS_H

class pass{
private:
	char id[15];
	char password[15];
public:
	pass();
	pass(const string &, const string &);
	string getid() const;
	string getpassword() const;
	void setid(const string &);
	void setpassword(const string &);
};

#endif