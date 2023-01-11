#include<bits/stdc++.h>
using namespace std;
string reverseStr(string& str)
{
    int n = str.length();
    int m = str.length()/2;
    for (int i = 0; i < m; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}
int main(){
	string a1 = "4567";
	string a = reverseStr(a1);
	int b = 6;
	int n = a.length();
	int nho = 0;
	int tg;
	int c[n];
	for (int i = 0; i < n; i++){
		tg = b*(a[i]-48) + nho;
		c[i] = tg % 10;
		nho = tg/10;
	}
	if (nho > 0){
		c[n] = nho;
		n++;
	}
	for (int i = n-1; i >= 0; i--){
		cout << c[i];
	}
	return 0;
}
