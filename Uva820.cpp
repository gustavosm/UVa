#include <bits/stdc++.h>

#define MAX_V 105
#define INF INT_MAX

using namespace std;

int res[MAX_V][MAX_V], mf, f, s, t;
vector<int> p;

void augment(int v, int minEdge)
{
	if(v == s) 
	{
		f = minEdge;
		return;
    } 
    else if(p[v] != -1) 
    {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}
int main()
{
	int n;
	int m;
	int u, v, w;
	int net = 1;
	while (1)
	{
		cin >> n;
		
		if (!n) return 0;
		memset(res, 0, sizeof res);
		cin >> s >> t >> m;
		--s; --t;
		
		while (m--)
		{
			cin >> u >> v >> w;
			
			--u; --v;
			
			res[u][v] += w;
			res[v][u] += w;
		}
		mf = 0;
		while (1)
		{
			f = 0;

			vector<int> dist(n, INF);
			dist[s] = 0; 
			queue<int> q;
			q.push(s);
			p.assign(n, -1);

			while (!q.empty())
			{
				int u = q.front(); q.pop();

				if (u == t) break;
				for (int v = 0; v < n; ++v)
				{
					if (res[u][v] > 0 && dist[v] == INF)
					{
						dist[v] = dist[u] + 1;
						q.push(v);
						p[v] = u;
					}
				}
			}
			augment(t, INF);
			p.clear();
			dist.clear();
			if (!f) break;
			mf += f;
		}
		
        printf("Network %d\nThe bandwidth is %d.\n\n", net, mf);
        ++net;
	}
}
