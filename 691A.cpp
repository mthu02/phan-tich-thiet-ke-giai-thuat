#include<iostream>
using namespace std;
long long a[100];
int n;
int main(){
	cin >> n;
	a[0] = 0;
	a[n+1] = 90;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n+1; i++){
		if(a[i] - a[i-1] > 15){
			cout << a[i-1]+15;
			return 0;
		}
	}
	cout << 90;
	return 0;
}
