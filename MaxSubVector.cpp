#include<bits/stdc++.h>
#define maxn 100
using namespace std;
int n;
int a[maxn];
int MaxS[maxn],MaxE[maxn];
int s1[maxn],s[maxn],e[maxn];

using namespace std;

int InPut_Arr(string path)
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
	return 0;
}
int MaxSubSeq(){
	MaxE[1]=a[1];s1[1]=1;
  	MaxS[1]=a[1];s[1]=1;e[1]=1;
  	for(int i=2;i<=n;i++){	
    	// Tinh MaxE[i]=Max(MaxE[i-1],0)+a[i];
    	if (MaxE[i-1]>0){
      		MaxE[i]=MaxE[i-1]+a[i];
      		s1[i]=s1[i-1];
      		
    	}
    	else{
      		MaxE[i]=a[i];
      		s1[i]=i;
    	}
    	// Tinh MaxS[i]=Max(MaxS[i-1],MaxE[i]);
    	if (MaxS[i-1]>=MaxE[i]){
      		MaxS[i]=MaxS[i-1];
      		s[i]=s[i-1];e[i]=e[i-1];
      		}
    	else{
      		MaxS[i]=MaxE[i];
      		s[i]=s1[i];e[i]=i;
      	}
  	}
}
int main(){
	string path = "Input2.txt";
    InPut_Arr(path);
	MaxSubSeq();
	cout << "Day con co tong Max la: ";
	for(int i=s[n];i<=e[n];i++) cout << a[i] << " ";
	cout << endl;
	cout << "Trong so la: " << MaxS[n];
}


