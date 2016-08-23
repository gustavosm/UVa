#include <bits/stdc++.h>


#define INF 999999

using namespace std;

typedef long long ll;

ll g[1000][1000];
int n, m;
vector<int> d;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int val(int i, int j)
{
	return 0 <= i && i < n  && 0 <= j && j < m;
}
void dijkstra(int i, int j)
{
	d.assign(n * m + m, INF);
	
	d[i * m + j] = g[i][j];
	
	priority_queue<pair<int , pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int > > > > pq;
	
	pq.push(make_pair(g[i][j], make_pair(i, j)));
	
	while (!pq.empty())
	{
		pair<int , pair<int, int> > u = pq.top(); pq.pop();
		
		if (u.first > d[u.second.first * m + u.second.second]) continue;
		
		for (int i = 0 ; i < 4; ++i)
		{
			if (val(u.second.first + dr[i], u.second.second + dc[i]))
			{
				if (d[(u.second.first + dr[i]) * m + u.second.second + dc[i]] >
									d[u.second.first * m + u.second.second] + g[(u.second.first + dr[i])][u.second.second + dc[i]])
				{
					d[(u.second.first + dr[i]) * m + u.second.second + dc[i]] =
									d[u.second.first * m + u.second.second] + g[(u.second.first + dr[i])][u.second.second + dc[i]];
					pq.push(make_pair(d[(u.second.first + dr[i]) * m + u.second.second + dc[i]], make_pair((u.second.first + dr[i]), u.second.second + dc[i])));
									
				}
			}
		}
	}
}
int main()
{
	int cases;
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n >> m;
		
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < m ; ++j)
			{
				cin >> g[i][j];
			}
		}
		dijkstra(0, 0);
	/*	for (int i = 0 ; i < d.size(); ++i)
			cout << d[i] << " haha ";
		cout << '\n';*/
		cout << d[(n - 1) * m + m - 1] << '\n';
		
		d.clear();
	}
}
