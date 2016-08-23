#include <bits/stdc++.h>


using namespace std;

vector<int> visited;
vector<vector<int> > v;

void dfs(int n)
{
	visited[n] = 1;
	
	for (int i = 0 ; i < v[n].size(); ++i)
	{
		if (!visited[v[n][i]])
			dfs(v[n][i]);
	}
}
int main()
{
	int cases;
	int acerto, erro;
	int n, u , w;
	int ret;
	
	char c;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n;
		acerto = erro = 0;
		getchar();
		
		v.assign(n, vector<int> ());
		visited.assign(n, 0);
		
		while(1)
		{
			ret = scanf("%c", &c);
			if (c == '\n' || ret == EOF) break;
			
			scanf("%d %d", &u, &w);
			--u; --w;
			
			getchar();
			
			if (c == 'q')
			{
				if (u == w)
				{
					++acerto;
					continue;
				}
				for (int i = 0 ; i < n ; ++i) visited[i] = 0;
				dfs(u);
				
				if (visited[w]) ++acerto;
				else ++erro;
			}
			else
			{
				v[u].push_back(w);
				v[w].push_back(u);
			}
		}
		cout << acerto << ',' << erro << '\n';
		if (cases) cout << '\n';
		if (ret == EOF) break;
	}
}
