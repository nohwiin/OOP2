#pragma warning(disable:4996)
#include<iostream>
#include<stdio.h>
#include<vector>
#include"utility.h"
using namespace std;

class ManageUser : public utility{	// 화면 UI 기능 사용을 위한 utility 상속
public:
	void manageuser_main()
	{
		int choice = 0;
		while (1) {
			frame();
			manageuser_text();
			choice = cursor_choice(13, 11, 3);
			switch (choice) {
			case 0:
				frame();
				set_authority();		// SET AUTHORITY
				break;
			case 1:
				show_user_list();		// SHOW USER LIST
				break;
			case 2:
				frame();
				delete_user();			// DELETE USER
				break;
			case 3:
				return;					// BACK
			}
		}
	}

	void manageuser_text(void) {
		int y = 11; int x = 0;
		gotoxy(x, y - 3); printf("                                 MANAGE USER                                  ");
		gotoxy(x, y + 0); printf("                                SET AUTHORITY                                 ");
		gotoxy(x, y + 2); printf("                               SHOW  USER LIST                                ");
		gotoxy(x, y + 4); printf("                                 DELETE USER                                  ");
		gotoxy(x, y + 6); printf("                                    BACK                                      ");
	}

	void set_authority(){		// SET AUTHORITY
		string id;
		string passid;
		int y = 8; int x = 0;
		gotoxy(x, y + 0); printf("                                SET AUTHORITY                                 ");
		gotoxy(x, y + 4); printf("                          ID :                                                ");
		gotoxy(16, 12); cin >> id;		// ID 입력 받음
		passid = id + ".dat";
		fstream id_check;
		account temp;
		id_check.open(passid, ios::out | ios::in);		// id.dat 파일을 열되 없으면 생성하지 않음( ios::in )
		if (!id_check){
			gotoxy(0, 16);printf("                  Account does not exist or is incorrect.                     ");		// ID 가 존재하지 않을 경우
			for (;;){
				if (_kbhit())
					break; //키입력이 있으면 무한루프 종료 
			}
			_getch();
			id_check.close();
			return;
		}
		else{
			id_check.read(reinterpret_cast<char*>(&temp), sizeof(account));
			gotoxy(0, 16); printf("                   ADMINISTRATOR               USER                       ");		// ID 가 존재할 경우 권한을 선택
			id_check.close();
			int choice = 0;
			choice = cursor_choice_par(8, 16, 1);		// 가로 선택 커서
			switch (choice){
			case 0:
				temp.setauthority(true);		// Admin 권한 부여
				break;
			case 1:
				temp.setauthority(false);		// Customer 권한 부여
				break;
			}
			id_check.open(passid, ios::out | ios::in);
			id_check.write(reinterpret_cast<char*>(&temp), sizeof(account));		// 변경된 사항 저장
			id_check.close();
		}
	}
	void delete_user(){		// DELETE USER
		string id;
		string passid;
		int y = 8; int x = 0;
		gotoxy(x, y + 0); printf("                                 DELETE USER                                  ");
		gotoxy(x, y + 4); printf("                          ID :                                                ");
		gotoxy(16, 12); cin >> id;		// ID 입력 받음
		passid = id + ".dat";
		char* passid2 = (char*)passid.c_str();
		fstream id_check;
		account temp;
		id_check.open(passid, ios::out | ios::in);		// id.dat 파일을 열되 없으면 생성하지 않음( ios::in )
		if (!id_check){
			gotoxy(0, 16); printf("                  Account does not exist or is incorrect.                     ");	// ID 가 존재하지 않을 경우
			for (;;){
				if (_kbhit())
					break; //키입력이 있으면 무한루프 종료 
			}
			_getch();
			id_check.close();
			return;
		}
		else{																											// ID 가 존재할 경우 유저 정보를 삭제한다.
			id_check.close();
			remove(passid2);				// id.dat 파일 삭제
			pass tmp;
			vector<pass> tmp_vector;
			fstream delete_pass;
			delete_pass.open("pass.dat", ios::out | ios::in);
			while (delete_pass && !delete_pass.eof()){
				delete_pass.read(reinterpret_cast<char*>(&tmp), sizeof(pass));
				if (tmp.getid() != id)														// 삭제할 유저를 제외한 유저의 정보를 벡터에 저장 
					tmp_vector.push_back(tmp);
				}
			delete_pass.close();
			delete_pass.open("pass.dat", ios::out | ios::in | ios::trunc);					// 벡터에 저장된 유저의 정보를 덮어씌운다 ( ios::trunc )
			for (int i = 0; i < tmp_vector.size(); i++)
				delete_pass.write(reinterpret_cast<char*>(&tmp_vector[i]), sizeof(pass));
			delete_pass.close();
		}
	}
	void show_user_list(){		// SHOW USER LIST
		system("cls");
		string passid;
		pass temp;
		account tmp;
		fstream user_list;
		fstream user_info;
		user_list.open("pass.dat", ios::out | ios::in);									// pass.dat 파일을 열되, 존재하지 않을 경우 파일을 생성하지 않는다. ( ios::in )
		while (user_list && !user_list.eof()){
			user_list.read(reinterpret_cast<char*>(&temp), sizeof(pass));				// pass.dat 에서 id 를 가져오고
			passid = temp.getid() + ".dat";
			user_info.open(passid, ios::out | ios::in);									
			user_info.read(reinterpret_cast<char*>(&tmp), sizeof(account));				// 가져온 id 로 id.dat 를 열어 id 와 email 을 출력한다.
			if (user_list.eof())
				break;
			cout << "─ ─ ─ ─ ─ ─ ─ ┬ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl << endl;
			cout << "  LOTTO CINEMA       │  ID : " << tmp.getid() << endl << endl;
			cout << "  USER INFORMATION   │  E-MAIL : " << tmp.getemail() << endl << endl;
			cout << "─ ─ ─ ─ ─ ─ ─ ┴ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl;				// 가져온 정보를 출력한다.
			user_info.close();
		}
		user_list.close();
		for (;;){
			if (_kbhit())
				break; //키입력이 있으면 무한루프 종료 
		}
		_getch();
	}
};