#include "seat.h"

using namespace std; 


void seat::reservedseat() {
reservedseatagain:
	system("cls");
	ifstream i1File("student.txt");
	while (1) {
		zizungflag = 1;
		int n = 1;
		int input = 1;

		while (!i1File.eof()) {
			i1File >> stna[n] ;
			cout << n << ". " << stna[n] << endl;
			n++;
		}

		cout << "몇번째 사람을 지정하시겠습니까?: ";
		cin >> reserved[recount];
		cout << "몇번째 좌석으로 지정하시겠습니까?: ";
		cin >> ren[recount];
		cout << "계속 하시려면 아무키를 입력해주세요(메인 화면 -1) : ";
		cin >> input;
		++recount;
		if (input == -1) break;
		else goto reservedseatagain;
	}
}

void seat::setseat() {
setseatagain:
	vector<int> over(numbern, 0);
	int fgfg = 0;
	jicount = 0;
	system("cls");
	seat seat;
	cout << "한 줄당 앉을 학생 수를 입력해주세요 : ";
	cin >> num;
	int i, j, bFound, exit_flag = 0;
	int exit_flag1 = 0;
	srand(time(NULL));
	for (i = 0; i < numbern; ++i)
	{
		//지정석~~~~~~~~~~~~~~~~~~~~~~~~~~

		//지정 횟수 구하기 
		if (i == 0 && zizungflag == 1) {
			jijung = 0;
			for (int k = 0; k < numbern; k++) {
				jijung++;
				if (reserved[k] == 0) {
					jijung -= 1;
					break;
				}
			}
		}
		//지정석~~~~~~~~~~~~~~~~~~~~~~~~~~
		while (1)
		{	
			//지정석~~~~~~~~~~~~~~~~~~~~~~~~~~
			if (i == 0 && zizungflag == 1) {
				for (int q = 0; q < jijung; q++) {
					//over[reserved[q]] = ren[q];
					over[ren[q] - 1] = reserved[q];//over[좌석 번호] = 사람번호
				}
			}

			fgfg = 0;

			if (jicount < jijung) {
				if (reserved[jicount] == over[i]) {
					jicount++;
					fgfg = 1;
				}
			}
			if (fgfg) break;
			//지정석~~~~~~~~~~~~~~~~~~~~~~~~~~

			over[i] = rand() % numbern + 1; // 난수를하나생성
			// 이미있는값인지확인하기위해플래그설정
			bFound = 0;
			// 같은값이있는지확인한다
			for (j = 0; j < i; ++j)
			{
				// 같은값이있으면
				if (over[j] == over[i])
				{
					// 같은값이이미있음
					bFound = 1;
					break;
				}
			}
			// 같은값이없으면while문탈출
			if (!bFound)
				break;
		}
	}
	/*기록 값 넣기*/
	ofstream i1File("setrecord.txt");

	int n = 0;
	//학생, 성별 이름넣기
	for (int i = 0; i < numbern; i++) {
		if (i == 0) {
			i1File << num << endl;
			i1File << numbern << endl;
		}
		i1File << over[i] << endl;
		system("cls");
	}
	i1File.close();
	////////////////////////////z
	system("cls");

	seat::waitingchang();
	int a = 0;
	cout.fill('0');
	system("cls");
	PlaySound("닭.wav", NULL, SND_ASYNC | SND_LOOP);
	cout << "┌────────────────────────────────── 추첨 결과 ─────────────────────────────────┐" << endl;
	for (int q = 0; q < numbern; ++q) {
		if (a % num == 0)
		{
			cout << endl << "│            ";
		}
		cout.width(2);
		cout << stna[over[q] - 1] << "   ";
		if (a != a / num && a % num == 5)
		{
			cout << "            │" << endl;
		}
		a++;
	}
	cout << endl;
	cout << "└──────────────────────────────────────────────────────────────────────────────┘" << endl;
	Sleep(2000);
	PlaySound(0, 0, 0);
	Sleep(3000);
	if (MessageBox(NULL, "재추첨 하시겠습니까?", "질문", MB_YESNO) == IDYES) {
		system("cls");
		goto setseatagain;
	}
	else {
		seat.mainchang();
	}
	cout << endl;
};


class student {
public:

	int gender; // 0남자 1여자

	int seatnumber; //고정 번호 // 없으면 0
};
