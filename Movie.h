#pragma once
#include<iostream>
using namespace std;

#ifndef MOVIE_H
#define MOVIE_H

class Movie {
private:
	int MovieNumber;			// 상영관 번호
	int StartingTime;
	int EndTime;
	char MovieName[50];
	int LeftSeats;
	double Price;
	bool Seats[50];
	
public:
	Movie();
	Movie(int, int, int, const string &, int, double);
	
	void setMovieNumber(int MovieNumber);
	void setStartingTime(int StartingTime);
	void setEndTime(int EndTime);
	void setMovieName(const string &MovieName);
	void setLeftSeats(int LeftSeats);
	void setPrice(int Price);
	void setSeats(int idx, bool av);

	int getMovieNumber();
	int getStartingTime();
	int getEndTime();
	string getMovieName() const;
	int getLeftSeats();
	double getPrice();
	bool getSeats(int idx);
};
#endif