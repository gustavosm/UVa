#include <bits/stdc++.h>


using namespace std;

bool ok;
vector<vector<int> > v;

vector<int> colored;

void dfs(int n, int cor)
{
	colored[n] = cor;
	
	for (int i = 0 ; i < v[n].size(); ++i)
	{
		if (colored[v[n][i]] == cor)
		{
			ok = false;
			break;
		}
		else if (colored[v[n][i]] == -1)
			dfs(v[n][i], !cor);

		if (!ok) break;		
	}
}


int main()
{
	int n, m;
	int x, y;
	
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		
		cin >> m;
		v.assign(n, vector<int> ());
		colored.assign(n, -1);
		
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> x >> y;
			
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ok = true;
		
		dfs(0, 0);
		
		if (ok) cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
		
		v.clear();
		colored.clear();
	}
}
