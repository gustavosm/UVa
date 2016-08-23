#include <bits/stdc++.h>


#define INF 999999

using namespace std;

typedef pair<int, pair<int, int> >  iic;

vector<vector<iic > > v;

map<string, int> mp;
int d[5005][28];

int vx;

void dijkstra(int s)
{
	for (int i = 0; i < vx; ++i) for (int j = 0; j <= 27; ++j) d[i][j] = INF;
	
	for (int i = 0 ; i <= 27; ++i) d[s][i] = 0;
	
	priority_queue<iic, vector<iic>, greater<iic> > q;
	
	q.push(iic(0, make_pair(s, 0)));
	
	while (!q.empty())
	{
		iic u = q.top(); q.pop();
		
		int w = u.second.first;
		int c1 = u.second.second;
		
		for (int i = 0 ; i < v[w].size(); ++i)
		{
			int j = v[w][i].second.first;
			int c = v[w][i].second.second;
			if (d[j][c] > d[w][c1] + v[w][i].first && c1 != c)
			{
				d[j][c] = d[w][c1] + v[w][i].first;
				q.push(iic(d[j][c], make_pair(j, c)));
			}
		}
	}
}

int main()
{
	string s;
	string t;
	string w;
	int tt, st;
	int m;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	while (1)
	{
		cin >> m;
		vx = 0;
		if (!m) return 0;
		
		
		cin >> s >> t;
		int zero = (s == t);
		mp[s] = vx++;
		mp[t] = vx++;
		
		v.push_back(vector< iic > ());
		v.push_back(vector< iic > ());
		
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> s >> t >> w;
			if (!zero)
			{
				if (!mp.count(s))
				{
					st = vx;
					mp[s] = vx++;
					v.push_back(vector<iic > ());
				}
				else st = mp[s];
				if (!mp.count(t))
				{
					tt = vx;
					mp[t] = vx++;
					v.push_back(vector< iic > ());
				}
				else tt = mp[t];
			
				v[st].push_back(make_pair(w.size(), make_pair(tt, w[0] - 'a' + 1)));
				v[tt].push_back(make_pair(w.size(), make_pair(st, w[0] - 'a' + 1)));
			}
		}
		if (zero) cout << "0\n";
		else
		{
			dijkstra(0);
		
			int mn = INF;
			
			for (int i = 0; i < 27; ++i)
				mn = min(mn, d[1][i]);
			
			if (mn == INF) cout << "impossivel\n";
			else cout << mn << '\n';
		
			v.clear();
			mp.clear();
		}
	}
}
