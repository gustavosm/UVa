#include <bits/stdc++.h>


using namespace std;


set<vector<int> > s;

int n;
int v[15];
int m;

int compare(int a, int b)
{
	return b < a;
}
void dfs(vector<int> acc, int idx, int soma)
{	
	
	if (soma == n)
	{
		sort(acc.begin(), acc.end(), compare);
		s.insert(acc);
		return;
	}
	if (idx == m) return;
	
	if (soma > n) return;
	
	dfs(acc, idx + 1, soma);
	
	if (soma + v[idx] <= n)
	{
		acc.push_back(v[idx]);
		dfs(acc, idx + 1, soma + v[idx]);
	}
}

int main()
{
	vector<int> x;
	
	while (cin >> n >> m)
	{
		if (!n && !m) return 0;
		
		for (int i = 0 ; i < m ; ++i) cin >> v[i];
		
		dfs(x, 0, 0);
		cout << "Sums of " << n << ":\n";
		if (s.size() == 0) cout << "NONE\n";
		else
		{
			for (set<vector<int> > :: reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
			{
				x = (*it);
			
				for (int i = 0 ; i < x.size(); ++i)
				{
					if (i) cout << '+';
					cout << x[i];
				}
				cout << '\n';
			}
		}
		
		x.clear();
		s.clear();
		
	}
}
