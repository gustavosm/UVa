#include <bits/stdc++.h>



using namespace std;


vector<vector<int> > v;

vector<int> visited;
int ans;

void dfs(int u)
{
	
	if (v[u].size() == 0) ++ans;
	
	for (int i = 0 ; i < v[u].size(); ++i)
		dfs(v[u][i]);
}

int main()
{
	int n;
	
	int k;
	int x;
	int pl = 0;
	
	while (scanf("%d", &n) != EOF)
	{
		v.assign(n, vector<int>());
		if (pl) printf("\n");
		pl = 1;
		for (int i = 0 ; i < n ; ++i)
		{
			scanf("%d", &k);
			for (int j = 0 ; j < k; ++j)
			{
				scanf("%d", &x);
				v[i].push_back(x);
			}
		}
		
		visited.assign(n, 0);
		ans = 0;
		dfs(0);
		printf("%d\n", ans);
		
		visited.clear();
		v.clear();
	}
}
