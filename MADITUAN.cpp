#include<bits/stdc++.h>
using namespace std;
int p[8] = {-2,-2,-1,-1,1,1,2,2};
int q[8] = {-1,1,-2,2,-2,2,-1,1};
int  x, y, n, a[50][50];
void inkq(){
    for (int i=0;i<n;i++){
    	for (int j=0;j<n;j++)
			printf("%3d",a[i][j]);
    	cout << endl;
    }  
	printf ("----------------------\n");
}
void thu(int x, int y, int i){
    for(int k=0;k<8;k++){
        int x1 = x+p[k];
		int y1 = y+q[k];
        if (x1 >= 0 && y1 < n && x1 < n && y1 >= 0 && a[x1][y1] == 0){
            a[x1][y1] = i;
            if (i < n*n)
                thu(x1, y1, i+1);
            else
            	inkq();   
        	a[x1][y1] = 0;
        }
    	        
    }
}
int main(){
    cout << "Kich thuoc ban co : ";
    cin >> n;
    cout << "Nhap vi tri xuat phat :";
    cin >> x >> y;
    for (int i=0;i<n;i++)
    	for (int j=0;j<n;j++)
    		a[i][j]=0;
    a[x][y]=1;
    thu(x,y,2);
    return 0;
}
