#include<bits/stdc++.h>
using namespace std;

void minMax(int a[], int l, int r, int &min, int &max){

	if(l == r){
		min = a[l];
		max = a[l];
	}
	else{
		int min1, max1, min2, max2;
		minMax(a, l, (l+r)/2, min1, max1);
		minMax(a, (l+r)/2+1, r, min2, max2);
		if(min1 < min2) min = min1;
		else min = min2;
		if(max1 > max2) max = max1;
		else max = max2;
	}
}
int main(){
	int min, max;
	int a[] = {3, 5, 8, 9, 4, 2, 7, 5, 3, 9, 8};
	minMax(a, 0, 10, min, max);
	cout << min << "\n" << max;
	return 0;
}
