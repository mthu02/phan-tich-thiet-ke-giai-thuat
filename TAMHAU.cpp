#include <conio.h>
#include <stdio.h>
int x[9], a[9];
int b[16], c[16];
int thu(int i);
int init();
int printkq();
int init(){
	for(int i = 1; i <=8; i++){
		x[i] = 0;
		a[i] = 1;
	}
	for(int i = 1; i <= 15; i++){
		b[i] = 1;
		c[i] = 1;
	}
	return 0;
}
int printkq(){
	for(int i = 1; i <= 8; i++)
		printf("%d-",x[i]);
	printf("\n");
	return 0;
}
int thu(int i){
	for(int j = 1; j <= 8; j++){
		if(a[j] && b[i+j-1] && c[i-j+8]){
			x[i] = j;
			a[j] = 0;
			b[i+j-1] = 0;
			c[i-j+8] = 0;
			if(i < 8) thu(i+1);
			else printkq();
			a[j] = 1;
			b[i+j-1] = 1;
			c[i-j+8] = 1;
		}
	}
}
int main(){
	init();
	thu(1);
	return 0;
}
