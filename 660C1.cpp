#include<iostream>
using namespace std;
const int N = 1200300;

int n, k;
int a[N];

void solve() {
	int ansl = 0, ansr = 0;
	int j = 0, cnt = 0;
	for(int i=0; i< n;i++) {
		if (j < i) {
			j = i;
			cnt = 0;
		}

		while (j < n) {
			int ncnt = cnt + !a[j];
			if (ncnt > k) break;
			cnt += !a[j];
			j++;
		}
		
		if (j - i > ansr - ansl)
			ansl = i, ansr = j;

		if (cnt > 0) cnt -= !a[i];
	}

	cout << ansr - ansl << endl;
	for(int i= ansl; i < ansr; i++) a[i] = 1;
	for(int i=0; i< n;i++) {
		if (i) putchar(' ');
		printf("%d", a[i]);
	}
	puts("");
}
int main(){
	cin >> n >> k;
	for(int i = 0; i <n; i++){
		cin >> a[i];
	}
	solve();
	return 0;
}
