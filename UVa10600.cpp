#include <bits/stdc++.h>


using namespace std;

vector<int> pset;
void init(int n)
{
	pset.assign(n, 0);
	for (int i = 0 ; i < n ; ++i) pset[i] = i;
}

int find(int i)
{
	return (pset[i] == i? i : pset[i] = find(pset[i]));
}

int same(int i, int j)
{
	return find(i) == find(j);
}

void unionset(int i, int j)
{
	pset[find(i)] = find(j);
}

int main()
{
	
	vector<pair<int, pair<int, int> > > adj;
	
	int n, m;
	int u, v, w;
	int cases;	
	int ans1, ans2;
	int aux;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	set<pair<int, int> > s1;
	cin >> cases;
	
	while (cases--)
	{
		cin >> n >> m;
		
			
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> u >> v >> w;
			--u; --v;
			adj.push_back(make_pair(w, make_pair(u, v)));
		}
		sort(adj.begin(), adj.end());
		ans2 = INT_MAX;
		init(n);
		aux = 0;
		for (int j = 0 ; j < m; ++j)
		{				
			pair<int, pair<int, int> > f = adj[j];
			
			if (!same(f.second.first, f.second.second))
			{
				s1.insert(f.second);
				aux += f.first;
				unionset(f.second.first, f.second.second);
			}
		}
		ans1 = aux;
		
		for (set<pair<int, int> > :: iterator it = s1.begin(); it != s1.end(); ++it)
		{
			aux = 0;
			int arestas = 0;
			
			init(n);
			for (int j = 0 ; j < m; ++j)
			{				
				pair<int, pair<int, int> > f = adj[j];
				if (f.second == (*it)) continue;
				
				if (!same(f.second.first, f.second.second))
				{
					aux += f.first;
					++arestas;
					unionset(f.second.first, f.second.second);
				}
			}
			if (arestas == n - 1)
				if (ans2 > aux) ans2 = aux;

			pset.clear();
		}
		
		if (ans2 == INT_MAX) cout << ans1 << ' ' << ans1 << '\n';
		else cout << ans1 << ' ' << ans2 << '\n';
		s1.clear();
		adj.clear();
	}
}
