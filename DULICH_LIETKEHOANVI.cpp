#include<bits/stdc++.h>
#define Max 100
using namespace std;
int n, a[Max], b[Max], c[Max][Max], r[Max], smin = Max, s;
void Input() {

	ifstream infile;
	infile.open("input1.txt");
	infile >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
		{
			infile >> c[i][j];
			if (i != j && c[i][j] == 0)c[i][j] = Max;
		}
	}
}
void xuat(){
	s=c[1][a[1]];
	for(int i = 1; i < n; i++){
		s += c[a[i]][a[i+1]];
	}
	s+=c[a[n]][1];
	
	if(s<smin){
		smin = s;
		for(int i = 1; i <= n; i++){
			r[i] = a[i];
		}
	}
}
void thu(int i){
	for(int j = 1; j <= n; j++){
		if(b[j]){
			a[i] = j;
			b[j] = 0;
			if(i < n) thu(i+1);
			else xuat();
			b[j] = 1;
		}
	}
}
int main(){
	Input();
	for(int i = 1; i <= n; i++){
		b[i] = 1;
	}
	thu(1);
	
	cout << "Duong di ngan nhat: " << smin << "\n";
	for(int i = 1; i <= n; i++){
		cout << r[i] << " ";
	}
	return 0;
}

