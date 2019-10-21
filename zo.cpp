#include "seat.h"

void seat::zolottery() {
againzolottery:
	system("cls");
	cout << "각 조 인원은 몇명입니까?" << endl;
	cin >> zonumber;
	seat seat;
	int i, j, bFound;
	vector<int> zonum(numbern);
	srand(time(0));
	for (i = 0; i < numbern; ++i)
	{
		while (1)
		{
			// 난수를하나생성
			zonum[i] = rand() % numbern + 1;
			// 이미있는값인지확인하기위해플래그설정
			bFound = 0;
			// 같은값이있는지확인한다
			for (j = 0; j < i; ++j)
			{
				// 같은값이있으면
				if (zonum[j] == zonum[i])
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
	ofstream i1File("zorecord.txt");

	int n = 0;
	//학생, 성별 이름넣기
	for (int i = 0; i < numbern; i++) {
		if (i == 0) {
			i1File << zonumber << endl;
			i1File << numbern << endl;
		}
		i1File << zonum[i] << endl;
		system("cls");
	}
	i1File.close();
	////////////////////////////

	system("cls");
	seat::waitingchang();
	int a = 0;
	int zocount = 0;
	cout.fill('0');
	PlaySound("개.wav", NULL, SND_ASYNC | SND_LOOP);
	cout << "────────────────────────────────── 추첨 결과 ─────────────────────────────────" << endl;
	for (i = 0; i < numbern; ++i) {

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
	cout <<  endl << endl << "──────────────────────────────────────────────────────────────────────────────" << endl;
	Sleep(2000);
	PlaySound(0, 0, 0);
	Sleep(3000);
	if (MessageBox(NULL, "재추첨 하시겠습니까?", "질문", MB_YESNO) == IDYES) {
		system("cls");
		goto againzolottery;
	}
	else {
		seat.mainchang();
	}
	cout << endl;
};
