#include<bits/stdc++.h>
using namespace std;
int n, x[50], d;
void xuat(){
	for(int i = 1; i <= n; i++){
		cout << x[i];
	}
	cout << "\n";
	d++;
}
void thu(int i){
	for(int j = 0; j <=1 ; j++){
		x[i] = j;
		if(i < n) thu(i+1);
		else xuat();
	}
}
int main(){
	cin >> n;
	thu(1);
	cout << "So day nhi phan do dai N la: " << d;
	return 0;
}
