#include <bits/stdc++.h>
#include "init.h"
#define ll long long
using namespace std;

ll arr[31];	// �� �ܰ躰 ��������  
int cnt; 	// �ùķ��̼� Ƚ��

void calculation(){
	// state�� Ȯ�� ���·�
	// 75% = A
	// 65% = B
	// 55% = C 
	// 45% = D
	// 35% = E
	// 35% = F
	
	char state = 'A'; // �ʱ� Ȯ�� ���� 
	
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
		
		if(result) {
			//�����ϸ� Ȯ�� ��� �϶� 
			arr[i]++; // ������ Ŭ�� �迭�� i���� �´� ���� 1 ����
			// ���⿡ ���� �м� �����͸� �߰� �� �� �ֵ��� ��.
			if(state != 'F') state++;
		}
		else{
			//�����ϸ� Ȯ�� ��� ��� 
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
	cout << "������ Ŭ�� ���" << endl;
	
	for(int i=1;i<31;i++){
		cout << i<< "��° ����Ȯ�� : " << ((float)arr[i]/(float)cnt) * 100.0 << "%\n";
	}
	
	cout << "��!\n";
}

void noname(){
	// �� ���� 75�� ��		��� 1
	// �̹��� ����, ���� 	��� 2 
	
	// �� ���� 65�� ��		��� 3 
	// �̹��� ����, ����	��� 4 
	
	// �� ���� 55�� ��		��� 5 
	// �̹��� ����, ����	��� 6 
	
	// �� ���� 45�� ��		��� 7 
	// �̹��� ����, ����	��� 8 
	
	// �� ���� 35�� ��		��� 9 
	// �̹��� ����, ����	��� 10 
	
	// �� ���� 25�� ��		��� 11
	// �̹��� ����, ����	��� 12
	
	//�迭�� 12*31 ��ù��° Ŭ���� 1�� ���� 
	//Ȧ���� ����, ¦���� ������ ��� ī���� 
}
 
int main(){
	
	cout << "����Ƚ�� �Է��ϼ� : ";
	cin >> cnt;
	
	simulation();
	
	printing();
	
}
