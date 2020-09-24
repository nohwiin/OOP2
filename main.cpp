#include<iostream>
#include"main_page.h"
using namespace std;

int main(){
	main_page page;
	int choice = 0;
	while (1){
		page.frame();
		page.main_page_text();
		choice = page.cursor_choice(13, 10, 3);	// 커서 초이스 ( 화살표키로 이동 가능 )
		switch (choice){
		case 0:
			page.frame();
			page.log_in();			// Login 실행
			break;
		case 1:
			page.frame();
			page.new_account();		// New Account 실행
			break;
		case 2:
			page.frame();
			page.Find_Password();	// Find Password 실행
			break;
		case 3:
			return 0;				// Quit 실행 = 프로그램 종료
		}
	}
}