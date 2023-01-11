#include<iostream>
#define REP(x,a,b) for (int x=a;x<b;x++)
#define Maxint 10001
using namespace std;
int S[Maxint];
int j = 1;
struct cviec{
	int d;
	int c;
	int stt;
};
void doicho(cviec &a, cviec &b){
	cviec tmp = a;
	a = b;
	b = tmp;
}
void sapxep(cviec a[], int m){
	int i, j;
	for(int i = 0; i < m-1; i++)
	for(int j = i+1; j < m; j++){
		if(a[i].c > a[j].c){
			doicho(a[i], a[j]);
		}
	}
}
void xeplich(cviec a[], int m){
	int t = 0;
	S[0] = 1;
	for(int i = 1; i < m;i++){
		if(a[t].c < a[i].d){
			t = i;
			S[j] = a[i].stt;
			j++;
		}
	}
}
int main(){
	int n;
	cout << "Nhap vao so cong viec: ";
	cin >> n;
	if(n < 1){
		cout << "Khong co cong viec nao!";
	}
	struct cviec a[n];
	for(int i = 0; i<n; i++){
		cin >> a[i].stt >> a[i].d >> a[i].c;
	}
	sapxep(a, n);
	xeplich(a, n);
	for(int i = 0; i < j; i++){
		cout << S[i]<< " ";
	}
}

