#include<bits/stdc++.h>
using namespace std;
int s[10][10] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
				{0, 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                {0, 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                {0, 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                {0, 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                {0, 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                {0, 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                {0, 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                {0, 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                {0, 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
bool check(int r, int c, int k){
	for(int i = 1; i <= 9; i++){
		if(s[r][i] == k) return false;
	}
	for(int i = 1; i <= 9; i++){
		if(s[i][c] == k) return false;
	}
	int a = (r-1)/3;
	int b = (c-1)/3;
	for(int i = 3*a+1; i <= 3*a+3; i++){
		for(int j = 3*b+1; j <= 3*b+3; j++){
			if (s[i][j] == k) return false;
		}
	}
	return true;
}
void xuat(){
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			cout << s[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}
void sudoku(int x, int y){
	if(y == 10){
		if(x == 9){
			xuat();
			return;
		}
		else sudoku(x+1, 1);
	}
	else if (s[x][y] == 0){
		for(int k = 1; k <= 9; k++){
			if (check(x,y,k)){
				s[x][y] = k;
				sudoku(x,y+1);
				s[x][y] = 0;	
			}
		}
	}
	else sudoku(x,y+1);
}
int main(){
	sudoku(1,1);
	return 0;
}
