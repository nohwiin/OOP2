#include<iostream>
#include<string>
#include<fstream>
#include"utility.h"
#include"account.h"
#include"pass.h"
#include"Admin.h"
#include"Customer.h"
using namespace std;

#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

class main_page : public utility{
public:
	main_page(){
		setcursortype(NOCURSOR);
		int x = 5; //타이틀화면이 표시되는 x좌표 
		int y = 4; //타이틀화면이 표시되는 y좌표  

		gotoxy(x, y + 0); printf("┌─────────────────────────────┐"); Sleep(50);
		gotoxy(x, y + 1); printf("│                                                          │"); Sleep(50);
		gotoxy(x, y + 2); printf("│        ■■         ■■     ■■■■■     ■■■■     │"); Sleep(50);
		gotoxy(x, y + 3); printf("│      ■■■■     ■■■■   ■■    ■■ ■■■■■■   │"); Sleep(50);
		gotoxy(x, y + 4); printf("│    ■■    ■■ ■■    ■■ ■■    ■■ ■■    ■■   │"); Sleep(50);
		gotoxy(x, y + 5); printf("│    ■■    ■■ ■■    ■■ ■■■■■         ■■     │"); Sleep(50);
		gotoxy(x, y + 6); printf("│    ■■    ■■ ■■    ■■ ■■             ■■       │"); Sleep(50);
		gotoxy(x, y + 7); printf("│    ■■    ■■ ■■    ■■ ■■           ■■         │"); Sleep(50);
		gotoxy(x, y + 8); printf("│      ■■■■     ■■■■   ■■         ■■    ■■   │"); Sleep(50);
		gotoxy(x, y + 9); printf("│        ■■         ■■     ■■         ■■■■■■   │"); Sleep(50);
		gotoxy(x, y + 10); printf("│                                                          │"); Sleep(50);
		gotoxy(x, y + 11); printf("│                          final project _ LOTTO CINEMA    │"); Sleep(50);
		gotoxy(x, y + 12); printf("│                                                          │"); Sleep(50);
		gotoxy(x, y + 13); printf("│                                       12151379 노휘인    │"); Sleep(50);
		gotoxy(x, y + 14); printf("│                                       12151502 최한호    │"); Sleep(50);
		gotoxy(x, y + 15); printf("│                                                          │"); Sleep(50);
		gotoxy(x, y + 16); printf("└─────────────────────────────┘"); Sleep(50);

		for (;;){
			if (_kbhit()){
				system("cls");
				break; //키입력이 있으면 무한루프 종료 
			}
		}
		_getch();
	}
	void main_page_text(void){
		int y = 10; int x = 0;
		gotoxy(x, y + 0); printf("                                    LOGIN                                     ");
		gotoxy(x, y + 2); printf("                                 NEW ACCOUNT                                  ");
		gotoxy(x, y + 4); printf("                                FIND PASSWORD                                 ");
		gotoxy(x, y + 6); printf("                                    QUIT                                      ");
	}

	void new_account(void){
		setcursortype(NORMALCURSOR);
		int x = 0; int y = 8;
		string id;
		string pw;
		string email;
		gotoxy(x, y + 0); printf("                                 NEW ACCOUNT                                  ");
		gotoxy(x, y + 3); printf("                          ID :                                                ");
		gotoxy(x, y + 4); printf("                                                                IF YOU WANT TO");
		gotoxy(x, y + 5); printf("                    PASSWORD :                                                ");
		gotoxy(x, y + 6); printf("                                                                 GO MAIN MENU,");
		gotoxy(x, y + 7); printf("          PASSWORD ONCE MORE :                                                ");
		gotoxy(x, y + 8); printf("                                                             PLEASE INPUT back");
		gotoxy(x, y + 9); printf("                      E-MAIL : ");

		id = new_account_id();
		// id 입력
		if (id == "back")
			return;
		pw = new_account_pw();
		// pw 입력
		if (pw == "back")
			return;
		gotoxy(16, 17); cin >> email;
		if (email == "back")
			return;
		ofstream outaccount(id + ".dat", ios::out | ios::binary);			// id.dat 를 열어서

		if (!outaccount){
			cerr << "File could not be opened." << endl;	// 예외처리
			exit(EXIT_FAILURE);
		}

		account temp(id, email, false);		// authority 는 default 값으로 Customer (=false).

		outaccount.write(reinterpret_cast<const char *>(&temp), sizeof(account));	// 계정을 생성한다.

		outaccount.close();

		ofstream outaccount2("pass.dat", ios_base::out | ios_base::app | ios_base::binary);	// pass.dat 파일을 열어서 정보 저장 ( 이어쓰기 ; ios::app )

		if (!outaccount2){
			cerr << "File could not be opened." << endl;	// 예외처리
			exit(EXIT_FAILURE);
		}

		pass tmp(id, pw);
		outaccount2.write(reinterpret_cast<const char *>(&tmp), sizeof(pass));
		outaccount2.close();
	}

	string new_account_id(void){
		string id;
		string passid;
		int x, y;

		x = 16; y = 11;
		gotoxy(x, y); cin >> id;		// id 입력
		passid = id + ".dat";			// 입력한 값과 ".dat" 을 passid 에 저장
		ofstream id_check;
		id_check.open(passid, ios::out | ios::in);		// id.dat 파일을 열되, 없으면 만들지 않는다. ( ios::in )
		if (id_check)
		{
			id_check.close();
			gotoxy(x - 16, y); printf("                          ID : THIS ID ALREADY EXISTS!");	 // 중복된 ID 있을 경우 예외처리

			for (;;){
				if (_kbhit()){
					cin.clear();
					cin.ignore();
					break; //키입력이 있으면 무한루프 종료 
				}
			}
			_getch();

			gotoxy(0, 11); printf("                          ID :                                                ");
			id = new_account_id();		// 재귀함수로 ID를 다시 입력받는다.
		}
		else
			id_check.close();

		return id;
	}
	string new_account_pw(void)
	{
		string pw, pw2;
		int x = 0, y = 0;

		x = 16; y = 13;
		for (int i = 0; i < 5; i++)
		{
			fflush(stdin);
		}
		gotoxy(x, y);	cin >> pw;			// PW 입력
		if (pw == "back")											// back 를 입력하면 이전 메뉴로 이동한다.
			return "back";
		gotoxy(x, y + 2);	cin >> pw2;
		if (pw2 == "back")
			return "back";
		if (pw != pw2){
			gotoxy(x - 16, y + 2); printf("          PASSWORD ONCE MORE : PASSWORD INCORRECT!");	    // 예외처리 ; PW 와 PW2 가 같지 않을 경우.
			for (;;){
				if (_kbhit())
					break; //키입력이 있으면 무한루프 종료 
			}
			_getch();

			gotoxy(0, 13); printf("                    PASSWORD :                                                ");
			gotoxy(0, 15); printf("          PASSWORD ONCE MORE :                                                ");
			pw = new_account_pw();  // 재귀함수로 PW를 다시 입력 받는다.
		}

		return pw;
	}

	void Find_Password(void){			// FIND PASSWORD
		setcursortype(NORMALCURSOR);	// 커서를 보이게 설정.
		int x = 0; int y = 8;
		string id;
		string pw;
		string email;
		gotoxy(x, y + 0); printf("                                FIND PASSWORD                                  ");
		gotoxy(x, y + 3); printf("                          ID :                                                 ");
		gotoxy(x, y + 7); printf("                      E-MAIL :                                                 ");

		find_Password_input();
		// id, email 입력
	}
	void find_Password_input(void)
	{
		string id;
		string email;
		string passid;
		int x, y;

		account account_temp;

		x = 16; y = 11;
		gotoxy(x, y);     cin >> id;
		gotoxy(x, y + 4); cin >> email;
		passid = id + ".dat";
		fstream id_check;
		id_check.open(passid, ios::out | ios::in);		// id.dat 파일을 열되, 파일이 없으면 만들지 않는다. ( ios::in )
		if (!id_check)
		{
			gotoxy(0, 11); printf("                                                                          ");
			gotoxy(0, 13); printf("                      THIS INFORMATION DOES NOT EXISTS!                   ");		// 예외처리
			gotoxy(0, 15); printf("                                                                          ");

			for (;;){
				if (_kbhit()){
					cin.clear();
					cin.ignore();
					break; //키입력이 있으면 무한루프 종료 
				}
			}
			_getch();
		}
		else
		{
				id_check.read(reinterpret_cast<char*> (&account_temp), sizeof(account));		// dat 파일에서 가져온 email 이 입력한 값과 같으면
				if (account_temp.getemail() != "")
				{
					if (account_temp.getemail() == email)
					{
						fstream password;
						password.open("pass.dat", ios::out | ios::in);							// pass.dat 파일에서 비밀번호를 가져와서

						pass pass_temp;

						while (password && !password.eof())
						{
							password.read(reinterpret_cast<char*> (&pass_temp), sizeof(pass));
							if (pass_temp.getid() == account_temp.getid())
							{
								frame();
								gotoxy(0, 8);  printf("                                 FIND PASSWORD                                  ");
								gotoxy(0, 13); printf("                      YOUR PASSWORD IS : "); cout << pass_temp.getpassword();			// 가져온 비밀번호를 출력한다.
								for (;;){
									if (_kbhit()){
										cin.clear();
										cin.ignore();
										_getch();
										break; //키입력이 있으면 무한루프 종료 
									}
								}
								break;
							}
						}
						password.close();
						id_check.close();
					}
					else
					{
						gotoxy(0, 11); printf("                                                                          ");
						gotoxy(0, 13); printf("                      THIS INFORMATION DOES NOT EXISTS!                   ");		// 예외처리
						gotoxy(0, 15); printf("                                                                          ");

						for (;;){
							if (_kbhit()){
								cin.clear();
								cin.ignore();
								break; //키입력이 있으면 무한루프 종료 
							}
						}
						_getch();
					}
				}
				else
				{
					gotoxy(0, 11); printf("                                                                          ");
					gotoxy(0, 13); printf("                      THIS INFORMATION DOES NOT EXISTS!                   ");		// 예외처리
					gotoxy(0, 15); printf("                                                                          ");

					for (;;){
						if (_kbhit()){
							cin.clear();
							cin.ignore();
							break; //키입력이 있으면 무한루프 종료 
						}
					}
					_getch();
				}
				id_check.close();
		}
	}

	void log_in(void){					// LOGIN
		setcursortype(NORMALCURSOR);
		int x = 0; int y = 8;
		string id;
		string pw;
		gotoxy(x, y + 0); printf("                                    LOGIN                                     ");
		gotoxy(x, y + 4); printf("                          ID :                                                ");
		gotoxy(x, y + 7); printf("                    PASSWORD :                                                ");

		gotoxy(16, 12); cin >> id;
		gotoxy(16, 15); cin >> pw;

		pass temp;
		account tmp;
		bool id_flag = false;		// ID 존재 여부
		bool pw_flag = false;		// PW 가 맞는지 아닌지 여부
		ifstream datafile;
		datafile.open("pass.dat", ios::out | ios::binary);					// pass.dat 파일에서
		while (datafile && !datafile.eof()){
			datafile.read(reinterpret_cast<char*>(&temp), sizeof(pass));
			if (temp.getid() == id){										
				id_flag = true;												// id 일치
				if (temp.getpassword() == pw){
					pw_flag = true;											// PW 일치
					break;
				}
				else
					break;
			}
		}
		datafile.close();


		if (!id_flag){					// id 틀릴 경우 예외처리.
			gotoxy(0, 12); printf("                                                                  ");
			gotoxy(0, 15); printf("                                                                  ");
			gotoxy(10, 13); cout << "Account does not exist or is incorrect.";
			for (;;){
				if (_kbhit())
					break; //키입력이 있으면 무한루프 종료 
			}
			_getch();
			return;
		}
		else{
			if (!pw_flag){				// pw 틀릴 경우 예외처리.
				gotoxy(0, 12); printf("                                                                  ");
				gotoxy(0, 15); printf("                                                                  ");
				gotoxy(10, 13); cout << "       Password is incorrect.";
				for (;;){
					if (_kbhit())
						break; //키입력이 있으면 무한루프 종료 
				}
				_getch();
				return;
			}
			else{
				ifstream idfile;
				idfile.open(id + ".dat", ios::out | ios::binary);				
				idfile.read(reinterpret_cast<char*>(&tmp), sizeof(account));
				if (tmp.getauthority()){		// 권한이 Admin 일 경우
					idfile.close();
					Admin ad;
					ad.admin_main();			// Admin 계정으로 로그인.
				}
				else{
					//고객권한으로 로그인.
					idfile.close();
					customer custom(id);
					custom.custom_main();
				}
			}
			return;
		}
		return;
	}
};

#endif