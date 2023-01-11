#include<bits/stdc++.h>
#define Maxint 10000
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
int maxLeftVector(int a[], int i, int j){
	int maxSum = -Maxint;
	int sum = 0;
	for(int k = j; k >= i; k--){
		sum += a[k];
		maxSum = max(sum, maxSum);
	}
	return maxSum;
}

int maxRightVector(int a[], int i, int j){
	int maxSum = -Maxint;
	int sum = 0;
	for(int k = i; k <= j; k++){
		sum += a[k];
		maxSum = max(sum, maxSum);
	}
	return maxSum;
}

int maxSubVector(int a[], int i, int j){
	if(i == j) return a[j];
	else{
		int m = (i+j)/2;
		int ml = maxSubVector(a, i, m);
		int mr = maxSubVector(a, m+1, j);
		int mw = maxLeftVector(a,i,m) + maxRightVector(a, m+1,j);
		return max(max(ml, mr), mw);
	}
}

int main(){
	int a[MAX] = {};
    int n;
	string path = "Input2.txt";
    InPut_Arr(path, a, n);
	int m = maxSubVector(a, 0, n-1);
	cout << m;
	return 0;
}
