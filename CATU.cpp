#include<bits/stdc++.h>
#define Max 100
using namespace std;
int w[Max], v[Max], x[Max], y[Max], S, Gttu, Tl,n,m;
int InPut(string path) 
{
	ifstream in(path,ios::in);
	int number;
    in>> number;
    n = number;   
    in>> number;
    m = number;
    for(int i = 0; i < n; i++){
    	in>> number;
		w[i] = number;
		in>> number;
		v[i] = number;
	}
	in.close();
	return 0;
}
void init(){
	for(int i=1; i<=n; i++){
		x[i] = 0;
	}
	S = 0;
	Gttu = 0;
	Tl = 0;
}
void gan(){
	for(int i=1; i<=n;i++){
		y[i] = 0;
	}
	for(int i=1; i<=n;i++){
		y[i] = x[i];
	}
}
void xuat(){
	for(int m = 1; m<n ; m++){
		cout << y[m] << ", ";
	}
	cout << y[n] << "\n";
}
void Try(int i){
	int j, g;
	for(j = 1; j>= 0; j--){
		x[i] = j;
		Tl += w[i]*x[i];
		S += v[i]*x[i];
		if(i==n){
			if(S>Gttu){
				Gttu = S;
				gan();
			}
		}
		else{
			g = S + (m-Tl)*v[i+1]/w[i+1];
			cout << g << " ";
			if(g>Gttu && m > Tl){
				Try(i+1);
			}
		}
		Tl -= w[i]*x[i];
		S -= v[i]*x[i];
	}
	
}
int main(){
	string path = "input1.txt";
	InPut(path);
	init();
	Try(1);
	xuat();
	return 0;
}
