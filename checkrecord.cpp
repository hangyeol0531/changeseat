#include "seat.h"

void seat::checkrecord() {

	system("cls");
	int input;
	cout << "┌─────────────────────── 체 기록 확인 ────────────────────────┐" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                        1.기록 확인                          │" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                        2.메인 홈                            │" << endl;
	cout << "│                                                             │" << endl;
	cout << "└─────────────────────────────────────────────────────────────┘" << endl;
	cout << "원하시는 선택지를 선택해주세요. ";
	cin >> input;

	if (input == 1) {
		system("cls");
		cout << "┌─────────────────────── 체 기록 확인 ────────────────────────┐" << endl;
		cout << "│                                                             │" << endl;
		cout << "│                                                             │" << endl;
		cout << "│                        1.자리 기록 확인                     │" << endl;
		cout << "│                                                             │" << endl;
		cout << "│                        2.조 기록 확인                       │" << endl;
		cout << "│                                                             │" << endl;
		cout << "│                        3.당번 기록 확인                     │" << endl;
		cout << "│                                                             │" << endl;
		cout << "│                        4.메인 홈                            │" << endl;
		cout << "│                                                             │" << endl;
		cout << "└─────────────────────────────────────────────────────────────┘" << endl;
		cout << "원하시는 선택지를 선택해주세요. ";
		cin >> input;

		int recoardarr[50] = { 0, };
		int recoardnum;
		int over[30] = { 0, };
		int n = 0;
		if (input == 1) {
			ifstream i1File("setrecord.txt");
			int studentnum = 0;
			//기록 배열에 넣기
			int reread[30] = { 0, };
			while (!i1File.eof()) {
				i1File >> reread[n];
				n++;
			}

			n = 0;
			recoardnum = reread[0];
			studentnum = reread[1];

			for (int j = 2; j < studentnum + 2; j++) {
				over[j - 2] = reread[j];
			}
			i1File.close();
			int a = 0;
			cout.fill('0');
			system("cls");
			cout << "┌────────────────────────────────── 추첨 결과 ─────────────────────────────────┐" << endl;
			for (int q = 0; q < studentnum; ++q) {
				if (a % recoardnum == 0)
				{
					cout << endl << "│            ";
				}
				cout.width(2);
				cout << stna[over[q] - 1] << "   ";
				if (a != a / recoardnum && a % recoardnum == 5)
				{
					cout << "            │" << endl;
				}
				a++;
			}
			cout << endl;
			cout << "└──────────────────────────────────────────────────────────────────────────────┘" << endl;
			cout << "아무키나 입력하면 메인화면으로 이동합니다.";
			getch();
		}

		if (input == 3) {
			ifstream i1File("dangrecord.txt");
			int studentnum = 0;
			int dangnum = 0;
			int reread[30] = { 0, };
			int c = 1;

			while (!i1File.eof()) {
				i1File >> reread[n];
				n++; 
			}
			studentnum = reread[0];
			dangnum = reread[1];
			//기록 배열에 넣기
			//		int recoardarr[100] = { 0, };
			//		int recoardnum;
			system("cls");
			cout << "───────────────당번 추첨 기록───────────────" << endl;
			for (int i = 0; i < dangnum; i++) {
				cout << c << ". " << stna[reread[i + 2]] << endl;
				c++;
			}
			i1File.close();
			cout << "────────────────────────────────────────────" << endl;
			cout << endl << endl;
			cout << "아무키나 입력하면 메인화면으로 이동합니다.";
			getch();
		}

		if (input == 2) {
			system("cls");
			ifstream i1File("zorecord.txt");
			int n = 0;
			int zonumber = 0;
			int studentnum = 0;
			int reread[30] = { 0, };
			int zonum[30] = { 0, };
			//기록 배열에 넣기
			while (!i1File.eof()) {
				i1File >> reread[n];
				n++;
			}
			zonumber = reread[0];
			studentnum = reread[1];

			for (int i = 2; i < studentnum + 2; i++) {
				zonum[i - 2] = reread[i];
			}
			i1File.close();

			int a = 0;
			int zocount = 0;
			cout.fill('0');
			cout << "─────────────── 조 추첨 기록───────────────" << endl;
			for (int i = 0; i < studentnum; ++i) {

				if (a % zonumber == 0)
				{
					zocount++;
					cout << endl << endl;
					cout << zocount << "조 :  ";
				}
				cout.width(2);
				cout << stna[zonum[i] - 1] << "  ";
				a++;
			}
			cout << endl << endl;
			cout << "────────────────────────────────────────────" << endl;
			cout << endl;
			cout << "아무키나 입력하면 메인화면으로 이동합니다.";
			getch();
		}
	}
}
