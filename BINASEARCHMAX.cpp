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
int binarySearchMax(int arr[], int l, int r)
{	
	if(l==r){
		return arr[l];
	}
    else {
        int mid = (r + l) / 2;
        return max(binarySearchMax(arr, l, mid),
        binarySearchMax(arr, mid+1, r));		
	}
}
int main(){
	int a[MAX] = {};
    int n;
	string path = "Input2.txt";
    InPut_Arr(path, a, n);
	int max1  = binarySearchMax(a, 0, n-1);
	cout << max1;
}
