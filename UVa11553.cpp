#include <bits/stdc++.h>


using namespace std;

int main()
{
	int grid[10][10];
	int n;
	int cases;
	
	vector<int> res;
	
	cin >> cases;
	while (cases--)
	{
		cin >> n;
		for(int i = 0 ; i < n ; ++i)
		   for(int j = 0 ; j < n ; ++j)
			   cin >> grid[i][j];		 
	 
		for(int i = 0 ; i < n ; ++i) res.push_back(i);
	 
		int mn = (1 << 30);
	 
		do{	 
			int top=0;
	 
			for(int i = 0 ; i < n ; ++i) top += grid[i][res[i]];
			mn = min(mn, top);
	 
		}while(next_permutation(res.begin(), res.end()));
			   
	 	res.clear();
		cout << mn << '\n';
	}
}
