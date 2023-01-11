#include<iostream>
using namespace std;
int main(){
	int n;
	int k;
	int c=0;
	int ans = 0;
	cin >> n >> k;
	int l = 0;
	int r = 0;
	int ri = 0;
	int a[300005];
	for(int i = 0; i <n; i++){
		cin >> a[i];
	}
	if(k == 0){
		for(int i = 0; i< n; i++){
			r = i;
			if(a[r] == 1) c=1;
				while(r++ < n && a[r]==1){	
					c++;	
					}
				ans = max(ans, c);
				if(a[i] == 1) c--;
				
				}
		if(ans != 0) cout << ans << "\n";		
		else cout << 0 << "\n";
		for(int i = 0; i< n; i++){
				cout << a[i] << " ";
			}	
	}
	else{
		for(int i = 0; i< n; i++){
			while(r < n && c <= k){
				if(a[r] == 0) c++;
				if(c <= k) r++;
			}
			if(ans < r-i){
				l = i;
				ri = r-1;
			} 
			ans = max(ans, r-i);
			if(a[i] == 0) c-=2;
		}
		cout << ans;
		cout << "\n";
		for(int i = 0; i<= l; i++){
			cout << a[i] << " ";
		}
		for(int i = l+1; i<=ri;i++){
			cout << 1 << " ";
		}
		for(int i = ri+1; i < n; i++){
			cout << a[i] << " ";
		}
	}
	
	return 0;
}
