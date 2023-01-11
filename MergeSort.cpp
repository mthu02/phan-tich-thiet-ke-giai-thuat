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
void merge(int a[], int l, int t, int r){
	int i = l;
	int j = t + 1;
	int p = l;
	int c[MAX];
	while (i <= t && j <= r){
		if(a[i] < a[j]){
			c[p] = a[i];
			i++;
		}
		else{
			c[p] = a[j];
			j++;
		}
		p++;
	}
	while(i <= t){
		c[p] = a[i];
		i++;
		p++;
	}
	while(j <= r){
		c[p] = a[j];
		j++;
		p++;
	}
	for (int i = l; i <= r; i++){
		a[i] = c[i];
	}
}
void mergeSort(int a[], int l, int r){
	if (r>l){
		
		int t = (l+r)/2;
		mergeSort(a,l,t);
		mergeSort(a,t+1,r);
		merge(a,l,t,r);
	}
	else return;
}

int main(){
	int a[MAX] = {};
    int n;
	string path = "Input2.txt";
    InPut_Arr(path, a, n);
	mergeSort(a, 0, n-1);	
	for(int i = 0; i <= n-1; i++){
		cout << a[i] << " ";
	}
	return 0;
}
