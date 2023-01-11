#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

int a[MAX][MAX];
int n;
int m;
int daxet[MAX], mau[MAX];

void docfile()
{
	ifstream in;
	in.open("mau1.txt");
	in >> n;
	for (int i = 1; i <= n; i++)
	{
		daxet[i] = 0;
		mau[i] = 0;
		for (int j = 1; j <= n; j++)
			in >> a[i][j];
	}

	in.close();
}

void ToMau()
{
	int demMau = 0;
	int demDinh = 0;
	int i = 1;  // luu vi tri dinh hien tai dang xet

	do {
		demDinh++;
		mau[i] = 0;  // khoi tao mau nho nhat cho dinh i
		do {
			mau[i] ++;
			demMau = 0;
			for (int j = 1; j <= n; j++) // kiem tra mau hien tai cua dinh co trung voi mau cua cac dinh ke voi no
			{
				if (a[i][j] != 0 && daxet[j] == 1)
				{
					if (mau[i] == mau[j]) demMau++;
				}
			}
		} while (demMau != 0);
		daxet[i] = 1;

		int tim = 0; // kiem tra xem 
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] != 0 && daxet[j] == 0)
				// tim dinh ke voi i va chua duoc xet
			{
				i = j;
				tim++;
				break;
			}
		}
		if (tim == 0) {
			for (int j = 1; j <= n; j++) {
				if (daxet[j] == 0) {
					i = j;
					break;
				}
			}
		}

	} while (demDinh < n);
	for (i = 1; i <= n; i++)
		cout << "Mau dinh " << i << ": " << mau[i] << endl;
}

int main()
{
	docfile();
	ToMau();
	return 0;
}

