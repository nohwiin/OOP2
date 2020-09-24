#define _SCL_SECURE_NO_WARNINGS  
#include<iostream>
#include"pass.h"
using namespace std;

pass::pass(){
	setid("");
	setpassword("");
}
pass::pass(const string & id, const string & password){
	setid(id);
	setpassword(password);
}
string pass::getid() const{
	return id;
}
string pass::getpassword() const{
	return password;
}
void pass::setid(const string & id){
	int length = id.size();
	length = (length < 15 ? length : 14);//ProductName_string에서 15자 만큼만 잘라서 가져온다.
	id.copy(this->id, length);
	this->id[length] = '\0';//마지막은 NULL문자를 넣어준다.
}
void pass::setpassword(const string & password){
	int length = password.size();
	length = (length < 15 ? length : 14);//ProductName_string에서 15자 만큼만 잘라서 가져온다.
	password.copy(this->password, length);
	this->password[length] = '\0';//마지막은 NULL문자를 넣어준다.
}