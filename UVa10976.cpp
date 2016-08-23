#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

vector<pair<ll, ll> > v[10005];

int main()
{
	ll x, y;
	
	ll k;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (cin >> k)
	{
		if (v[k].size() == 0)
		{
			for (x = (k + 1); x <= 2 * k; ++x)
			{
				if ((k * x) % (x - k) == 0)
				{
					ll y = (k * x) / (x - k);
					if (x <= y)
						v[k].push_back(make_pair(y, x));
					else break;
				}
			}
		}
		
		cout << (int)(v[k].size()) << '\n';
		for (int i = 0 ; i < (int)v[k].size(); ++i)
			cout << "1/" << k << " = 1/" << v[k][i].first << " + 1/" << v[k][i].second << '\n';
	}
}
