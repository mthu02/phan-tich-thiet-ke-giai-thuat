#include <iostream>
#include <fstream>

using namespace std;
#define max 100

int n;
int a[max][max]; //ma tran trong so cua do thi
int TOUR[max];// mang ghi chu trinh
int Ddau; //diem dau cua chu trinh
int v; //Dinh dang xet;
int k; //duyet qua k dinh de chon
int w; //dinh duoc chon trong moi buoc
int mini; //chon min cac canh trong moi buoc
int COST; //trong so nho nhat cua chu trinh
int daxet[max]; //danh dau cac dinh da xet

void Input() {

	ifstream infile;
	infile.open("input1.txt");
	infile >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
		{
			infile >> a[i][j];
			if (i != j && a[i][j] == 0)a[i][j] = max;
		}
	}
}

void Print(int i) {
	cout << "\nTOUR: ";
	cout << Ddau;
	for (int j = 2; j <= i; j++)
		cout << " -> " << TOUR[j];
	cout << "\nCOST = " << COST << endl;
}

int TSP() {
	//khoi tao
	for (k = 1; k <= n; k++) {
		daxet[k] = 0; //chua dinh nao duoc xet
	}
	COST = 0;
	int i;
	v = Ddau; //chon dinh dau
	i = 1;
	TOUR[i] = v; //dua v vao chu trinh
	daxet[v] = 1;
	//tim dinh gan nhat voi dinh dang xet
	while (i < n) 
	{
		mini = max;
		for (k = 1; k <= n; k++)
		{
			if (!daxet[k]) {
				if (mini > a[v][k]) 
				{
					mini = a[v][k];
					w = k;
				}
			}
		}
		v = w;
		i++;
		TOUR[i] = v;
		daxet[v] = 1;
		COST += mini;
		
	}
	//tro ve dinh dau tien
	i++;
	TOUR[i] = Ddau;
	COST += a[v][Ddau];
	Print(i);
	return COST;
}

int main() {
	cout << "Nhap diem dau: ";
	cin >> Ddau;
	Input();
	TSP();
}

