#include <bits/stdc++.h>
#include "init.h"
#define ll long long
using namespace std;

ll arr[30];
int cnt; // 시뮬레이션 횟수

void calculation(){
	// state는 확률 상태로
	// 75% = A
	// 65% = B
	// 55% = C 
	// 45% = D
	// 35% = E
	// 35% = F
	
	char state = 'A'; // 초기 확률 상태 
	for(int i=0;i<30;i++){
		int R = rand()%100;
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
			arr[i]++;
			if(state != 'F') state++;
		}
		else{
			if(state != 'A') state--;
		}
		
		
	}
}

void simulation(){
	srand((unsigned int)time(NULL));
	memset(arr,0,sizeof(arr));
	
	while(cnt--){
		init();
		suffle();
		calculation();
	}
}

void printing(){
	cout << "결과 : " << endl;
	
	for(int i=0;i<30;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
 
int main(){
	

	cin >> cnt;
	
	simulation();
	
	printing();
}
