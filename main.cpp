#include "seat.h"

using namespace std;
#pragma comment(lib, "winmm.lib")
#define MAX_SIZE 1000

int seat::num = 4;//*
int seat::numbern = 20;//*
int seat::zonumber = 4;
int seat::genderline = 0;
int seat::studentline = 0;


int main(void) {
	seat seat;
	while (1) {
	again:
		int input, snsn;
		seat.inputinformation();
		seat.mainchang();
		cout << "원하시는 선택지를 선택해주세요. ";
		cin >> input;
		if (input != 4 && input != 6 && input != 3 && input != 5) {
			cout << "학생들의 수를 입력해주세요.";
			cin >> snsn;
			seat.numbern = snsn;
		}
		if (input == 1) seat.setseatmain();
		else if (input == 2) seat.zolottery();
		else if (input == 3) seat.danglottery();
		else if (input == 4) seat.setmember();
		else if (input == 5) seat.checkrecord();
		else if (input == 6) break;
		else if (input == 7) seat.inputinformation();
		else {
			system("cls");
			cout << "다시 입력해주세요";
			goto again;
		}
		seat.mainchang();
		system("cls");
	}
	return 0;
}

void seat::waitingchang(void) {
	system("cls");
	cout << "랜덤 추첨 중입니다. □ □ □ □ □..." << endl;
	Sleep(300);
	system("cls");
	cout << "랜덤 추첨 중입니다. ■ □ □ □ □.." << endl;
	Sleep(300);
	system("cls");
	cout << "랜덤 추첨 중입니다. ■ ■ □ □ □...." << endl;
	Sleep(300);
	system("cls");
	cout << "랜덤 추첨 중입니다. ■ ■ ■ □ □.." << endl;
	Sleep(300);
	system("cls");
	cout << "랜덤 추첨 중입니다. ■ ■ ■ ■ □..." << endl;
	Sleep(300);
	system("cls");
	cout << "랜덤 추첨 중입니다. ■ ■ ■ ■ ■" << endl;
	Sleep(200);
	system("cls");
}

void seat::mainchang()
{
	cout << "┌─────────────────────── 체 메인 화면 ────────────────────────┐" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                        1.자리 배치                          │" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                        2.조 추첨                            │" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                        3.당번 추첨                          │" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                        4.회원 설정                          │" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                        5.기록 확인                          │" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                        6.종 료                              │" << endl;
	cout << "│                                                             │" << endl;
	cout << "└─────────────────────────────────────────────────────────────┘" << endl;
}

void seat::setseatmain() {
	int op;
	system("cls");
	cout << "┌────────────────────── 자리 배치 화면 ────────────────────────┐" << endl;
	cout << "│                                                              │" << endl;
	cout << "│                                                              │" << endl;
	cout << "│                        1.자리 배치                           │" << endl;
	cout << "│                                                              │" << endl;
	cout << "│                        2.지정석 설정                         │" << endl;
	cout << "│                                                              │" << endl;
	cout << "│                        3.메인 홈	                       │" << endl;
	cout << "│                                                              │" << endl;
	cout << "└──────────────────────────────────────────────────────────────┘" << endl;
	cout << "선택지를 선택해주세요 : ";
	cin >> op;
	if (op == 1) {
		seat::setseat();
	}
	if (op == 2) {
		seat::reservedseat();
	}
}




