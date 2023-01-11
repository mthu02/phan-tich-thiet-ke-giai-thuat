#include<bits/stdc++.h>
#define Max 1000
using namespace std;

int a[Max][Max];
int d[Max][Max];
int p[Max][Max];
int n;
int s[Max];
void Input() {

	ifstream infile;
	infile.open("input1.txt");
	infile >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
		{
			infile >> a[i][j];
			if (i != j && a[i][j] == 0)a[i][j] = Max;
		}
	}
}
void floyd(){
	int i, j, k;
	for(int i = 1; i<= n; i++){
		for(int j = 1; j <=n ; j++){
			d[i][j] = a[i][j];
			p[i][j] = 0;
		}
	}
	for(k = 1; k <= n; k++){ //Cac buoc lap k
		for(i = 1; i<= n; i++){ //Hang
			if (d[i][k] > 0 && d[i][k] < Max){
				for(j = 1; j <= n; j++){ //Cot
					if(d[k][j] > 0 && d[k][j] < Max){
						if(d[i][k] + d[k][j] < d[i][j]){
							d[i][j] = d[i][k] + d[k][j];
							p[i][j] = k;
						}
					}
				}
			}
		}
	}
}
void Print(int u, int v){
	//Truy vet
	if (d[u][v] >= Max) {
	  		cout<<"\nKhong co duong di"<<endl;
	}
	else {
		cout<<"\nDuong di ngan nhat tu "<<u<<" den "<<v<< " co do dai quang duong la: "<<d[u][v]<<endl;
		int t = 1; int i=u; int j=v; int k;
		s[t]=v;
		while (p[i][j]!=0) {
			k = p[i][j];
			t++;
			s[t] = k; 
			j = k;
		}
		cout<<"\nDuong di: "<<u;
		int count = t;
		while(count>0) {
			cout<<" -> "<<s[count];
			count--;
		}
	}
}
int main(){
	int u, v;
	cout << "Dinh bat dau: ";
	cin >> u;
	cout << "Dinh ket thuc: ";
	cin >> v;
	Input();
	floyd();
	Print(u, v);
	return 0;			
}
