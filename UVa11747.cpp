#include <bits/stdc++.h>


using namespace std;

typedef pair<long long, pair<int, int > > llii;
vector<int> pset;

void init(int n)
{
	pset.assign(n, 0);
	for (int i = 0 ; i < n ; ++i) pset[i] = i;
}

int find(int i)
{
	return (pset[i] == i ? i : pset[i] = find(pset[i]));
}

bool issame(int i , int j)
{
	return find(i) == find(j);
}

void unionset(int i, int j)
{
	pset[find(i)] = find(j);
}

int main()
{
	vector< llii > edges;
	vector<long long> ans;
	//int visited[1005];
	int n, m;
	int usados;
	int u, v;
	long long w;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (1)
	{
		cin >> n >> m;
		
		if (!n && !m) return 0;
	//	memset(visited, 0, sizeof visited);
		//usados = 0;
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> u >> v >> w;
			
			//if (!visited[u]) ++usados;
			//if (!visited[v]) ++usados;
		//	visited[u] = visited[v] = 1;
			edges.push_back(make_pair(w, make_pair(u, v)));
		}
		
	/*	if (usados < n) cout << "forest\n";
		else
		{*/
		init(n);
		sort(edges.begin(), edges.end());
		for (int i = 0; i < m ; ++i)
		{
			llii edge = edges[i];
			
			if (!issame(edge.second.first, edge.second.second))
				unionset(edge.second.first, edge.second.second);
			else ans.push_back(edge.first);
		}
		if (ans.size() > 0)
		{
			for (int i = 0 ; i < ans.size(); ++i)
			{
				if (i) cout << ' ';
				cout << ans[i];
			}
			cout << '\n';
		}
		else cout << "forest\n";
		pset.clear();
		ans.clear();
		//}
		edges.clear();
	}
}
