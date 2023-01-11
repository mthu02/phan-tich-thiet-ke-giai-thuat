#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int c = 0;
	int tien[5];
	tien[0] = 100;
	tien[1] = 50;
	tien[2] = 20;
	tien[3] = 10;
	for(int i = 0; i < 4; i++){
		cout << "So to tien menh gia " << tien[i] << " :";
		while(n - tien[i] >= 0){
			n = n - tien[i];
			c++;
		}
		cout << c << "\n";
		c = 0;
	}
	return 0;
}
