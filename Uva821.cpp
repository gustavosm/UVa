#include <bits/stdc++.h>

#define INF 12312712
using namespace std;


int g[105][105];
int n;
void fw()
{
	for (int k = 0 ; k < n ; ++k)
		for (int i = 0 ; i < n ; ++i)
			for (int j = 0 ; j < n ; ++j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main()
{
	int u, v;
	int c = 1;
	int w[105];
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (1)
	{
		cin >> u >> v;
		
		if (!u && !v) return 0;
		memset(w, 0, sizeof w);
		--u; --v;
		for (int i = 0 ; i < 105; ++i) for (int j = 0; j < 105; ++j) g[i][j] = INF;
		g[u][v] = 1;
		n = max(u, v);
		w[u] = w[v] = 1;
		
		while (1)
		{
			cin >> u >> v;
			
			if (!u && !v) break;
			--u; --v;
			
			n = max(n, max(u, v));
			
			w[u] = w[v] = 1;
			
			g[u][v] = 1;
		}
		++n;
		
		fw();
		int ans = 0;
		int qtde = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < n ; ++j)
			{
				if (i == j) continue;
				if (g[i][j] != INF) ans += g[i][j], ++qtde;
			}
		}
		cout << "Case " << c++ << ": average length between pages = " << setprecision(3) << fixed << (double)ans / (double)qtde << " clicks\n";		
	}
}
