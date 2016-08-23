#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n;
	int mx;
	char x;
	
	vector<pair<int, int > > v1, v2;
	
	while (cin >> n)
	{
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < n ; ++j)
			{
				cin >> x;
				if (x == '1') v1.push_back(make_pair(i, j));
				if (x == '3') v2.push_back(make_pair(i, j));
			}
		}
		mx = INT_MIN;
		for (int i = 0 ; i < v1.size(); ++i)
		{
			int mn = INT_MAX;
			for (int j = 0 ; j < v2.size(); ++j)
			{
				mn = min(mn, abs(v1[i].first - v2[j].first) + abs(v1[i].second - v2[j].second));
			}
			mx = max(mx, mn);
		}
		cout << mx << '\n';
		v1.clear();
		v2.clear();
	}
}
