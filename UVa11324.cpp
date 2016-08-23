#include <bits/stdc++.h>

#define SZ(X) (X).size()
#define PB push_back
using namespace std;


const int MAXN = 1001;

vector< int > G[MAXN], R[MAXN], D[MAXN];
int stck[MAXN], top;
int w[MAXN], comp[MAXN], nc;
char flag[MAXN];

void dfs1(int u) 
{
	int i, v;
	for(i = 0; i < SZ(G[u]); i++) 
	{
		v = G[u][i];
		if(!flag[v]) 
		{
			flag[v] = 1;
			dfs1(v);
		}
	}
	stck[top++] = u;
}

void dfs2(int u) 
{
	int i, v;
	comp[u] = nc;
	w[nc]++;
	for(i = 0; i < SZ(R[u]); i++) 
	{
		v = R[u][i];
		if(!flag[v]) 
		{
			flag[v] = 1;
			dfs2(v);
		}
	}
}

int solve(int u) 
{
	if(flag[u]) return w[u];
	flag[u] = 1;
	int ret = 0, i;
	for(i = 0; i < SZ(D[u]); i++)
		ret = max(ret, solve(D[u][i]));
	w[u] += ret;
	return w[u];
}

int main() 
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int test, n, e, i, u, v, ans;
	cin >> test;
	while(test--) 
	{
		cin >> n >> e;
		if(!n) { cout << 0 << '\n'; continue; }
		for(i = 1; i <= n; i++) 
		{
			G[i].clear();
			R[i].clear();
		}
		for(i = 0; i < e; i++) 
		{		
			cin >> u >> v;
			G[u].PB(v);
			R[v].PB(u);
		}
		memset(flag, 0, sizeof flag);
		top = 0;
		for(i = 1; i <= n; i++) 
		{
			if(!flag[i])
			{
				flag[i] = 1;
				dfs1(i);
			}
		}
		memset(flag, 0, sizeof flag);
		memset(w, 0, sizeof w);
		nc = 0;
		while(top--) 
		{
			u = stck[top];
			if(!flag[u]) 
			{
				nc++;
				flag[u] = 1;
				dfs2(u);
			}
		}
		for(i = 1; i <= nc; i++) D[i].clear();
		for(u = 1; u <= n; u++) 
		{
			for(i = 0; i < SZ(G[u]); i++) 
			{
				v = G[u][i];
				if(comp[u] != comp[v]) D[comp[u]].PB(comp[v]);
			}
		}
		memset(flag, 0, sizeof flag);
		ans = 0;
		for(i = 1; i <= nc; i++) 
			if(!flag[i])
				ans = max(ans, solve(i));
		cout << ans << '\n';
	}
	return 0;
}
