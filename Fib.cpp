#include<iostream>
#define Maxint 10001
using namespace std;
int S[Maxint];
int DPFib(int n){
	S[0] = 0;
	S[1] = 1;
	if(n > 1){
		for(int k = 2; k <= n; k++){
			S[k] = S[k-1] + S[k-2];
		}
	}
	return S[n];
}
int main(){
	int n;
	cin >> n;
	cout << DPFib(n);
	return 0;
}
