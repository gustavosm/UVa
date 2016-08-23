#include <bits/stdc++.h>

using namespace std;
int main ()
{
	vector<vector<int> > w;
	vector<int> maximo;
	int cases;
	int k;
	int p;
	int n;
	pair<int,int> u;
	pair<int,int> winner;
	pair<int,int> v;
	queue< pair<int,int> > q;
	cin >> cases;
	while(cases--)
	{
		cin >> n >> k;
		
		for (int i = 0; i < (int)(pow(2,n)); i++)
		{
			w.push_back(vector<int> ());
			cin >> p;
			maximo.push_back(p);
			q.push(make_pair(i,p));
		}
		
		while(!q.empty())
		{
			u = q.front();
			q.pop();
			v = q.front();
			q.pop();
			
			if (u.second > v.second)
			{
				winner = u;
				u.second = min(u.second - v.second + k, maximo[u.first]);
				w[u.first].push_back(v.first);
				if (!q.empty()) q.push(u);
			}
			else if (u.second < v.second)
			{
				winner = v;
				v.second = min(v.second - u.second + k, maximo[v.first]);
				w[v.first].push_back(u.first);
				if (!q.empty()) q.push(v);
			}
			else
			{
				if (u.first < v.first)
				{
					winner = u;
					u.second = min(k, maximo[u.first]);
					w[u.first].push_back(v.first);
					if (!q.empty()) q.push(u);
				}
				else				
				{
					winner = v;
					v.second = min(k, maximo[v.first]);
					w[v.first].push_back(u.first);
					if (!q.empty()) q.push(v);
				}
			}
		}
		cout << winner.first + 1 << '\n';
		int pos = winner.first;
		for (int i = 0 ; i < w[pos].size(); i++)
		{
			cout << w[pos][i] + 1;
			if (i < w[pos].size() - 1) cout << " ";
		}
		cout << '\n';
		w.clear();
		maximo.clear();
	}
}
