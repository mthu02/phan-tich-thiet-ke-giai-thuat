#include<iostream>
#include<math.h>
#include <fstream>
#include <vector>
#define Max 100


using namespace std;

void In(int a[],int na)
{
    for(int i = 0; i< na; i++)
    {
        cout << " "<< a[i];
    }
}

int InPut_Arr(string path, int a[Max], int &n)
{

	ifstream in(path,ios::in);
	int number;  
    int i = 0;
    while (in >> number ) {
		a[i] = number;
        i++;
	}
    
	n = i ;
   
	in.close();

    In(a, n);
    cout << endl;
	return 0;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}


void Exchange(int a[], int i, int j, int m)
{
    for(int k = 0; k<m; k++)
    {
        swap(a[i+k], a[j+k]);
    }
}

void Tranpose(int a[], int n, int m)
{
     int i = m; 
     int j = n - m;
    //  m = m+1;
     while(i != j)
     {
        if(i > j)
        {
            Exchange(a, m -i, m, j );
            i = i - j;
        }
        else{
            j = j - i;
            Exchange(a, m-i, m + j, i);
        }
     }
     Exchange(a, m-i, m, i);
}

int main()
{
    int a[100] = {};
    int n;
    string path = "Input.txt";
    InPut_Arr(path, a, n);

    Tranpose(a, n, 3);

    In(a, n);


}