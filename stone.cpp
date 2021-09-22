#include <bits/stdc++.h>
#include <conio.h>
#include "init.h"
#define ll long long
using namespace std;

ll arr[31];		// 무지성 배열 
ll brr[13][31];	// 나름 분석 배열 
int cnt;		// 시뮬레이션 횟수

void calculation2(bool result, int idx, char preState){
	switch(preState){
		case 'A':
			if(result) 	brr[1][idx]++;
			else 		brr[2][idx]++;	
			break;
		case 'B':
			if(result) 	brr[3][idx]++;
			else 		brr[4][idx]++;	
			break;
		case 'C':
			if(result) 	brr[5][idx]++;
			else 		brr[6][idx]++;	
			break;
		case 'D':
			if(result) 	brr[7][idx]++;
			else 		brr[8][idx]++;	
			break;
		case 'E':
			if(result) 	brr[9][idx]++;
			else 		brr[10][idx]++;	
			break;
		case 'F':
			if(result) 	brr[11][idx]++;
			else 		brr[12][idx]++;	
			break;
	}
}

void calculation(){
	char state = 'A'; // 초기 확률 상태 
	char preState = 'A';
	// 하나의 돌당 30번의 클릭을 해야 함 
	for(int i=1;i<31;i++){
		int R = rand() % Max;
		bool result;
		
		switch(state){
			case 'A': result = getResultA(R); break;
			case 'B': result = getResultB(R); break;
			case 'C': result = getResultC(R); break;
			case 'D': result = getResultD(R); break;
			case 'E': result = getResultE(R); break;
			case 'F': result = getResultF(R); break;
		}
		
		calculation2(result, i, preState);
		
		if(result) {
			//성공하면 확률 등급 하락 
			arr[i]++; // 무지성 클릭 배열에 i값에 맞는 값을 1 증가	
			if(state != 'F') state++;
		}
		else{
			//실패하면 확률 등급 상승 
			if(state != 'A') state--;
		}
		
		preState = state;
	}
}

void simulation(){
	srand((unsigned int)time(NULL));
	memset(arr,0,sizeof(arr));
	
	init();
	suffle();
	
	for(int i=0;i<cnt;i++) {
		calculation();
	}
}

void printing(){
	cout << "무지성 클릭 결과" << endl;
	
	for(int i=1;i<31;i++){
		cout << i<< "번째 성공확률 : " << ((float)arr[i]/(float)cnt) * 100.0 << "%\n";
	}
	
	cout << endl;
	cout << "나름 분석 배열 결과" << endl;
	
	for(int i=1;i<13;i++) {
		for(int j=1;j<31;j++){
			cout << brr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void endSimulator(){
	getch();
}
 
int main(){
	cout << "시행횟수 입력하셈 : ";
	cin >> cnt;
	
	simulation();
	
	printing();
	
	endSimulator();
}
