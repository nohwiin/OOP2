#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

#ifndef UTILITY_H
#define UTILITY_H

class utility{
public:
	void gotoxy(int x, int y) { //gotoxy함수 
		COORD pos = { 2 * x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //커서숨기는 함수에 사용되는 열거형 
	void setcursortype(CURSOR_TYPE c){ //커서숨기는 함수 
		CONSOLE_CURSOR_INFO CurInfo;

		switch (c) {
		case NOCURSOR:
			CurInfo.dwSize = 1;
			CurInfo.bVisible = FALSE;
			break;
		case SOLIDCURSOR:
			CurInfo.dwSize = 100;
			CurInfo.bVisible = TRUE;
			break;
		case NORMALCURSOR:
			CurInfo.dwSize = 20;
			CurInfo.bVisible = TRUE;
			break;
		}
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
	}

	void frame(void){
		system("cls");
		int y = 2; int x = 0;
		gotoxy(x, y + 0); printf("                                 LOTTO CINEMA                                 ");
		gotoxy(x, y + 1); printf("                                BOOKING SYSTEM                                ");
		gotoxy(x, y + 3); printf("────────────────────────────────────────");
		gotoxy(x, y + 4); printf("■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■");
		gotoxy(x, y + 5); printf("────────────────────────────────────────");
		gotoxy(x, y + 17); printf("────────────────────────────────────────");
		gotoxy(x, y + 18); printf("■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■");
		gotoxy(x, y + 19); printf("────────────────────────────────────────");
	}

	int cursor_choice(int start_x, int start_y, int max){
		setcursortype(NOCURSOR);
		int x = start_x; int y = start_y;
		int pos = 0;
		gotoxy(x, y + (2 * pos)); printf("▷");

		while (1){
			if (_kbhit()){
				bool enter_flag = false;
				gotoxy(x, y + (2 * pos)); printf(" ");
				int ch = _getch();  // 키 입력 받았을 경우 키 값을 ch에 저장
				switch (ch) {
				case 80:    // 방향키 Down
					pos++;
					break;
				case 72:    // 방향키 Up
					pos--;
					break;
				case 13:
					enter_flag = true;
					break;
				}
				if (pos < 0)
					pos = max;
				else if (pos > max)
					pos = 0;
				if (enter_flag == true)
					break;
				gotoxy(x, y + (2 * pos)); printf("▷");
			}
		}
		return pos;
	}

	int cursor_choice_par(int start_x, int start_y, int max){
		setcursortype(NOCURSOR);
		int x = start_x; int y = start_y;
		int pos = 0;
		gotoxy(x + (14 * pos), y); printf("▷");

		while (1){
			if (_kbhit()){
				bool enter_flag = false;
				gotoxy(x + (14 * pos), y); printf(" ");
				int ch = _getch();  // 키 입력 받았을 경우 키 값을 ch에 저장
				switch (ch) {
				case 77:    // 방향키 Right
					pos++;
					break;
				case 75:    // 방향키 Left
					pos--;
					break;
				case 13:
					enter_flag = true;
					break;
				}
				if (pos < 0)
					pos = max;
				else if (pos > max)
					pos = 0;
				if (enter_flag == true)
					break;
				gotoxy(x + (14 * pos), y); printf("▷");
			}
		}
		return pos;
	}
};

#endif