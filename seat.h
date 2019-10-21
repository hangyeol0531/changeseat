#include <iostream>
#include <stdlib.h>
#include<string>
#include <fstream>
#include <time.h>
#include<windows.h>
#include <mmsystem.h>
#include <vector>
#include <iomanip>
#include <conio.h>
using namespace std;

class seat {
	string stna[50]; // 학생들이름
	int stgn[50]; //학생들 성별
	string inputstring;

public:
	seat();
	static int num;
	static int numbern;// 학생수z
	static int zonumber;
	static int studentline;
	static int genderline;
	int reserved[10] = { 0, }; // 바꾸는 사람 번호
	int zizungflag = 0;
	int ren[10] = { 0, }; // 좌석 번호
	int recount = 0; //지정 횟수
	int jijung;
	int jicount = 0;
	int studentnum = 0; // 성별설정 사람수
	void inputinformation(void);
	void mainchang(void);
	void setseat(void);	
	void zolottery(void);
	void danglottery(void);
	void checkrecord(void);
	void setmember(void);
	void waitingchang(void);
	void setseatmain(void);
	void reservedseat(void);
	void Shuffle_Data(int *student_array, int routine_time=20);
};
