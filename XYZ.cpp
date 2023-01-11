#include<conio.h>
#include<string.h>
#include<iostream>
using namespace std;
struct domain{
	char values[27];
	int n;
	int cur;
	int serviced;
};
void init(domain &d, char* s){
	strcpy(d.values, s);
	d.n	= strlen(s);
	d.cur = 0;
	d.serviced = 0;
}
char getValue(domain &d){
	char x = d.values[d.cur++];
	if(d.cur==d.n) d.cur = 0;
	if(d.serviced==0) d.serviced = 1;
	return x;
}
int isCircular(domain d){
	return (d.cur==0 && d.serviced==1);
}
void generate(){
	char vars[4];
	domain d0, d1, d2;
	init(d0, "abc");
	init(d1, "de");
	init(d2, "mnt");
	//Lay cau hinh ban dau
	vars[0] = getValue(d0);
	vars[1] = getValue(d1);
	vars[2] = getValue(d2);
	vars[3] = 0;
	// Xu ly cau hinh ban dau
	cout << vars << "\n";
	// Kiem tra dieu kien ngung
	int stop = isCircular(d0) && isCircular(d1) && isCircular(d2);
	while(!stop){
		// Lay cau hinh ke tiep
		if(isCircular(d1) && isCircular(d2)) vars[0] = getValue(d0);
		if(isCircular(d2)) vars[1] = getValue(d1);
		vars[2] = getValue(d2);
		// Xu ly cau hinh
		cout << vars << "\n";
		// Kiem tra ngung
		stop = isCircular(d0) && isCircular(d1) && isCircular(d2);
		
	}
}
int main(){
	cout << "Cac phep gan chuoi 3 ki tu: \n";
	generate();
	return 0;
}
