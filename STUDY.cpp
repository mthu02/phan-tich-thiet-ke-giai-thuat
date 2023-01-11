#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int weight[n][m];
    int v[n][m];
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			cin >> v[i][j];	
			weight[i][j] = j;		
		}
	}
	int K[m+1][n+1][n+1];
	for (int w=0; w <= n; w++) K[0][0][w] = 0;
	for(int i = 1; i <=m; i++){
		for(int w = 0; w<= n; w++){
			K[i][w] = K[i-1][w];
			if (w >= weight[i] && K[i][w] < v[i]+K[i-1][w-weight[i]]){
				K[i][w] = v[i]+K[i-1][w-weight[i]];
			}
		}
	}
	cout<< K[n][m] << "\n";
	int w = m;
	for(int i = n; i > 0; i--){
		if(K[i][w] != K[i-1][w]){
			cout << i << " ";
			w = w - weight[i];
		}
	}
	
	return 0;
}
    
