#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int D[MAX];
int n, m;//n la so dinh, m la so canh
struct canh{
	int d;
	int c;
	int w;
};
int InPut_Arr(string path, canh a[MAX], int &n, int &m) 
{
	ifstream in(path,ios::in);
	int number;

    in>> number;
    n = number;
    
    in>> number;
    m = number;

    for(int i = 1; i <=m; i++){
    	in>> number;
		a[i].d = number;
		in>> number;
		a[i].c = number;
		in>> number;
		a[i].w = number;
	}
	in.close();
	return 0;
}

void doicho(canh &a, canh &b){
	canh tmp = a;
	a = b;
	b = tmp;
}
void sapxep(canh a[]){
	int i, j;
	for(int i = 1; i < m; i++)
	for(int j = i+1; j < m+1; j++){
		if(a[i].w > a[j].w){
			doicho(a[i], a[j]);
		}
	}
	for(int i = 1; i <= m; i++){
		cout << a[i].d << " ";
		cout << a[i].c << " ";
		cout << a[i].w << " ";
		cout << endl;
	}
}
void khoitao(){
	for(int i = 1; i<=n; i++){
		D[i] = i;
	}
}
int kruskal(canh a[]){
	int k = 1;
	int maud, mauc;
	int trongso = 0;	
	for(int i = 1; i <= m; i++){		
		if(k == n+1) return trongso;
		if(D[a[i].d] != D[a[i].c]){
			
			trongso += a[i].w;
			maud = D[a[i].d];
			mauc = D[a[i].c];
			k++;
			
		}
		for(int j = 1; j <= n; j++){
			if(D[j] == mauc) D[j] = maud;
		}
	}
	return trongso;
}
int main(){
	struct canh a[MAX] = {};
	string path = "input1.txt";
    InPut_Arr(path, a, n, m);
	khoitao();
	sapxep(a);
	int ts = kruskal(a);
	cout << ts;
	return 0;
}
