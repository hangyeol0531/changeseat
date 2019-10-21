#include "seat.h"

void seat::setmember(void) {
	system("cls");
	int input;
	cout << "┌─────────────────────── 체 설정 화면 ────────────────────────┐" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                        1.이름 설정                          │" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                        2.성별 설정                          │" << endl;
	cout << "│                                                             │" << endl;
	cout << "│                                                             │" << endl;
	cout << "└─────────────────────────────────────────────────────────────┘" << endl;
	cout << "원하시는 선택지를 선택해주세요. ";
	cin >> input;
	system("cls");
	if (input == 1) {
		string name;
		system("cls");
		cout << "학생수를 입력해주세요.";
		cin >> numbern;
		ofstream outFile("student.txt");
		system("cls");
		for (int i = 0; i < numbern; i++) {
			cout << i + 1 << "번째 사람의 성함을 입력해주세요" << endl;
			cout << "이름: ";
			cin >> name;
			outFile << name << endl;
			system("cls");
		}
		outFile.close();
	}
	else if (input == 2) {
		int gender;
		system("cls");
		ofstream outFile("gender.txt");
		ifstream inFile("student.txt");
		system("cls");

		string a[30];
		for (int i = 0; i < numbern; i++) {
			//inFile.getline(inputString, 100);
			inFile >> a[i];

			cout << a[i] << "님의 성별을 입력해주세요.(남자 = 0 여자 = 1)" << endl;
			cout << "성별: ";
			cin >> gender;
			outFile << gender << endl;
			system("cls");
		}
		inFile.close();
		outFile.close();
		inputinformation();
	}
}

void seat::inputinformation(void) {
	ifstream i1File("student.txt");
	ifstream i2File("gender.txt");

	int n = 0;
	//학생, 성별 이름넣기
	while (!i1File.eof() && !i2File.eof()) {
		getline(i1File, inputstring);
		stna[n] = inputstring;
		i2File >> stgn[n];
		n++;
	}
	
	i1File.close();
	i2File.close();

	genderline = n - 1;
	studentline = n - 1;
	system("cls");

	//stna[100][100]; // 학생들이름
	//stgn[100][1]; //학생들 성별
}
