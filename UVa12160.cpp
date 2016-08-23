#include <bits/stdc++.h>

#define INF INT_MAX
using namespace std;

vector<int> adds;
int nadds;
int s, t;
vector<int> d;

void bfs(int u)
{
	d.assign(10000, INF);
	d[u] = 0;
	queue<int> q;
	q.push(u);
	
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		
		for (int i = 0 ; i < nadds; ++i)
		{
			if (d[(x + adds[i]) % 10000] > d[x] + 1)
			{
				d[(x + adds[i]) % 10000] = d[x] + 1;
				q.push((x + adds[i]) % 10000);
			}
		}
	}
}

int main()
{
	int c = 1;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	while (1)
	{
		cin >> s >> t >> nadds;
		
		if (!s && !t && !nadds) return 0;
		adds.clear();
		for (int i = 0 ; i < nadds; ++i)
		{
			int x;
			cin >> x;
			adds.push_back(x);
		}
		d.clear();
		bfs(s);
		cout << "Case " << c++ << ": ";
		if (d[t] == INF) cout << "Permanently Locked\n";
		else cout << d[t] << '\n';
	}
}

