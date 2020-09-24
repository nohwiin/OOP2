#define _SCL_SECURE_NO_WARNINGS
#include<iostream>
#include"Movie.h"
using namespace std;

Movie::Movie()
{
	this->MovieNumber = 0;		// 상영관 번호
	this->StartingTime = 0;
	this->EndTime = 0;
	setMovieName("");
	this->LeftSeats = 50;
	this->Price = 0;
	for(int i = 0; i < 50; i++)
		Seats[i] = true;	//사용가능한 좌석
}

Movie::Movie(int MovieNumber, int StartingTime, int EndTime, const string &MovieName, int LeftSeats, double Price)
{
	this->MovieNumber = MovieNumber;		// 상영관 번호
	this->StartingTime = StartingTime;
	this->EndTime = EndTime;
	setMovieName(MovieName);
	this->LeftSeats = 50;
	this->Price = Price;
	for (int i = 0; i < 50; i++)
		Seats[i] = true;	//사용가능한 좌석
}

void Movie::setMovieNumber(int MovieNumber)
{
	this->MovieNumber = MovieNumber;
}
void Movie::setStartingTime(int StartingTime)
{
	this->StartingTime = StartingTime;
}
void Movie::setEndTime(int EndTime)
{
	this->EndTime = EndTime;
}
void Movie::setMovieName(const string &MovieName)
{
	int length = MovieName.size();
	length = (length < 50 ? length : 49);		//ProductName_string에서 50자 만큼만 잘라서 가져온다.
	MovieName.copy(this->MovieName, length);
	this->MovieName[length] = '\0';				//마지막은 NULL문자를 넣어준다.
}
void Movie::setLeftSeats(int LeftSeats)
{
	this->LeftSeats = LeftSeats;
}
void Movie::setPrice(int Price)
{
	this->Price = Price;
}
void Movie::setSeats(int idx, bool av)
{
	this->Seats[idx] = av;
}

int Movie::getMovieNumber()
{
	return MovieNumber;
}
int Movie::getStartingTime()
{
	return StartingTime;
}
int Movie::getEndTime()
{
	return EndTime;
}
string Movie::getMovieName() const
{
	return MovieName;
}
int Movie::getLeftSeats()
{
	return LeftSeats;
}
double Movie::getPrice()
{
	return Price;
}
bool Movie::getSeats(int idx)
{
	return Seats[idx];
}