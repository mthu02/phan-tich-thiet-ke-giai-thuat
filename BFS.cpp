#include<bits/stdc++.h>
#define Max 100
using namespace std;
int a[Max][Max], q[Max], daxet[Max], truoc[Max], s, t, n;
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
void BFS(int s){
	int u, j, dauQ = 1, cuoiQ = 1;
	q[cuoiQ] = s;
	daxet[s] = 1;
	while(dauQ <= cuoiQ){
		u = q[dauQ];
		dauQ++;
		for(j = 1; j <=n ; j++){
			if(a[u][j]==1 && !daxet[j]){
				cuoiQ++;
				q[cuoiQ] = j;
				daxet[j] = 1;
				truoc[j] = u;
			}
		}
		
	}xuat();
}
int main(){
	cout << "Nhap vao dinh bat dau: ";
	cin >> s;
	cout << "Nhap vao dinh ket thuc: ";
	cin >> t;
	string path = "input1.txt";
	Input();
	BFS(s);
	return 0;
}

