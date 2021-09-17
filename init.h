const int Max = 10000;
bool stone25[Max];
bool stone35[Max];
bool stone45[Max];
bool stone55[Max];
bool stone65[Max];
bool stone75[Max];

void init(){
	memset(stone25, 0, sizeof(stone25));
	memset(stone35, 0, sizeof(stone25));
	memset(stone45, 0, sizeof(stone25));
	memset(stone55, 0, sizeof(stone25));
	memset(stone65, 0, sizeof(stone25));
	memset(stone75, 0, sizeof(stone25));
	
	for(int i=0;i<2500;i++) stone25[i] = 1;
	for(int i=0;i<3500;i++) stone35[i] = 1;
	for(int i=0;i<4500;i++) stone45[i] = 1;
	for(int i=0;i<5500;i++) stone55[i] = 1;
	for(int i=0;i<6500;i++) stone65[i] = 1;
	for(int i=0;i<7500;i++) stone75[i] = 1;
}

void swap(bool &a, bool &b){
	bool tmp = a;
	a = b;
	b = tmp;
}

void suffle(){
	for(int T=0;T<1000;T++){
		for(int i=0;i<Max;i++){
			int r = rand()%(Max-i)+i;
			swap(stone25[i], stone25[r]);
		}
		
		for(int i=0;i<Max;i++){
			int r = rand()%(Max-i)+i;
			swap(stone35[i], stone35[r]);
		}
		
		for(int i=0;i<Max;i++){
			int r = rand()%(Max-i)+i;
			swap(stone45[i], stone45[r]);
		}
		
		for(int i=0;i<Max;i++){
			int r = rand()%(Max-i)+i;
			swap(stone55[i], stone55[r]);
		}
		
		for(int i=0;i<Max;i++){
			int r = rand()%(Max-i)+i;
			swap(stone65[i], stone65[r]);
		}
		
		for(int i=0;i<Max;i++){
			int r = rand()%(Max-i)+i;
			swap(stone75[i], stone75[r]);
		}
	}
}

bool getResultA(int n){
	return stone75[n];
}

bool getResultB(int n){
	return stone65[n];
}

bool getResultC(int n){
	return stone55[n];
}

bool getResultD(int n){
	return stone45[n];
}

bool getResultE(int n){
	return stone35[n];
}

bool getResultF(int n){
	return stone25[n];
}
