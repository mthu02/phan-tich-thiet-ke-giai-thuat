#include<iostream>
using namespace std;
int a[30005];
int n, t;
int main(){
	cin >> n >> t;
	for(int i = 1; i <= n-1; i++){
		cin >> a[i];
	}
	int p = 1;
	while (p < t){
		p = a[p] + p;
	}
	if (p == t){
		cout << "YES";
	}
	else cout << "NO";
	return 0;
}

