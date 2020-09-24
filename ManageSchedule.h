#pragma once
#include<fstream>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<iomanip>
#include"Movie.h"
#include"utility.h"
using namespace std;

class ManageSchedule : public utility { 	// 화면 UI 기능 사용을 위한 utility 상속
public:
	void manageschedule_main()
	{
		int choice = 0;
		while (1) {
			frame();
			manageschedule_text();
			choice = cursor_choice(13, 10, 4);
			switch (choice) {
			case 0:
				show_schedule();		// SHOW SCHEDULE
				break;
			case 1:
				frame();
				update_schedule();		// UPDATE SCHEDULE
				break;
			case 2:
				frame();
				add_schedule();			// ADD SCHEDULE
				break;
			case 3:
				frame();
				delete_schedule();		// DELETE SCHEDULE
				break;
			case 4:					
				return;					// BACK
			}
		}
	}

	void manageschedule_text()
	{
		int y = 10; int x = 0;
		gotoxy(x,  8); printf("                               MANAGE SCHEDULE                                ");
		gotoxy(x, 10); printf("                                SHOW SCHEDULE                                 ");
		gotoxy(x, 12); printf("                               UPDATE SCHEDULE                                ");
		gotoxy(x, 14); printf("                                ADD  SCHEDULE                                 ");
		gotoxy(x, 16); printf("                               DELETE SCHEDULE                                ");
		gotoxy(x, 18); printf("                                    BACK                                      ");
	}

	void show_schedule()	// SHOW SCHEDULE
	{
		system("cls");
		Movie temp;
		fstream audit("Aud1.dat", ios::in | ios::binary);						// dat 파일을 열어서 모든 상영관의 정보를 출력한다.
		while (audit && !audit.eof()){
			audit.read(reinterpret_cast<char*>(&temp), sizeof(Movie));
			if (audit.eof())
				break;
			cout << "─ ─ ─ ─ ─ ─ ─ ┬ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl << endl;
			cout << "  LOTTO CINEMA       │     MOVIE NAME : " << temp.getMovieName() << endl;
			cout << "                         STARTING TIME : " << temp.getStartingTime() / 100 << "시 " << temp.getStartingTime() % 100 << "분" << endl;
			cout << "  AUDITORIUM 1       │       END TIME : " << temp.getEndTime() / 100 << "시 " << temp.getEndTime() % 100 <<"분" << endl << endl;
			cout << "─ ─ ─ ─ ─ ─ ─ ┴ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl;
		}
		audit.close();
		audit.open("Aud2.dat", ios::in | ios::binary);
		while (audit && !audit.eof()){
			audit.read(reinterpret_cast<char*>(&temp), sizeof(Movie));
			if (audit.eof())
				break;
			cout << "─ ─ ─ ─ ─ ─ ─ ┬ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl << endl;
			cout << "  LOTTO CINEMA       │     MOVIE NAME : " << temp.getMovieName() << endl;
			cout << "                         STARTING TIME : " << temp.getStartingTime() / 100 << "시 " << temp.getStartingTime() % 100 << "분" << endl;
			cout << "  AUDITORIUM 2       │       END TIME : " << temp.getEndTime() / 100 << "시 " << temp.getEndTime() % 100 << "분" << endl << endl;
			cout << "─ ─ ─ ─ ─ ─ ─ ┴ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl;
		}
		audit.close();
		audit.open("Aud3.dat", ios::in | ios::binary);
		while (audit && !audit.eof()){
			audit.read(reinterpret_cast<char*>(&temp), sizeof(Movie));
			if (audit.eof())
				break;
			cout << "─ ─ ─ ─ ─ ─ ─ ┬ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl << endl;
			cout << "  LOTTO CINEMA       │     MOVIE NAME : " << temp.getMovieName() << endl;
			cout << "                         STARTING TIME : " << temp.getStartingTime() / 100 << "시 " << temp.getStartingTime() % 100 << "분" << endl;
			cout << "  AUDITORIUM 3       │       END TIME : " << temp.getEndTime() / 100 << "시 " << temp.getEndTime() % 100 << "분" << endl << endl;
			cout << "─ ─ ─ ─ ─ ─ ─ ┴ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl;
		}
		audit.close();
		for (;;){
			if (_kbhit())
				break; //키입력이 있으면 무한루프 종료 
		}
		_getch();
	}

	void update_schedule()		// UPDATE SCHEDULE
	{
		int number = delete_schedule();				// SCHEDULE 삭제
		while (make_schedule(number) != true){}		// SCHEDULE 생성, 이 때 오류가 발생하면 생성될 때 까지 반복
	}

	void add_schedule()			// ADD SCHEDULE
	{
		int choice;
		int y = 10; int x = 0;
		gotoxy(x, 8);  printf("                                ADD  SCHEDULE                                 ");
		gotoxy(x, 11); printf("                                AUDITORIUM  1                                 ");
		gotoxy(x, 13); printf("                                AUDITORIUM  2                                 ");
		gotoxy(x, 15); printf("                                AUDITORIUM  3                                 ");
		gotoxy(x, 17); printf("                                     BACK                                     ");
		choice = cursor_choice(13, 11, 3);
		switch (choice) {				// 상영관 선택
		case 0:
			make_schedule(choice);
			break;
		case 1:
			make_schedule(choice);
			break;
		case 2:
			make_schedule(choice);
			break;
		case 3:
			return;
		}
	}

	int delete_schedule()			// DELETE SCHEDULE
	{
		int choice;
		int y = 10; int x = 0;
		gotoxy(x, 8);  printf("                               UPDATE SCHEDULE                                 ");
		gotoxy(x, 11); printf("                                AUDITORIUM  1                                 ");
		gotoxy(x, 13); printf("                                AUDITORIUM  2                                 ");
		gotoxy(x, 15); printf("                                AUDITORIUM  3                                 ");
		gotoxy(x, 17); printf("                                     BACK                                     ");
		choice = cursor_choice(13, 11, 3);
		system("cls");
		switch (choice) {			// 상영관 선택
		case 0:
			del_schedule(choice);
			return 0;
		case 1:
			del_schedule(choice);
			return 1;
		case 2:
			del_schedule(choice);
			return 2;
		case 3:
			return 3;
		}
	}

	void del_schedule(int movienumber){		// DEL SCHEDULE
		setcursortype(NORMALCURSOR);		// 커서 보이게 설정
		movienumber = movienumber + 1;
		string movienumber_s = to_string(movienumber);
		Movie temp;
		fstream audit("Aud" + movienumber_s + ".dat", ios::in | ios::binary);			// Aud.dat 파일을 열어서 모든 정보를 출력한다.
		int count = 1;
		while (audit && !audit.eof()){
			audit.read(reinterpret_cast<char*>(&temp), sizeof(Movie));
			if (audit.eof())
				break;
			cout << "─ ─ ─ ─ ─ ─ ─ ┬ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl << endl;
			cout << "  LOTTO CINEMA       │     MOVIE NAME : " << temp.getMovieName() << endl;
			cout << "  AUDITORIUM " << movienumber << "           STARTING TIME : " << temp.getStartingTime() / 100 << "시 " << temp.getStartingTime() % 100 << "분" << endl;
			cout << "  #" << setw(2) << count << "                │       END TIME : " << temp.getEndTime() / 100 << "시 " << temp.getEndTime() % 100 << "분" << endl << endl;		// index 값을 적용 (count)
			cout << "─ ─ ─ ─ ─ ─ ─ ┴ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl;
			count++;
		}
		count--;
		audit.close();
		int sn;
		cout << "PLEASE INPUT SCHEDULE NUMBER(INPUT 0 = ADD SCHEDULE) : "; cin >> sn;			// 삭제할 스케쥴 인덱스 입력 ( 0 일 경우 스케쥴 생성 )
		if (sn == 0){}
		else if (sn > count || sn < 1){
			cout << "INVALID INPUT";		// 예외처리
			for (;;){
				if (_kbhit())
					break; //키입력이 있으면 무한루프 종료 
			}
			_getch();
		}
		else{
			int cnt = 0;
			Movie tmp;
			vector<Movie> tmp_vector;
			fstream delete_pass;
			delete_pass.open("Aud" + movienumber_s + ".dat", ios::in | ios::out | ios::binary);			// Aud.dat 파일을 열어서 선택한 영화를 제외한 나머지 영화를 벡터에 저장.
			while (delete_pass && !delete_pass.eof()){
				delete_pass.read(reinterpret_cast<char*>(&tmp), sizeof(Movie));
				cnt++;
				if (sn != cnt)
					tmp_vector.push_back(tmp);
				if (cnt == count)
					break;
			}
			delete_pass.close();
			delete_pass.open("Aud" + movienumber_s + ".dat", ios::out | ios::in | ios::trunc);			// 벡터에 저장된 영화들을 Aud.dat 파일에 덮어씌운다. ( ios::trunc )
			for (int i = 0; i < tmp_vector.size(); i++)
				delete_pass.write(reinterpret_cast<char*>(&tmp_vector[i]), sizeof(Movie));
			delete_pass.close();
		}
	}

	bool make_schedule(int movienumber){		// MAKE SCHEDULE
		frame();
		setcursortype(NORMALCURSOR);	// 커서 보이게 설정
		int y = 8; int x = 0;
		gotoxy(x, y + 0); printf("                                 ADD SCHEDULE                                 ");
		gotoxy(x, y + 3); printf("                  MOVIE NAME :                                                ");
		gotoxy(x, y + 4); printf("                                                                              ");
		gotoxy(x, y + 5); printf("               STARTING TIME :                                                ");
		gotoxy(x, y + 6); printf("                              Ex) 2016 = 20 : 16                              ");
		gotoxy(x, y + 7); printf("                    END TIME :                                                ");
		gotoxy(x, y + 8); printf("                                                                              ");
		gotoxy(x, y + 9); printf("                       PRICE : ");

		movienumber = movienumber + 1;
		string movienumber_s = to_string(movienumber);		// int 값을 string 으로 변환하여 저장

		fstream audit("Aud" + movienumber_s + ".dat", ios::out | ios::in | ios::binary);		

		string moviename;
		x = 16; y = 11;
		gotoxy(x, y); cin >> moviename; //띄어쓰기를 쓰면 오류가 발생
		y = 13;
		int startingtime, endtime;
		double price;
		gotoxy(x, y); cin >> startingtime;
		if (startingtime / 100 < 0 || startingtime / 100 > 24 || startingtime % 100 < 0 || startingtime % 100 > 60){
			gotoxy(x, y); cout << "Invalid input                                    ";		// 예외처리
			for (;;){
				if (_kbhit())
					break; //키입력이 있으면 무한루프 종료 
			}
			_getch();
			return false;	// 생성 실패 ( =false )
		}
		gotoxy(x, y + 2); cin >> endtime;
		if (endtime / 100 < 0 || endtime / 100 > 24 || endtime % 100 < 0 || endtime % 100 > 60 || endtime < startingtime){
			gotoxy(x, y); cout << "Invalid input                                    ";		// 예외처리
			for (;;){
				if (_kbhit())
					break; //키입력이 있으면 무한루프 종료 
			}
			_getch();
			return false;	// 생성 실패 ( =false )
		}
		gotoxy(x, y + 4); cin >> price;		// price 입력

		bool error_flag = false;		// 에러 발생 여부 확인
		Movie temp;
		while (audit && !audit.eof()){
			audit.read(reinterpret_cast<char*>(&temp), sizeof(Movie));
			if (temp.getStartingTime() < startingtime && temp.getEndTime() > startingtime){
				frame();
				setcursortype(NOCURSOR);
				gotoxy(1, 12);    printf("                              INVALID INPUT                                   ");
				gotoxy(1, 14);    printf("                             TIME  OVERLAPS!                                  ");		//  영화 시간이 겹칠 경우 예외처리
				for (;;){
					if (_kbhit())
						break; //키입력이 있으면 무한루프 종료 
				}
				_getch();
				audit.close();
				error_flag = true;	// 에러 발생
				break;
			}
			else if (temp.getStartingTime() < endtime && temp.getEndTime() > endtime){
				frame();
				setcursortype(NOCURSOR);
				gotoxy(1, 12);    printf("                              INVALID INPUT                                   ");
				gotoxy(1, 14);    printf("                             TIME  OVERLAPS!                                  ");		// 영화 시간이 겹칠 경우 예외처리
				for (;;){
					if (_kbhit())
						break; //키입력이 있으면 무한루프 종료 
				}
				_getch();
				audit.close();
				error_flag = true;	// 에러 발생
				break;
			}
		}
		if (error_flag == false){	// 에러가 발생하지 않았으면
			audit.close();
			audit.open("Aud" + movienumber_s + ".dat", ios::out | ios::in | ios::binary | ios::app);		// Aud.dat 파일에 이어쓰기 ( ios::app )
			temp.setMovieNumber(movienumber);
			temp.setEndTime(endtime);
			temp.setMovieName(moviename);
			temp.setPrice(price);
			temp.setStartingTime(startingtime);
			audit.write(reinterpret_cast<char*>(&temp), sizeof(Movie));
			audit.close();
			return true;													// 파일 생성 성공
		}
		else
			return false;													// 파일 생성 실패
	}
};