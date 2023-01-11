#include<bits/stdc++.h>
#define Max 100
using namespace std;

struct dovat{
	int w;
	int v;
};

void swap(dovat &a, dovat &b){
	dovat t = a;
	a = b;
	b = t;
}

void sapxep_1(dovat a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(a[i].v < a[j].v){
				swap(a[i], a[j]);
			}
		}
	}
}

void sapxep_2(dovat a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(a[i].w > a[j].w){
				swap(a[i], a[j]);
			}
		}
	}
}

void sapxep_3(dovat a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if((a[i].v/a[i].w) > (a[j].v/a[j].w)){
				swap(a[i], a[j]);
			}
		}
	}
}

int InPut_Arr(string path, dovat dv[Max], int &n, int &m) 
{

	ifstream in(path,ios::in);
	int number;

    in>> number;
    n = number;
    
    in>> number;
    m = number;

    for(int i = 0; i < n; i++){
    	in>> number;
		dv[i].w = number;
		in>> number;
		dv[i].v = number;
	}

	in.close();

	return 0;
}

int main(){
	struct dovat dv[Max] = {};
    int n,m;
	string path = "input1.txt";
    InPut_Arr(path, dv, n, m);
	int sum = 0;
	sapxep_3(dv, n);
	for(int i = 0; i < n; i++){
		if(m - dv[i].w >= 0){
			cout << dv[i].w << " ";
			m = m - dv[i].w;
			sum += dv[i].v;
		}
		else break;
	}
	cout << "\n" << sum;
	return 0;
}
