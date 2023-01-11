#include<bits/stdc++.h>
using namespace std;
bool check(string s){
	if(s[0] == 45) return false;
	else if(s[0] == 49 && s[1] >= 49 && s[1] <= 57) return false;
	return true;
}
int main(){
	string s;
	cout << "Nhap diem so: ";
	cin >> s;
	while (!check(s)){
		cout << "Ban da nhap sai diem, moi ban nhap lai: ";
		cin >> s;
	}
	if (s[1] == 46 || s[1] == 44){
		for (int i = 0; i < s.length() ;i++){
			if(s[i] == 48) cout << "Khong ";
			else if(s[i] == 49) cout << "Mot ";
			else if(s[i] == 50) cout << "Hai ";
			else if(s[i] == 51) cout << "Ba ";
			else if(s[i] == 52) cout << "Bon ";
			else if(s[i] == 53) cout << "Nam ";
			else if(s[i] == 54) cout << "Sau ";
			else if(s[i] == 55)cout << "Bay ";
			else if(s[i] == 56) cout << "Tam ";
			else if(s[i] == 57) cout << "Chin ";
			else if(s[i] == 44) cout << "Phay ";
			else cout << "Cham ";
		}
	}
	else{
		cout << "Muoi ";
		if(s[2] == 44) cout << "Phay ";
		else cout << "Cham ";
		for (int i = 3; i < s.length(); i++){
			if(s[i] == 48) cout << "Khong ";
			else if(s[i] == 49) cout << "Mot ";
			else if(s[i] == 50) cout << "Hai ";
			else if(s[i] == 51) cout << "Ba ";
			else if(s[i] == 52) cout << "Bon ";
			else if(s[i] == 53) cout << "Nam ";
			else if(s[i] == 54) cout << "Sau ";
			else if(s[i] == 55)cout << "Bay ";
			else if(s[i] == 56) cout << "Tam ";
			else if(s[i] == 57) cout << "Chin ";
		}
	}
	
}
