#include<iostream>
using namespace std;
int main(){
	int n;
	int t;
	int sum=0;
	int ans = 0;
	cin >> n >> t;
	int r = 0;
	int a[100005];
	for(int i = 0; i <n; i++){
		cin >> a[i];
	}
	for(int i = 0; i< n; i++){
		while(r < n && sum + a[r] <= t){
			sum += a[r];
			r++;
		}
		ans = max(ans, r-i);
		sum -= a[i];
	}
	cout << ans;
	return 0;
}
