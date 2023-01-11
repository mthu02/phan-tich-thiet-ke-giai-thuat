#include<conio.h>
#include<string.h>
#include<iostream>
#define TRUE 1
#define FALSE 0
using namespace std;
void InitConfig(char vars[], int n){
	for(int i = 0; i<n; i++) vars[i]='0';
}
void Output(char vars[], int n, int count){
	printf("\nTap con thu %d:\t", count);
	for(int i=0; i<n; i++) putchar(vars[i]);
}
void NextConfig(char vars[], int n){
	int i=n-1;
	while(i>0 && vars[i]=='1'){
		vars[i]='0';
		i--;
	}
	vars[i]='1';
}
int LastConfig(char* vars, int n){
	for(int i=0; i<n; i++){
		if(vars[i]=='0') return 0;
	}
	return 1;
}
void Generate(char vars[], int n){
	int stop = FALSE;
	InitConfig(vars, n); //khoi tao cau hinh ban dau
	int count=1;
	Output(vars, n, count); //xu li cau hinh dang co
	stop = LastConfig(vars, n); //kiem tra co phai cau hinh cuoi khong
	while(!stop){
		NextConfig(vars, n); // sinh cau hinh ke tiep
		count++;
		Output(vars, n, count); //xu li cau hinh dang co
		stop=LastConfig(vars,n); // Kiem tra ngung
	}
}
int main(){
	int n;
	printf("Nhap so phan tu cua tap:");
	scanf("%d",&n);
	char* vars= new char[n];
	Generate(vars, n);
	return 0;
}
