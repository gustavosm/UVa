#include <bits/stdc++.h>

#define MAX_V 38
#define INF INT_MAX

using namespace std;

int res[MAX_V][MAX_V], mf, f, st = 0, t = 37;
vector<int> p;

void augment(int v, int minEdge)
{
	if(v == 0) 
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
	string s;
	char cx, cx2;
	string s1;
	int w;
	int verify;
	stringstream ss;
	
	while (getline(cin, s))
	{
		memset(res, 0, sizeof res);
		verify = 0;
		do
		{
			if (s == "")
				break;
			
			ss << s;
			
			ss >> cx;
			ss >> cx2;
			
			ss >> s1;
			
			int u = cx - 'A' + 1;
			w = cx2 - '0';
			res[0][u] = w;
			verify += w;
			for (int i = 0 ; i < s1.size(); ++i)
			{
				if (s1[i] == ';') break;
				
				res[u][s1[i] - '0' + 27] = INF;
			}
			ss.clear();
			
		}while (getline(cin, s));
		for (int i = 27; i <= 36; ++i) res[i][37] = 1;
		
		mf = 0;
		while (1)
		{
			f = 0;

			vector<int> dist(MAX_V, INF);
			dist[0] = 0; queue<int> q; q.push(0);
			p.assign(MAX_V, -1);

			while (!q.empty())
			{
				int u = q.front(); q.pop();

				if (u == t) break;
				for (int v = 0; v < MAX_V; ++v)
				{
					if (res[u][v] > 0 && dist[v] == INF)
					{
						dist[v] = dist[u] + 1; q.push(v); p[v] = u;
					}
				}
			}
			augment(t, INF);
			p.clear();
			dist.clear();
			if (!f) break;
			mf += f;
		}
		if (mf != verify) cout << "!\n";
		else
		{
			for (int i = 27; i <= 36; ++i)
			{
				int flag = 0;
				for (int j = 1; j <= 26; ++j)
				{
					if (res[i][j] == 1)
					{
						cout << (char)(j - 1 + 'A');
						flag = 1;
						break;
					}
				}
				if (!flag) cout << "_";
			}
			cout << '\n';
		}
	}
}
