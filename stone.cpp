#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool stone35[100];
bool stone45[100];
bool stone55[100];
bool stone65[100];
bool stone75[100];
ll result[30];
int cnt;
int size;

void swap(bool &a, bool &b) { 
	bool tmp = a;
	a = b;
	b = tmp;
}

void initArr(int n, bool arr){
	for(int i=0;i<n;i++){
		arr[i] = 1;
	}
}

void beforeSuffle(){
	
	memset(stone35,0,size);
	memset(stone45,0,size);
	memset(stone55,0,size);
	memset(stone65,0,size);
	memset(stone75,0,size);
	
	initArr(35, stone35);
	initArr(45, stone45);
	initArr(55, stone55);
	initArr(65, stone65);
	initArr(75, stone75);
	
}

void stonesSuffle(bool arr){
	for(int i=0;i<1000;i++){
		for(int j=0;j<100;j++){
			int r = rand()%(100-j)+j;
			swap(arr[j], arr[r]);
		}
	}
}

void startSuffle(){함 
	// stonesSuffle(stone35)
	// 배열을 전역변수로 선언해서 사용하기가 어려움...
	// 추가적인 아이디어가 필요 
}

void suffle(){
	beforeSuffle();
	startSuffle();
}

void init(){
	size = sizeof(stone35);
	cin >> cnt;
}

void startSimulation(){
	for(int i=0;i<cnt;i++){
		suffle();
	}
}

void simulation(){
	init();
	
	startSimulation();
}

int main(){
	simulation();
}
