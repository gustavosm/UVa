#include <bits/stdc++.h>


#define oo 1231237861
using namespace std;


map<string, int> m;
vector<vector<int> > v;
vector<int> d;
int n;

void dijkstra(int source)
{
	d.clear();
	
	d.assign(n, oo);
	
	d[source] = 0;
	priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;
	
	pq.push(make_pair(0, source));
	
	while (!pq.empty())
	{
		pair<int, int> u = pq.top(); pq.pop();
		
		if (u.first > d[u.second]) continue;
		
		for (int i = 0 ; i < (int)v[u.second].size(); ++i)
		{
			if (d[v[u.second][i]] > d[u.second] + 1)
			{
				d[v[u.second][i]] = d[u.second] + 1;
				pq.push(make_pair(d[v[u.second][i]], v[u.second][i]));
			}
		}
	}
}
int weigth(string s1, string s2)
{
	if (s1.size() != s2.size()) return oo;
	
	int w = 0;
	
	for (int i = 0 ; i < s1.size(); ++i)
		if (s1[i] != s2[i]) ++w;
	return w;
}
int main()
{
	string s;
	n = 0;
	int cases;
	
	cin >> cases;
	
	getchar();
	getchar();
	
	while (cases--)
	{
		while (1)
		{
			cin >> s;
			if (s[0] == '*') break;
			if (!m[s])
				m[s] = n++;
		}
		getchar();
		v.assign(n, vector<int>());
		
		for (map<string, int> :: iterator it = m.begin(); it != m.end(); ++it)
		{
			for (map<string, int> :: iterator it2 = m.begin(); it2 != m.end(); ++it2)
			{
				if (weigth(it->first, it2->first) != 1) continue;
				v[it->second].push_back(it2->second);
			}
		}
		
		while (1)
		{
			getline(cin, s);
			if (s.empty()) break;
			stringstream ss;
			ss << s;
			
			string s1, s2;
			ss >> s1 >> s2;
			dijkstra(m[s1]);
			
			cout << s1 << ' ' << s2 << ' ' << d[m[s2]] << '\n';
		}
		
		m.clear();
		v.clear();
		
		if (cases) cout << '\n';
	}
}
