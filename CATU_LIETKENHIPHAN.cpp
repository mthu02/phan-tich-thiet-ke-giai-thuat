#include<bits/stdc++.h>
#define REP(x,a,b) for (int x=a;x<=b;x++)
#define Max 100
using namespace std;
int n, x[Max], c[Max], d, m, maxV = 0,maxW, mV, mW;
struct item{
	int weight;
	int value;
}items[Max];
void ktra(){
	mW = 0;
	mV = 0;
	REP(i, 1, n){
		mW += items[i].weight*x[i];
		mV += items[i].value*x[i];
	}

	if(mW <= m && mV > maxV){
		maxV = mV;
		maxW = mW;
		REP(i, 1, n){
			c[i] = x[i];
		
		}
	}
	return;
}
void thu(int i){
	REP(j, 0, 1){
		x[i] = j;
		if(i < n) thu(i+1);
		else ktra();
	}
}
int InPut_Arr(string path, item dv[Max], int &n, int &m) 
{

	ifstream in(path,ios::in);
	int number;

    in>> number;
    n = number;
    
    in>> number;
    m = number;

    for(int i = 0; i < n; i++){
    	in>> number;
		dv[i].weight = number;
		in>> number;
		dv[i].value = number;
	}

	in.close();

	return 0;
}

int main(){
	string path = "input1.txt";
    InPut_Arr(path, items, n, m);
	thu(1);
	cout << "Tong gia tri: " << maxV << "\n";
	cout << "Tong trong luong: " << maxW << "\n";
	cout << "Nhung vat duoc mang di: ";
	REP(i, 1, n){
		if(c[i] != 0) cout << i << ", ";
	}
	return 0;
}


