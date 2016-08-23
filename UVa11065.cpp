#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

ll adj[65];

int n;
int ns;
int ans;

void rec(int idx, ll used, int d)
{
	if (used == (1L << n) - 1)
	{
		++ns;
		ans = max(d, ans);
	}
	
	else
	{
		for (int i = idx ; i < n; ++i)
		{
			if (!(used & (1L << i)))
				rec(i + 1, used | adj[i], d + 1);
		}
	}
}

int main()
{
	int cases;
	int m;
	int u, v;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n >> m;
		
		for (int i = 0 ; i < n ; ++i)
			adj[i] = (1L << i);
		ns = ans = 0;
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> u >> v;
			
			adj[v] |= (1L << u);
			adj[u] |= (1L << v);
		}
		
		rec(0, 0, 0);
		
		cout << ns << '\n' << ans << '\n';
	}
}
