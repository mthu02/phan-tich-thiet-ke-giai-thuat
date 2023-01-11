#include<bits/stdc++.h>
#define Max 100
using namespace std;
int n, a[Max][Max], daxet[Max], truoc[Max], t, s;
void Input() {

	ifstream infile;
	infile.open("input1.txt");
	infile >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
		{
			infile >> a[i][j];
		}
	}
}
void xuat(){
	cout << t <<" <--";
	int j = t;
	while (truoc[j] != s){
		cout << truoc[j] << " <--";
		j = truoc[j];
	}
	cout << s << endl;
}
void DFS(int s){
	int u;
	daxet[s] = 1;
	for(u = 1; u <= n; u++){
		if(a[s][u] && !daxet[u]){
			truoc[u] = s;
			if(u == t) xuat();
			else DFS(u);
			daxet[u] = 0;
		}
	}
}
int main(){
	cout << "Nhap vao dinh bat dau: ";
	cin >> s;
	cout << "Nhap vao dinh ket thuc: ";
	cin >> t;
	Input();
	DFS(s);
	return 0;
}
/*
0 0 0 1 0 1 1
0 0 1 1 0 0 0
0 1 0 1 0 1 0
1 0 1 0 0 0 0
0 0 0 0 0 1 0
1 0 0 0 1 0 0
1 0 0 1 0 0 0
*/
