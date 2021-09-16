const int Max = 100;
bool stone25[Max];
bool stone35[Max];
bool stone45[Max];
bool stone55[Max];
bool stone65[Max];
bool stone75[Max];

void init(){
	for(int i=0;i<25;i++) stone25[i] = 1;
	for(int i=25;i<Max;i++) stone25[i] = 0;
	
	for(int i=0;i<35;i++) stone35[i] = 1;
	for(int i=35;i<Max;i++) stone35[i] = 0;
	
	for(int i=0;i<45;i++) stone45[i] = 1;
	for(int i=45;i<Max;i++) stone45[i] = 0;
	
	for(int i=0;i<55;i++) stone55[i] = 1;
	for(int i=55;i<Max;i++) stone55[i] = 0;
	
	for(int i=0;i<65;i++) stone65[i] = 1;
	for(int i=65;i<Max;i++) stone65[i] = 0;
	
	for(int i=0;i<75;i++) stone75[i] = 1;
	for(int i=75;i<Max;i++) stone75[i] = 0;
}

void swap(bool &a, bool &b){
	bool tmp = a;
	a = b;
	b = tmp;
}

void suffle(){
	for(int T=0;T<10000;T++){
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
