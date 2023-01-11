#include<iostream>
#define Maxint 10001
using namespace std;
int a[Maxint];
int MaxS, MaxE, s, e, s1, n;
//s: chi so dau, e: chi so cuoi, s1: chi so dau tam
void subMax(){
	MaxS = a[1];
	MaxE = a[1];
	s = 1;
	e = 1;
	s1 = 1;
	for(int i = 2; i <= n; i++){
		if (MaxE > 0) MaxE += a[i];
		else{
			MaxE = a[i];
			s1 = i;
		}
		if(MaxE > MaxS){
			MaxS = MaxE;
			s = s1;
			e = i;
		}
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	subMax();
	cout << MaxS << "\n";
	for(int i = s; i <= e; i++){
		cout << a[i] << " ";
	}
	return 0;
}
