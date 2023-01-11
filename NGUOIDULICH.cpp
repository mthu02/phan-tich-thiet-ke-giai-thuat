#include<bits/stdc++.h>
#define Max 100
using namespace std;
int daxet[Max], Cmin, c[Max][Max], gttu, s, x[Max], lttu[Max], n;
void Input(){
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
void init(){
	int i, j;
	Cmin = Max;
	for(i=1; i<=n; i++){
		daxet[i]=0;
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(Cmin > c[i][j]) Cmin = c[i][j];
		}
	}
	gttu = Max; 
	s = 0;
	x[1] = 1;
}
void xuat(){
	for(int m = 1; m<n ; m++){
		cout << x[m] << "-->";
	}
	cout << x[n] << "\n";
}
void Try(int i){
	int j, Tong, g;
	for(j=2; j<=n; j++){
		if(!daxet[j]){ //Chap nhan duoc
			x[i] = j; //Xac dinh xi theo j
			daxet[j] = 1; //Ghi nhan trang thai moi
			s = s + c[x[i-1]][x[i]]; 

			if(i==n){
				// Cap nhat loi giai toi uu
				Tong = s + c[x[n]][x[1]];
				
				if(Tong < gttu){
					xuat();
					gttu = Tong;
					cout << "Gia tri toi uu: " << gttu << "\n";
				}
			}else{
				g = s + (n-i+1)*Cmin; //Xac dinh can tren g
				if(g < gttu){
					Try(i+1);
				}
			}
			//Tra lai trang thai cu cho bai toan
			s = s - c[x[i-1]][x[i]]; //Tra lai chi phi
			daxet[j] = 0;
		}
	}
}
int main(){
	Input();
	init();
	Try(2);
	return 0;
}
