#include<bits/stdc++.h>
#define Maxint 10001
using namespace std;
int c[Maxint][Maxint];
char r[Maxint];
int s = 0;
void LCS(char x[], char y[], int n, int m){
	for(int i = 1; i <= m; i++){
		c[i][0] = 0;
	}
	for(int i = 1; i <= n; i++){
		c[0][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(x[i] == y[j]) c[i][j] = c[i-1][j-1] + 1;
			else{
				if (c[i-1][j] >= c[i][j-1]) c[i][j] = c[i-1][j];
				else c[i][j] = c[i][j-1];
			}
		}
	}
}
void TruyVet(int m, int n, char x[]){
	while(c[m][n] == c[m-1][n]) m--;
	while(c[m][n] == c[m][n-1]) n--;
	if(c[m][n] != 0){
		r[s] = x[m];
		s++;
	}
	if(m >= 1 && n >= 1) TruyVet(m-1, n-1, x);
	
}
int main(){
	int m, n;
	string st1, st2;
	ifstream nameFileout;

	nameFileout.open("name2.txt");
	getline(nameFileout, st1);
	getline(nameFileout, st2);
	
	n = st1.length();
	char x[n+2];
	char xx[n + 1];
	strcpy(xx, st1.c_str());
	for(int i = 0; i < n; i++){
		x[i+1] = xx[i];
	}
	
	m = st2.length();
	char y[m+2];
	char yy[m + 1];
	strcpy(yy, st2.c_str());
	for(int i = 0; i < n; i++){
		y[i+1] = yy[i];
	}
	LCS(x, y,n,m);
	cout << c[m][n] << "\n";
	TruyVet(m,n,x);
	for(int i = s-1; i >= 0; i--){
		cout << r[i] << " ";
	}
	return 0;
}


