#include<bits/stdc++.h>
using namespace std;

char s[50] = "";

char *bachuso(unsigned int n)
{
  char kyso[10][5]= {"", "mot", "hai", "ba", "bon", "nam", "sau",
                    "bay", "tam", "chin"};
  int donvi, chuc, tram;

  s[0] = 0;
  donvi = n % 10;
  n /= 10;
  chuc = n % 10;
  tram = n / 10;
  if (tram > 0)
  {
    strcat(s, kyso[tram]);
    strcat(s, " tram ");
  }
  if (chuc > 0)
  {
    if (chuc == 1)
       strcat(s, "muoi ");
    else
    {
       strcat(s, kyso[chuc]);
       strcat(s, " muoi ");
    }
  }
  if (donvi > 0)
  {
     if (chuc == 0 && tram != 0)
       strcat(s, "le ");
     if (donvi == 1)
       strcat(s, "mot");
     else if (donvi == 5 && (chuc != 0 && tram != 0))
       strcat(s, "lam");
     else if (donvi == 5 && (chuc = 0 && tram != 0))
       strcat(s, "nam");
     else
       strcat(s, kyso[donvi]);
  }
  return s;
}

int main()
{
  unsigned long n;
  unsigned ngan, trieu, ty, donvi;
  char chuoi[200];

  cout << "Nhap so tien: ";
  cin >> n;
  cout << "So " << n << " doc bang chu la : ";
  if (n == 0)
    cout << "khong";
  else
  {
     donvi = n % 1000;
     n /= 1000;
     ngan = n % 1000;
     n /= 1000;
     trieu = n % 1000;
     ty = n / 1000;
     chuoi[0] = 0;
     if (ty > 0)
       cout << bachuso(ty) << " ty ";
     if (trieu > 0)
       cout << bachuso(trieu) << " trieu ";
     if (ngan > 0)
       cout << bachuso(ngan) << " ngan ";
     if (donvi > 0)
       cout << bachuso(donvi) << " dong ";
  }
	return 0;
}
