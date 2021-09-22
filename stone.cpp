#include <bits/stdc++.h>
#include <conio.h>
#include "init.h"
#define ll long long
using namespace std;

ll arr[31];		// ������ �迭 
ll brr[13][31];	// ���� �м� �迭 
int cnt;		// �ùķ��̼� Ƚ��

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
	char state = 'A'; // �ʱ� Ȯ�� ���� 
	char preState = 'A';
	// �ϳ��� ���� 30���� Ŭ���� �ؾ� �� 
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
			//�����ϸ� Ȯ�� ��� �϶� 
			arr[i]++; // ������ Ŭ�� �迭�� i���� �´� ���� 1 ����	
			if(state != 'F') state++;
		}
		else{
			//�����ϸ� Ȯ�� ��� ��� 
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
	cout << "������ Ŭ�� ���" << endl;
	
	for(int i=1;i<31;i++){
		cout << i<< "��° ����Ȯ�� : " << ((float)arr[i]/(float)cnt) * 100.0 << "%\n";
	}
	
	cout << endl;
	cout << "���� �м� �迭 ���" << endl;
	
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
	cout << "����Ƚ�� �Է��ϼ� : ";
	cin >> cnt;
	
	simulation();
	
	printing();
	
	endSimulator();
}
