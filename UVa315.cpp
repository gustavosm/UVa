#include <bits/stdc++.h>


using namespace std;

vector<vector<int> > v;
vector<int> dfs_low, dfs_num, dfs_parent, av;
int dfsNumber, dfsRoot, rootChildren;

void dfs(int n)
{
	dfs_low[n] = dfs_num[n] = ++dfsNumber;
	for (int j = 0 ; j < (int)v[n].size(); ++j)
	{
		int u = v[n][j];
		if (dfs_num[u] == 0)
		{
			dfs_parent[u] = n;
			if (n == dfsRoot) ++rootChildren;
			
			dfs(u);
			
			if (dfs_low[u] >= dfs_num[n])
				av[n] = 1;
				
			dfs_low[n] = min(dfs_low[n], dfs_low[u]);
		}
		else if (u != dfs_parent[n])
		{
			dfs_low[n] = min(dfs_low[n], dfs_num[u]);
		}
	}
}

int main()
{
	int n;
	string s;
	int u, w;
	int articulation;
	
	stringstream ss;
	while (1)
	{
		cin >> n;
		
		if (!n) return 0;
		v.assign(n, vector<int> ());
		dfs_low.assign(n, 0);
		dfs_num.assign(n, 0);
		dfs_parent.assign(n, 0);
		av.assign(n, 0);
		
		while (1)
		{
			cin >> u;
			
			if (!u) break;
			
			getchar();
			getline(cin, s);
			ss << s;
			--u;
			while (ss >> w)
			{
				--w;
				v[u].push_back(w);
				v[w].push_back(u);
			}
			ss.clear();
		}
		dfsNumber = dfsRoot = rootChildren = articulation = 0;
		dfs(0);
		
		av[0] = (rootChildren > 1);
		
		for (int i = 0 ; i < n ; ++i)
			articulation += (av[i] == 1);
		cout << articulation << '\n';
		
		dfs_num.clear();
		dfs_low.clear();
		dfs_parent.clear();
		v.clear();
		av.clear();
	}

}
