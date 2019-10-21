#include "seat.h"
void seat::danglottery() {
	string inputString;
	string stuString;

	system("cls");
	int Dinput = 1; // 총 당번 수
	int i; //for문 돌릴 변수
	int boy = 1, girl = 1; // 뽑을 남, 녀 각각 인원 수
	int input; // 사용자의 번호 선택
	int r = 0;//랜덤 값 저장
	int cnt = 0;
	int bFound;
	int c = 1;
	vector<int> boyArr; //남자가 속해있는 줄 수가 저장되어있는 배열 기반 컨테이너
	vector<int> girlArr;
	vector<int>over(studentline, 0);

	//  /*여자와 남자가 속해있는 줄 수 저장
	ifstream gd("gender.txt");
	while (!gd.eof()) {
		for (i = 0; i < genderline; i++) {
			getline(gd, inputString);
			if (inputString.compare(0, 1, "0") == 0) {
				boyArr.push_back(i + 1);
			}
			else if (inputString.compare(0, 1, "1") == 0) {
				girlArr.push_back(i + 1);
			}
			else
				break;
		}
	}

	ifstream student("student.txt");
	ifstream gender("gender.txt");

	int *student_array = new int[studentline];
	for (i = 0; i < studentline; i++)
		student_array[i] = i + 1;
	Shuffle_Data(student_array);

	vector <string> stu;
	vector <string> gen;

	while (!student.eof()) {
		getline(student, stuString);
		stu.push_back(stuString);
		getline(gender, inputString);
		gen.push_back(inputString);
	}

	while (true) {
		cout << "┌────────────────────── 당번 뽑기 화면 ────────────────────────┐" << endl;
		cout << "│                                                              │" << endl;
		cout << "│                                                              │" << endl;
		cout << "│                        1.전체에서 뽑기                       │" << endl;
		cout << "│                                                              │" << endl;
		cout << "│                        2.남,녀 구분 뽑기                     │" << endl;
		cout << "│                                                              │" << endl;
		cout << "│                        3.메인 홈                             │" << endl;
		cout << "│                                                              │" << endl;
		cout << "└──────────────────────────────────────────────────────────────┘" << endl;
		cin >> input;

		//      /*추첨할 당번 인원 수 및 성별 설정
		if (input == 1) {
			againdang1:
			//인원  수 설정
			while (true) {
				cout << "뽑을 인원 수를 설정해주세요 : ";
				cin >> Dinput;
				if (Dinput > studentline) {
					MessageBoxA(NULL, "뽑을 인원 수가 많습니다", "Error", MB_ICONWARNING);
					_getch();
					continue;
				}
				break;
			}

			//출력
			seat::waitingchang();

			/*기록 값 넣기*/
			ofstream i1File("dangrecord.txt");

			int n = 0;
			//학생, 성별 이름넣기
			for (int i = 0; i < numbern; i++) {
				if (i == 0) {
					i1File << numbern << endl;
					i1File << Dinput << endl;
				}
				system("cls");
			}
			////////////////////////////
			cout << "───────────────당번 추첨 결과───────────────" << endl;
			c = 1;
			Shuffle_Data(student_array);
			for (int i = 0; i < Dinput; i++) {
				cout << c << ". " << stu[student_array[i]] << endl;
				c++;
				i1File << student_array[i] << endl; // 기록
			}
			i1File.close();
			cout << "────────────────────────────────────────────" << endl;
			Sleep(3000);
			if (MessageBox(NULL, "재추첨 하시겠습니까?", "질문", MB_YESNO) == IDYES) {
				system("cls");
				goto againdang1;
			}
			else goto EXIT;
			system("cls");
		}
		else if (input == 2) {
			//뽑을 인원 수 설정
			while (true) {
			againdang2:
				cout << "뽑을 인원 수를 설정해주세요 : ";
				cin >> Dinput;
				if (Dinput > studentline) {
					MessageBoxA(NULL, "뽑을 인원 수가 많습니다", "Error", MB_ICONWARNING);
					_getch();
					continue;
				}
				system("cls");
				cout << "뽑을 (남), (녀) 인원수를 설정해주세요 (총 당번 수 :" << Dinput << ") " << endl;
				cout << "남 : ";
				cin >> boy;
				cout << "여 : ";
				cin >> girl;

				if (boy + girl != Dinput) {
					MessageBoxA(NULL, "남,녀 수를 잘못지정하였습니다.", "ERROR", MB_ICONWARNING);
					_getch();
					continue;
				}

				if (girl > girlArr.size() || boy > boyArr.size()) {
					MessageBoxA(NULL, "남자 또는 여자의 수가 지나치게 많습니다.", "ERROR", MB_ICONWARNING);
					_getch();
					continue;
				}
				break;
			}
			seat::waitingchang();
			/*기록 값 넣기*/
			ofstream i1File("dangrecord.txt");

			int n = 0;
			//학생, 성별 이름넣기
			for (int i = 0; i < numbern; i++) {
				if (i == 0) {
					i1File << numbern << endl;
					i1File << Dinput << endl;
				}
				system("cls");
			}
			////////////////////////////
			c = 1; // 출력 번호 
			//남자 출력
			cout << "───────────────당번 추첨 결과───────────────" << endl;
			int draw_amount = 0;
			for (int i = 0; i < studentline; i++) {
				if (draw_amount == boy) {
					break;
				}
				if (gen[student_array[i]] == "0") {
					cout << c << ". "<< stu[student_array[i]] << endl;
					c++;
					i1File << student_array[i] << endl;
					draw_amount++;
				}
			}
			//여자 출력
			draw_amount = 0;
			for (int i = 0; i < studentline; i++) {
				if (draw_amount == girl) {
					break;
				}
				if (gen[student_array[i]] == "1") {
					cout << c << ". " << stu[student_array[i]] << endl;
					c++;
					i1File << student_array[i] << endl;
					draw_amount++;
				}
			}
			cout << "────────────────────────────────────────────" << endl;
			i1File.close();
			Sleep(3000);
			if (MessageBox(NULL, "재추첨 하시겠습니까?", "질문", MB_YESNO) == IDYES) {
				system("cls");
				goto againdang2;
			}
			break;
		}
		else if (input == 3) {
			EXIT:
			seat::mainchang();
			break;
		}

		else {
			MessageBoxA(NULL, "선택지를 잘 못 선택하셨습니다.", "Error", MB_ICONWARNING);
		}
	}
	student.close();
	gender.close();
};

void seat::Shuffle_Data(int *student_array, int routine_time) {
	for (int i = 0; i < routine_time; i++) {
		int data1_dir = rand() % studentline;
		int data2_dir = rand() % studentline;
		int temp = student_array[data2_dir];
		student_array[data2_dir] = student_array[data1_dir];
		student_array[data1_dir] = temp;
	}
};
