#define _SCL_SECURE_NO_WARNINGS  
#include<iostream>
#include"account.h"
using namespace std;

account::account(){
	setid("");
	setemail("");
	this->authority = false;
}
account::account(const string &id, const string &email, bool authority){
	setid(id);
	setemail(email);
	this->authority = authority;
}
void account::setid(const string &id){
	int length = id.size();
	length = (length < 15 ? length : 14);//ProductName_string에서 15자 만큼만 잘라서 가져온다.
	id.copy(this->id, length);
	this->id[length] = '\0';//마지막은 NULL문자를 넣어준다.
}
void account::setemail(const string &email){
	int length = email.size();
	length = (length < 40 ? length : 39);//ProductName_string에서 40자 만큼만 잘라서 가져온다.
	email.copy(this->email, length);
	this->email[length] = '\0';//마지막은 NULL문자를 넣어준다.
}
void account::setauthority(bool authority){
	this->authority = authority;
}
string account::getid() const{
	return id;
}
string account::getemail() const{
	return email;
}
bool account::getauthority(){
	return authority;
}