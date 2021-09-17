#include <bits/stdc++.h>
#include "init.h"
#define ll long long
using namespace std;

ll arr[31];	// 각 단계별 성공누적  
int cnt; 	// 시뮬레이션 횟수

void calculation(){
	// state는 확률 상태로
	// 75% = A
	// 65% = B
	// 55% = C 
	// 45% = D
	// 35% = E
	// 35% = F
	
	char state = 'A'; // 초기 확률 상태 
	
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
		
		if(result) {
			//성공하면 확률 등급 하락 
			arr[i]++; // 무지성 클릭 배열에 i값에 맞는 값을 1 증가
			// 여기에 나름 분석 데이터를 추가 할 수 있도록 함.
			if(state != 'F') state++;
		}
		else{
			//실패하면 확률 등급 상승 
			if(state != 'A') state--;
		}
		
		
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
	
	cout << "끝!\n";
}

void noname(){
	// 앞 돌이 75일 때		경우 1
	// 이번이 성공, 실패 	경우 2 
	
	// 앞 돌이 65일 때		경우 3 
	// 이번이 성공, 실패	경우 4 
	
	// 앞 돌이 55일 때		경우 5 
	// 이번이 성공, 실패	경우 6 
	
	// 앞 돌이 45일 때		경우 7 
	// 이번이 성공, 실패	경우 8 
	
	// 앞 돌이 35일 때		경우 9 
	// 이번이 성공, 실패	경우 10 
	
	// 앞 돌이 25일 때		경우 11
	// 이번이 성공, 실패	경우 12
	
	//배열을 12*31 →첫번째 클릭에 1을 저장 
	//홀수는 성공, 짝수는 실패의 경우 카운팅 
}
 
int main(){
	
	cout << "시행횟수 입력하셈 : ";
	cin >> cnt;
	
	simulation();
	
	printing();
	
}
