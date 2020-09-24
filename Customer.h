#include<iostream>
#include<vector>
#include<string>
#include"history.h"
#include"utility.h"
using namespace std;

class customer : public utility{	// 화면 UI 기능 사용을 위한 utility 상속
private:
	string masterid;		// Login ID
public:
	customer(string id){
		this->masterid = id;
	}

	void custom_main()
	{
		int choice = 0;
		while (1) {
			frame();
			custom_page_text();
			choice = cursor_choice(13, 11, 2);
			switch (choice) {
			case 0:
				frame();
				book_tickets();				// BOOK TICKETS 실행
				break;
			case 1:
				system("cls");
				confirm_information();		// CONFIRM INFORMATION 실행
				break;
			case 2:
				return;
			}
		}
	}

	void confirm_information(){
		account temp;
		history ttp;
		fstream custommer(masterid + ".dat", ios::in);											// 계정 데이터 파일(id.dat)을 열고, 
		custommer.read(reinterpret_cast<char*>(&temp), sizeof(account));						// 정보를 불러와서
		cout << "ID : " << temp.getid() << "       E-MAIL : " << temp.getemail() << endl;		// 가져온 정보를 출력한다.
		while (custommer && !custommer.eof()){										
			custommer.read(reinterpret_cast<char*>(&ttp), sizeof(history));   // id.dat 의 Booking history 를 불러온다.
			if (custommer.eof())
				break;
			cout << "─ ─ ─ ─ ─ ─ ─ ┬ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl;
			cout << "                            MOVIE NAME : " << ttp.getname() << endl;
			cout << "  LOTTO CINEMA       │  STARTING TIME : " << ttp.gettime_s() / 100 << "시 " << ttp.gettime_s() % 100 << "분" << endl;
			cout << "                              END TIME : " << ttp.gettime_e() / 100 << "시 " << ttp.gettime_e() % 100 << "분" << endl;
			cout << "                     │    SEAT NUMBER : " << ttp.getcount() << endl;
			cout << "                                 PRICE : " << ttp.getprice() << endl;															// 가져온 정보를 출력한다.
			cout << "─ ─ ─ ─ ─ ─ ─ ┴ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl;
		}
		custommer.close();
		for (;;){
			if (_kbhit())
				break; //키입력이 있으면 무한루프 종료 
		}
		_getch();
		int y = 9; int x = 0;
		int choice = 0;
		while (1) {
			frame();
			gotoxy(x, y - 1); printf("                              CONFIRM INFORMATION                                  ");
			gotoxy(x, y + 2); printf("                                 EDIT PASSWORD                                     ");
			gotoxy(x, y + 4); printf("                                  EDIT EMAIL                                       ");
			gotoxy(x, y + 6); printf("                                CANCEL TICKETS                                     ");
			gotoxy(x, y + 8); printf("                                     BACK");
			choice = cursor_choice(13, 11, 3);
			switch (choice) {
			case 0:
				frame();
				editpassword();			// EDIT PASSWORD 실행
				break;
			case 1:
				frame();
				editemail();			// EDIT EMAIL 실행
				break;
			case 2:
				system("cls");
				canceltickets();		// CANCEL TICKETS 실행
				break;
			case 3:
				return;					// BACK 실행 = 뒤로가기
			}
		}
	}

	void canceltickets(){		// CANCEL TICKETS
		account temp;
		history ttp;
		fstream custommer(masterid + ".dat", ios::in);								// id.dat 파일을 열어서
		custommer.read(reinterpret_cast<char*>(&temp), sizeof(account));			// 사용자 정보를 읽어들인 후
		int bookingnum = 0;
		while (custommer && !custommer.eof()){										// Booking history 를 계속 불러온다.
			custommer.read(reinterpret_cast<char*>(&ttp), sizeof(history));
			if (custommer.eof())
				break;
			bookingnum++;
			cout << "─ ─ ─ ─ ─ ─ ─ ┬ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl;
			cout << "                            MOVIE NAME : " << ttp.getname() << endl;
			cout << "  LOTTO CINEMA       │  STARTING TIME : " << ttp.gettime_s() / 100 << "시 " << ttp.gettime_s() % 100 << "분" << endl;
			cout << "                              END TIME : " << ttp.gettime_e() / 100 << "시 " << ttp.gettime_e() % 100 << "분" << endl;
			cout << "  #"<<setw(2)<< bookingnum <<"                 │    SEAT NUMBER : " << ttp.getcount() << endl;							// 가져온 정보의 인덱스를 적용한다. (bookingnum)
			cout << "                                 PRICE : " << ttp.getprice() << endl;
			cout << "─ ─ ─ ─ ─ ─ ─ ┴ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl;									// 가져온 정보를 출력한다.
		}
		custommer.close();
		int sel;
		cout << "SELECT NUMBER OF MOVIE : ";		// 취소할 티켓의 인덱스 번호를 입력한다.
		cin >> sel;
		if (sel<0 || sel > bookingnum){	// 예외처리
			cout << "INVALID INPUT";
			return;
		}
		else{
			history booked;
			custommer.open(masterid + ".dat", ios::in);								// id.dat 파일을 열어서,
			custommer.read(reinterpret_cast<char*>(&temp), sizeof(account));		
			bookingnum = 0;
			vector<history> Mvec;													// history 벡터에 원하는 history 만 저장.
			while (custommer && !custommer.eof()){
				custommer.read(reinterpret_cast<char*>(&ttp), sizeof(history));
				if (custommer.eof())
					break;
				bookingnum++;
				if (sel != bookingnum)
					Mvec.push_back(ttp);
				else
					booked = ttp;		// 삭제할 티켓을 booked 에 저장한다.
			}
			custommer.close();
			custommer.open(masterid + ".dat", ios::out, ios::trunc);					// id.dat 파일을 열어서,
			custommer.write(reinterpret_cast<char*>(&temp), sizeof(account));
			for (int i = 0; i < Mvec.size(); i++)
				custommer.write(reinterpret_cast<char*>(&Mvec[i]), sizeof(history));	// 선택한 티켓을 제외한 티켓을 덮어씌운다. ( ios::trunc )
			custommer.close();
			string movienumber_s = to_string(booked.getthnum());
			Movie moviebooked;
			fstream thm("Aud" + movienumber_s + ".dat", ios::in);						// 취소한 영화가 있는 Aud.dat 을 열어서,
			vector<Movie> Movievector;													
			while (thm  && !thm.eof()){
				thm.read(reinterpret_cast<char*>(&moviebooked), sizeof(Movie));
				if (booked.getname() == moviebooked.getMovieName()){					// 취소 내역을 적용한다.
					moviebooked.setLeftSeats(moviebooked.getLeftSeats() + 1);
					moviebooked.setSeats(booked.getcount() - 1, true);
				}
				Movievector.push_back(moviebooked);
				if (thm.eof())
					break;
			}
			thm.close();
			thm.open("Aud" + movienumber_s + ".dat", ios::in | ios::out);				// 변경사항을 Aud.dat 에 저장한다.
			for (int i = 1; i < Movievector.size(); i++)
				thm.write(reinterpret_cast<char*>(&Movievector[i]), sizeof(Movie));
			thm.close();
		}
	}

	void editemail(){		// EDIT EMAIL
		setcursortype(NORMALCURSOR);
		int y = 9; int x = 0;
		gotoxy(x, y - 1); printf("                                 EDIT E-MAIL                                       ");
		gotoxy(x, y + 2); printf("                   NEW E-MAIL :                                                    ");
		string email;
		gotoxy(16, 11); cin >> email;
		vector<pass> vps;
		account ps;
		fstream ep(masterid + ".dat", ios::in | ios::out | ios::binary);		// id.dat 에서 email 값만 바꿔서 저장한다.
		ep.read(reinterpret_cast<char*>(&ps), sizeof(account));
		ep.close();
		ps.setemail(email);
		ep.open(masterid + ".dat", ios::in | ios::out | ios::binary);	
		ep.write(reinterpret_cast<char*>(&ps), sizeof(account));
		ep.close();
	}

	void editpassword(){	// EDIT PASSWORD
		setcursortype(NORMALCURSOR);
		int y = 9; int x = 0;
		gotoxy(x, y - 1); printf("                                EDIT PASSWORD                                      ");
		gotoxy(x, y + 2); printf("                 NEW PASSWORD :                                                    ");
		gotoxy(x, y + 6); printf("           PASSWORD ONCE MORE :                                                    ");
		string pw, pw2;
		gotoxy(16, 11); cin >> pw;
		gotoxy(16, 15); cin >> pw2;
		if (pw != pw2){
			gotoxy(16, 15); cout << "INVALID INPUT!                                                                  ";	// 예외처리
			for (;;){
				if (_kbhit())
					break; //키입력이 있으면 무한루프 종료 
			}
			_getch();
			return;
		}
		else{
			vector<pass> vps;
			pass ps;
			fstream ep("pass.dat", ios::in | ios::out | ios::binary);		// pass.dat 에서 비밀번호를 변경하고 다시 저장한다.
			while (ep && !ep.eof()){
				ep.read(reinterpret_cast<char*>(&ps), sizeof(pass));
				if (ps.getid() == masterid)
					ps.setpassword(pw);
				vps.push_back(ps);
				if (ep.eof())
					break;
			}
			ep.close();
			ep.open("pass.dat", ios::in | ios::out | ios::binary);
			for (int i = 0; i < vps.size(); i++)
				ep.write(reinterpret_cast<char*>(&vps[i]), sizeof(pass));
			ep.close();
		}
	}

	void custom_page_text(void) {
		int y = 9; int x = 0;
		gotoxy(x, y - 1); printf("                                CUSTOMER MODE                                      ");
		gotoxy(x, y + 2); printf("                                BOOK  TICKETS                                      ");
		gotoxy(x, y + 4); printf("                             CONFIRM INFORMATION                                   ");
		gotoxy(x, y + 6); printf("                                    QUIT                                           ");
	}

	void book_tickets(){		// 예매할 상영관을 고름.
		int choice;
		int y = 10; int x = 0;
		gotoxy(x, 8);  printf("                                BOOK  TICKETS                                 ");
		gotoxy(x, 11); printf("                                AUDITORIUM  1                                 ");
		gotoxy(x, 13); printf("                                AUDITORIUM  2                                 ");
		gotoxy(x, 15); printf("                                AUDITORIUM  3                                 ");
		gotoxy(x, 17); printf("                                     BACK                                     ");
		choice = cursor_choice(13, 11, 3);
		switch (choice) {
		case 0:
			make_book(choice);
			break;
		case 1:
			make_book(choice);
			break;
		case 2:
			make_book(choice);
			break;
		case 3:
			return;
		}
	}

	void make_book(int movienumber){		// MAKE BOOK
		system("cls");
		setcursortype(NORMALCURSOR);
		movienumber = movienumber + 1;
		string movienumber_s = to_string(movienumber);
		Movie temp;
		fstream audit("Aud" + movienumber_s + ".dat", ios::in | ios::binary);		// Aud.dat 를 열어 들어있는 정보를 출력한다.
		int count = 1;
		while (audit && !audit.eof()){
			audit.read(reinterpret_cast<char*>(&temp), sizeof(Movie));
			if (audit.eof())
				break;
			cout << "─ ─ ─ ─ ─ ─ ─ ┬ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl << endl;
			cout << "  LOTTO CINEMA       │     MOVIE NAME : " << temp.getMovieName() << endl;
			cout << "  AUDITORIUM " << movienumber << "           STARTING TIME : " << temp.getStartingTime() / 100 << "시 " << temp.getStartingTime() % 100 << "분" << endl;
			cout << "  #" << setw(2) << count << "                │       END TIME : " << temp.getEndTime() / 100 << "시 " << temp.getEndTime() % 100 << "분" << endl << endl;		// 가져온 정보의 인덱스를 적용한다. (count)
			cout << "─ ─ ─ ─ ─ ─ ─ ┴ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ " << endl;
			count++;
		}
		count--;
		audit.close();
		int sn;
		cout << "PLEASE INPUT SCHEDULE NUMBER : "; cin >> sn;		// 원하는 영화 선택
		if (sn > count || sn < 1){
			cout << "INVALID INPUT";	// 예외처리
			for (;;){
				if (_kbhit())
					break; //키입력이 있으면 무한루프 종료 
			}
			_getch();
			return;
		}
		else{
			system("cls");
			showseats();
			cout << endl << "INAVAILABLE SEATS : ";		// 이미 예매된 좌석을 출력한다.
			int cnt = 0;
			Movie tmp;
			vector<Movie> tmp_vector;
			fstream delete_pass;
			delete_pass.open("Aud" + movienumber_s + ".dat", ios::in | ios::out | ios::binary);		// Aud.dat 파일에서 
			while (delete_pass && !delete_pass.eof()){
				delete_pass.read(reinterpret_cast<char*>(&tmp), sizeof(Movie));
				cnt++;
				if (sn == cnt){																		// 이미 예매된 좌석의 번호를 출력한다.
					for (int i = 0; i < 50; i++){
						if (tmp.getSeats(i) == false)
							cout << i + 1 << "  ";
					}
					cout << endl;
				}
				tmp_vector.push_back(tmp);
				if (cnt == count)
					break;
			}
			cout << "INPUT SEAT NUMBER : ";		// 예매할 좌석 번호를 입력.
			int seatnumber;
			cin >> seatnumber;
			delete_pass.close();
			if (seatnumber < 0 || seatnumber > 50 || tmp_vector[sn - 1].getSeats(seatnumber - 1) == false){
				cout << "INVALID INPUT" << endl;	// 예외처리
				return;
			}
			else{
				tmp_vector[sn - 1].setSeats(seatnumber - 1, false);							// 예매정보 적용
				tmp_vector[sn - 1].setLeftSeats(tmp_vector[sn - 1].getLeftSeats() - 1);
				delete_pass.open("Aud" + movienumber_s + ".dat", ios::out | ios::in | ios::trunc);		// Aud.dat 파일을 열어서 변경 사항을 저장.
				for (int i = 0; i < tmp_vector.size(); i++)
					delete_pass.write(reinterpret_cast<char*>(&tmp_vector[i]), sizeof(Movie));
				delete_pass.close();
				Movie movtem = tmp_vector[sn - 1];
				history histem(movtem.getMovieName(), movtem.getStartingTime(), movtem.getEndTime(), seatnumber, movtem.getPrice(), movienumber);		// 예매한 영화 정보를 가져와서
				fstream account(masterid + ".dat", ios::out | ios::app);
				account.write(reinterpret_cast<char*>(&histem), sizeof(history));																		// id.dat 파일에 저장한다.
				account.close();
			}
		}
	}

	void showseats(){
		int y = 0, x = 0;
		gotoxy(x, y - 1);  printf("                                     SEATS                                       ");
		gotoxy(0, y + 4);  printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓  S C R E E N  〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");

		gotoxy(0, y + 6);  printf("            01□□□□□05   06□□□□□□□□□□15   16□□□□□20             ");

		gotoxy(0, y + 8);  printf("            21□□□□□25   26□□□□□□□□□□35   36□□□□□40             ");

		gotoxy(0, y + 10); printf("                             41□□□□□□□□□□50                              ");
	}
};