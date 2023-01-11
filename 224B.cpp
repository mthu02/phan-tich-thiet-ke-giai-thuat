#include<iostream>
#include <set>
using namespace std;
int main(){
	set<int> d;
	int n,k;
	int c = 1;
	int s;
	int a[100001];
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int i = 1;
	while(a[i] == a[i+1]) i++;
	s = i;
	for(int i = s; i <= n; i++){
		d.insert(a[i]);
		if(d.size() == k){
			cout << s << " " << i;
			return 0;
		} 
	}
	cout << -1 << " " << -1;
	return 0;
}
