#include<conio.h>
#include<string.h>
#include<iostream>
using namespace std;
void InitConfig(int vars[], int n){
	for(int i = 1; i<=n; i++) vars[i]=i;
}
int isLastConfig(int vars[], int n){
	for(int i =1; i<n;i++){
		if(vars[i] < vars[i+1]) return 0;
	}
	return 1;
}
void Output(int vars[], int n, int count){
	printf("\nHoan vi thu %d:\t", count);
	for(int i=1; i<=n; i++) printf("%d ", vars[i]);
}
void NextConfig(int vars[], int n){
	int j=n-1;
	while(j>0 && vars[j]>vars[j+1]) j--;
	int k=n;
	while(vars[j] > vars[k]) k--;
	int t = vars[j];
	vars[j] = vars[k];
	vars[k] = t;
	int left=j+1, right = n;
	while(left < right){
		t = vars[left];
		vars[left] = vars[right];
		vars[right] = t;
		left++;
		right--;
	}
}
void Generate(int vars[], int n){
	InitConfig(vars, n);
	int count=1;
	Output(vars,n,count);
	int stop = isLastConfig(vars, n);
	while(!stop){
		NextConfig(vars,n);
		count++;
		Output(vars,n,count);
		stop=isLastConfig(vars,n);
		
	}
}
int main(){
	int n;
	printf("Nhap so phan tu cua tap: ");
	scanf("%d", &n);
	int* vars = new int[n+1];
	Generate(vars, n);
	return 0;
}
