#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n, m;
	stack<int> s;
	vector<int> v;
	int x;
	int pl = 0;
	
	while (1)
	{
		cin >> n;
		
		if (!n) return 0;
		while (1)
		{
			cin >> x;
			if (!x) break;
			
			v.push_back(x);
			for (int i = 1; i < n ; ++i)
			{
				cin >> x;
				
				v.push_back(x);
			}
			
			int aux = 0;
			for (int i = 1; i <= n ; ++i)			
			{
				s.push(i);
				while (!s.empty())
				{
					if (s.top() == v[aux])
					{
						s.pop();
						++aux;
					}
					else break;
				}
			}
			if (s.empty()) cout << "Yes\n";
			else cout << "No\n";
			
			v.clear();
			while (!s.empty()) s.pop();
		}
		cout << '\n';
	}
}
