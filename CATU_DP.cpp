#include<bits/stdc++.h>
#define REP(x,a,b) for (int x=a;x<=b;x++)
#define Max 100
using namespace std;

struct item{
	int weight;
	int value;
};
int InPut_Arr(string path, item dv[Max], int &n, int &m) 
{

	ifstream in(path,ios::in);
	int number;

    in>> number;
    n = number;
    
    in>> number;
    m = number;

    for(int i = 1; i <= n; i++){
    	in>> number;
		dv[i].weight = number;
		in>> number;
		dv[i].value = number;
	}

	in.close();

	return 0;
}

int main(){
	int h[Max], c[Max];
	struct item items[Max] = {};
    int n,m;
    int t=0;
	string path = "input1.txt";
    InPut_Arr(path, items, n, m);
	int F[n+1][m+1];
	REP(x, 0, m){
		F[0][x] = 0;
	}
	REP(i, 1, n){
		REP(j, 0, m){
			F[i][j] = F[i-1][j];
			if((j >= items[i].weight) && (F[i][j] < F[i-1][j-items[i].weight] + items[i].value)){
				F[i][j] = F[i-1][j-items[i].weight] + items[i].value;
			}
		}
	}
	cout << F[n][m] << "\n";
	int hang = n;
	int cot = m;
	while(n != 0){
		if (F[n][m] != F[n-1][m]){
			cout << n << " ";
			h[t] = n;
			c[t] = m;
			m -= items[n].weight;
			t++;
		}
		n--;
	}
	cout << endl;
	REP(i,0,hang){
		REP(j, 0, cot){
			for(int k = 0; k<=t; k++){
				if(i==h[k] && j == c[k] && i != 0) cout << ".";
			}
			cout << F[i][j] << " ";
		}
		cout << endl;
	}
	
	
	
	
}
