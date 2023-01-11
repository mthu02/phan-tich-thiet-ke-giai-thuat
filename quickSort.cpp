#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int InPut_Arr(string path, int a[MAX], int &n)
{
	ifstream in(path,ios::in);
	int number;  
    int i = 0;
    while (in >> number ) {
		a[i] = number;
        i++;
	}    
	n = i ;
	in.close();
	return 0;
}
void swap(int &a, int &b){
	int c = a;
	a = b;
	b = c;
}
int partition(int a[], int l, int r){
	int x = a[l];
	int i = l+1;
	int j = r;
	while(i <= j){
		while(a[i] <= x && i <=r) i++;
		while(a[j] > x) j--;
		if(i<=j){
			swap(a[i], a[j]);
		}
	}	
	swap(a[l], a[j]);
	return j;
}
void quickSort(int a[], int l, int r){
	if(l >= r) return;
	int i = partition(a, l, r);
	quickSort(a, l, i-1);
	quickSort(a, i+1, r);
}
int main(){
	int a[MAX] = {};
    int n;
	string path = "Input2.txt";
    InPut_Arr(path, a, n);
	quickSort(a, 0, n-1);
	for(int i = 0; i <= n-1; i++){
		cout << a[i] << " ";
	}
	return 0;
}
