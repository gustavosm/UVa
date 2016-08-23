#include <bits/stdc++.h>


using namespace std;


vector<vector<int> > v;
vector<vector<int> > v2;

vector<int> s;
vector<int> vis;

int op;

void dfs(int n)
{
	vis[n] = 1;
	
	for (int i = 0 ; i < v[n].size() ; ++i)
	{
		if (!vis[v[n][i]])
			dfs(v[n][i]);
	}
	s.push_back(n);
}
void dfs2(int n)
{
	vis[n] = 1;
	
	for (int i = 0 ; i < v2[n].size() ; ++i)
	{
		if (!vis[v2[n][i]])
			dfs2(v2[n][i]);
	}
}

int main()
{
	int x, y, z;
	
	int n, m;
	
	while (1)
	{
		cin >> n >> m;
		
		if (!n) return 0;
		
		v.assign(n, vector<int> ());
		v2.assign(n, vector<int> ());
		vis.assign(n, 0);
		
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> x >> y >> z;
			--x; --y;
			v[x].push_back(y);
			v2[y].push_back(x);
			
			if (z == 2)
			{
				v[y].push_back(x);
				v2[x].push_back(y);
			}
		}
		for (int i = 0 ; i < n ; ++i)
			if (!vis[i])
				dfs(i);
		int cc = 0;
		for (int i = 0 ; i < n; ++i) vis[i] = 0;
		
		for (int i = s.size() - 1; i >= 0 ; --i)
		{
			if (!vis[s[i]])
			{
				dfs2(s[i]);
				++cc;
			}
			if (cc > 1) break;
		}
		cout << (cc == 1? 1 : 0) << '\n';
		
		vis.clear();
		v.clear();
		v2.clear();
		s.clear();
	}
}
