#include <bits/stdc++.h>

#define INF 9999999

using namespace std;

typedef pair<int, pair<int, int> >  iii;

int s, t, mx;
int n;
vector<vector<pair<int, int> > > v;

void bfs()
{
	d.assing(n, INF);
	
	d[s] = 0;
	
	priority_queue<iii, vector<iii>, greater<iii> > q;
	
	q.push(make_pair(0, make_pair(0, s)));
	
	while (!q.empty())
	{
		iii u = q.top();
		q.pop();
		
		int w = u.second.second;
		
		if (w == t)
		{
			if (u.first <= p)
				mx = max(mx, u.second.first);
			continue;
		}
		
		for (int i = 0 ; i < v[w].size(); ++i)
		{
			if (d[v[w][i].second] > d[w] + v[w][i].first)
			{
				d[v[w][i].second] = d[w] + v[w][i].first;
				q.push(make_pair(d[v[w][i].second], make_pair(max(u.second.first, v[w][i].first), v[w][i].second)));
			}
		}
	}
}

int main()
{
	
}
