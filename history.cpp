#define _SCL_SECURE_NO_WARNINGS
#include<iostream>
#include"history.h"
using namespace std;

history::history(const string& name, int time_s, int time_e, int count, double price, int thnum){
	setname(name);
	this->thnum = thnum;	// 상영관 번호
	this->time_s = time_s;
	this->time_e = time_e;
	this->count = count;	// 좌석 번호
	this->price = price;
}

history::history(){
	setname("");
	this->time_s = 0;
	this->time_e = 0;
	this->count = 0;
	this->price = 0;
}

void history::setthnum(int num){
	this->thnum = num;
}

int history::getthnum(){
	return thnum;
}

void history::setname(const string &name)
{
	int length = name.size();
	length = (length < 50 ? length : 49);//ProductName_string에서 50자 만큼만 잘라서 가져온다.
	name.copy(this->name, length);
	this->name[length] = '\0';//마지막은 NULL문자를 넣어준다.
}

void history::settime_s(int time_s)
{
	this->time_s = time_s;
}

void history::settime_e(int time_e)
{
	this->time_e = time_e;
}

void history::setcount(int count)
{
	this->count = count;
}

void history::setprice(double price){
	this->price = price;
}

string history::getname() const
{
	return name;
}

int history::gettime_s()
{
	return time_s;
}

int history::gettime_e()
{
	return time_e;
}

int history::getcount()
{
	return count;
}

double history::getprice(){
	return price;
}