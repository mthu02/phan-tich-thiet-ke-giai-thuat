#include<bits/stdc++.h>
using namespace std;
set<int> dauDB {44, 46};
void *Xoa_dau(char s[]){
	while(s[0] == 32){
		strcpy(&s[0], &s[1]);
	}
}
void *Xoa_cuoi(char s[]){
	int i = sizeof(s)-1;
	while(s[i] == 32){
		s[i] = 0;
		i--;
	}
}
void *Xoa_trong(char s[]){
	int i = 0;
	while(i < sizeof(s)){
		while(s[i] == 32 && s[i+1] == 32){
			strcpy(&s[i],&s[i+1]);
		}
		i++;
	}
}
void *Xoa_truocdauDB(char s[]){
	int i;
	for (i = 0; i < sizeof(s); i++){
		if (dauDB.find(s[i]) != dauDB.end() && s[i-1] == 32){
			strcpy(&s[i-1], &s[i]);
		}
	}
}
void *Them_sauDB(char s[]){
	int i;
	for (i = 0; i < sizeof(s); i++){
		if (dauDB.find(s[i]) != dauDB.end() && s[i+1] != 32){
			strcpy(&s[i+2], &s[i+1]);
			s[i+1] = 32;
		}
	}
}
void *VietHoaDauCau(char s[]){
	int i;
	for (i = 0; i < sizeof(s); i++){
		if (s[i] == 46 && (s[i+2] < 65 || s[i+2] > 90)){
			s[i+2] = s[i+2] - 97 + 65;
		}
	}
}
int main(){
	char s[] = "  ab c .d  ";
	Xoa_dau(s);
	Xoa_cuoi(s);
	Xoa_trong(s);
	Xoa_truocdauDB(s);
	Them_sauDB(s);
	VietHoaDauCau(s);
	for (int i = 0; i < sizeof(s); i++){
		cout << s[i];
	}
	return 0;
}
