#include<stdio.h>
#include<conio.h>
void Init(int* result, int k){
	for(int i=1; i <= k; i++) result[i]=i;
}
void Process(int* result, int n){
	printf("\n");
	for(int i=1; i<=n; i++) printf("%d, ", result[i]);
}
void NextCombi(int* result, int n, int k, int &stop){
	int i = k;
	while(i > 0 && result[i] == n-k+i) i--;
	if(i>0){
		result[i]++;
		for(int j=i+1; j<=k; j++) result[j]=result[i]+j-i;
	}
	else stop=1;
}
void Generate(int* result, int n, int k){
	int stop=0;
	Init(result, k);
	Process(result, k);
	while(!stop){
		NextCombi(result, n, k, stop);
		if(!stop) Process(result, k);
	}
}
int main(){
	int n, k, *result;
	printf("Nhap so phan tu cua tap n: "); 
	scanf("%d", &n);
	printf("Nhap so phan tu cua tap con k: ");
	scanf("%d", &k);
	result = new int[k+1];
	Generate(result, n, k);
	return 0;
}
