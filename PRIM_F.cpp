#include <bits/stdc++.h>
#define MIN -1000
using namespace std;
	int n,m, u, v, t, sum;
	vector< vector< pair<int, int > > > dinh(-MIN);
	//mang danh dau cac dinh da xet
	vector< bool > daxet(-MIN);
	pair<int, int> ts;
int InPut(string path) 
{
	ifstream in(path,ios::in);
	int number;
    in>> number;
    n = number;  
    in>> number;
    m = number;
    for(int i = 1; i <=m; i++){
    	in>> number;
		u = number;
		in>> number;
		v = number;
		in>> number;
		t = number;
		ts = make_pair(v-1,t);
		dinh[u-1].push_back(ts);
		ts = make_pair(u-1,t);
		dinh[v-1].push_back(ts);
	}
	in.close();
	return 0;
}
int main(){
	string path = "input1.txt";
	InPut(path);
	//khoi tao bien dem so dinh da duyet u
	u = 0;
	//khoi tao bien t luu trong so 
	t = -MIN;
	sum = 0;
	//khoi tao hang doi - duyet tu dinh 0
	ts = make_pair(MIN,0);
	priority_queue< pair<int, int> > q;
	q.push(ts);
	while(!q.empty())
	{
		ts = q.top();
		q.pop();
		v = ts.second;
		if(!daxet[v])
		{
			//tang so dinh da duoc chon len
			++u;
			if(ts.first!=MIN){
				//cout << ts.first << " ";
				sum += ts.first;
			}
			//da duyet xong thoat khoi vong lap
			if(u == n) break;
			//danh dau dinh da xet
			daxet[v] = true;
			//dua cac dinh ke voi dinh dang xet vao hang doi
			for(int i=0; i< dinh[v].size(); ++i)
				if(!daxet[dinh[v][i].first])
					q.push(make_pair(-dinh[v][i].second,dinh[v][i].first));
		}
	}
	cout<<-sum;
	return 0;
	}
