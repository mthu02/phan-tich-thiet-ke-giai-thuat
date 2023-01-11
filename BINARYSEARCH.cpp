#include<bits/stdc++.h>
#define Max 100
using namespace std;
int InPut_Arr(string path, int a[Max], int &n)
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
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid+1;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
    }
    else return -1;
}
int main(){
	int a[100] = {};
    int n;
	string path = "Input1.txt";
    InPut_Arr(path, a, n);
	int b = 4;
	quickSort(a, 0, n-1);
	cout << binarySearch(a, 0, n-1, b);
	return 0;
}
