#include<bits/stdc++.h>
using namespace std;
int n, a[50], b[50], d;
void xuat(){
	for(int i = 1; i <= n; i++){
		cout << a[i];
	}
	cout << "\n";
	d++;
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
	cin >> n;
	for(int i = 1; i <= n; i++){
		b[i] = 1;
	}
	thu(1);
	cout << "So cac hoan vi la: " << d;
	return 0;
}
