#include<bits/stdc++.h>
#define REP(x,a,b) for (int x=a;x<b;x++)
#define Maxint 10001
using namespace std;
int n;
int a[Maxint][Maxint];	
void ReadMatrix (string filePath) 
{
	ifstream in(filePath,ios::in);

	int number;  //Variable to hold each number as it is read
    int i = 1;
    int j = 1;
	in >> number;
	n = number; // so dau tien la so hang cot
    //Read number using the extraction (>>) operator
    while (in >> number && i <= n)// n la so hang
    {
    	if(number != 0) a[i][j] = number;
        else a[i][j] = Maxint;
        j++;
        if(j == n+1)// m la so cot
        {
            i++;
            j = 1;
        }
    }
	in.close();
}
void xuatdd(int s, int k, int Ddnn[Maxint]){
		int i;
		cout << "\nDuong di ngan nhat tu "<<s<<" den "<<k<<" la: ";
		i = k;
		while(i!=s){
			cout << i<< "<--";
			i = Ddnn[i];
		}
		cout << s;
	}
void dijkstra(int s, int &n, int a[Maxint][Maxint]){
	int Ddnn[Maxint];
	int i, k, dht, Min;
	int Daxet[Maxint];
	int L[Maxint];
	REP(i, 1, n+1){
		Daxet[i] = 0;
		L[i] = Maxint;
	}
	Daxet[s] = 1;
	L[s] = 0;
	dht = s;
	int h = 1;
	while(h <= n-1){
		Min = Maxint;
		REP(i, 1, n+1){
			if(!Daxet[i]){
				if(L[dht] + a[dht][i]<L[i]){		
					L[i] = L[dht]+a[dht][i];
					Ddnn[i] = dht;
				}
				if(L[i] < Min){
					Min = L[i];
					k = i;
				}		
			}
		}
		xuatdd(s, k, Ddnn);
		cout << "\nTrong so: " << L[k];
		dht = k;
		Daxet[dht] = 1;
		h++;			
	}
}

int main(){
	int s;
	cout << "Nhap vao dinh bat dau: ";
	cin >> s;
	string path = "input1.txt";
	ReadMatrix(path);
	dijkstra(s, n, a);
	return 0;		
}
