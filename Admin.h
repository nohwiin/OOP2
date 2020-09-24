#include<iostream>
#include"utility.h"
#include"ManageUser.h"
#include"ManageSchedule.h"
using namespace std;

#ifndef ADMIN_H
#define ADMIN_H

class Admin : public utility {	// 화면 UI 기능 사용을 위한 utility 상속
public:
	void admin_main()
	{
		int choice = 0;
		while (1) {
			frame();
			admin_page_text();
			choice = cursor_choice(13, 12, 2);
			switch (choice) {
			case 0:
				ManageSchedule schedule;
				schedule.manageschedule_main();		// MANAGE SCHEDULE 실행
				break;
			case 1:
				ManageUser manage;
				manage.manageuser_main();			// MANAGE USER 실행
				break;
			case 2:
				return;								// QUIT 
			}
		}
	}

	void admin_page_text(void) {
		int y = 10; int x = 0;
		gotoxy(x, y - 2); printf("                             ADMINISTRATOR MODE                                    ");
		gotoxy(x, y + 2); printf("                               MANAGE SCHEDULE                                     ");
		gotoxy(x, y + 4); printf("                                 MANAGE USER                                       ");
		gotoxy(x, y + 6); printf("                                    QUIT                                           ");
	}
};

#endif