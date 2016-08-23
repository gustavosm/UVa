#include <bits/stdc++.h>


using namespace std;

vector<int> pset;

void init(int n)
{
	pset.assign(n, 0);
	
	for (int i = 0 ; i < n ; ++i)
		pset[i] = i;
}

int find(int i)
{
	return (pset[i] == i? i : pset[i] = find(pset[i]));
}

int same(int i, int j)
{
	return find(i) == find(j);
}

void unir(int i, int j)
{
	pset[find(i)] = find(j);
}

int main()
{
	vector<pair<int, pair<int, int> > > adj;
	int n, m;
	int u, v, w;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	while (1)
	{
		cin >> n >> m;
		
		if (!n) return 0;
		init(n);
		for (int i = 0 ; i < m ;++i)
		{
			cin >> u >> v >> w;
			
			adj.push_back(make_pair(w, make_pair(u, v)));
		}
		
		sort(adj.begin(), adj.end());
		int ans = 0;
		for (int i = 0 ; i < m ; ++i)
		{
			pair<int, pair<int, int> > f = adj[i];
			
			if (!same(f.second.first, f.second.second))	
				unir(f.second.first, f.second.second);
			else ans += f.first;
		}
		cout << ans << '\n';
		
		adj.clear();
		pset.clear();
	}
}
