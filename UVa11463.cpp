#include <bits/stdc++.h>


#define INF 9999999
using namespace std;


typedef long long ll;


ll g[105][105];
int n;
void fw()
{
	for (int k = 0 ; k < n; ++k)
	{
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < n ; ++j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		}		
	}
}

int main()
{
	int cases;
	int m;
	int u, w, s, t;
	
	cin >> cases;
	
	for (int c = 1; c <= cases; ++c)
	{
		for (int i = 0 ; i < 105; ++i) {for (int j = 0 ; j < 105; ++j) g[i][j] = INF; g[i][i] = 0;}
		
		cin >> n >> m;
		
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> u >> w;
			
			g[u][w] = g[w][u] = 1;
		}
		
		fw();
		
		cin >> s >> t;
		ll ans = -1;
		for (int i = 0 ; i < n ; ++i)
		{	
			if (g[s][i] != INF && g[i][t] != INF)
				ans = max(ans, g[s][i] + g[i][t]);
		}
		
		cout << "Case " << c << ": " << ans << '\n';
	}
}
