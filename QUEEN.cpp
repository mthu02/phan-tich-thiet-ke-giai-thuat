#include<bits/stdc++.h>
using namespace std;
bool ktra(int x, int y, int a[]){
	for(int i = 1; i < x; i++){
		if(a[i] == y || abs(i - x) == abs(y - a[i])){
			return false;
		}
	}
	return true;
}

void xuat(int a[], int size){
	for(int i = 1; i <= size; i++){
		for(int j = 1; j <= size; j++){
			if(a[i] == j) cout << "w" ;
			else cout << ".";
		}
		cout << "\n";	
	}
	cout << "\n";
	return;
}

void quaylui(int i, int a[], int n, int m, int size){
	for(int j = 1; j <= size; j++){
		if(ktra(i, j, a)){
			a[i] = j;
			if(i == size){
				if(a[n] == m){
					xuat(a, size);

				return;
				}
			quaylui(i+1, a, n, m, size);
			}
	}	
	
}

int main(){
	int size;
	cout << "Nhap vao kich thuoc ban co: ";
	cin >> size;
	int n, m;
	cout << "Nhap vao toa do con hau x, y: ";
	cin >> n >> m;
	int a[size+1]; //mang danh dau vi tri dat con queen
	for(int i = 1; i <= size; i++){
		if(i == n) a[i] = m; 
		else a[i] = 0;	
	}
	quaylui(1, a, n, m, size);
	
	return 0;
}
