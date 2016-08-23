#include <bits/stdc++.h>


using namespace std;


int main()
{
	vector<string> v;
	vector<pair<int, int> > v2;
	
	int cases;
	int x, y, price, pos;
	int n, m;
	
	string s;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n;
		
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> s >> x >> y;
			
			v.push_back(s);
			v2.push_back(make_pair(x, y));
		}
		
		cin >> m;
		int flag = 0;
		while (m--)
		{
			cin >> price;
			flag = 0;
			pos = -1;
			for (int i = 0 ; i < n ; ++i)
			{
				if (v2[i].first <= price && price <= v2[i].second)
				{
					pos = i;
					++flag;
				}
				if (flag >= 2) break;
			}
			
			if (flag != 1) cout << "UNDETERMINED\n";
			else cout << v[pos] << '\n';
			
			
		}
		if (cases)
		cout << '\n';
		v.clear();
		v2.clear();
	}
}
