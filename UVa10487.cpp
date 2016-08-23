#include <bits/stdc++.h>


using namespace std;


int main()
{
	int x;
	int n, m;
	int v[1006];
	int caso = 1;
	int closest;
	int mn;
	
	while (cin >> n)
	{
		if (!n) return 0;
		
		
		for (int i = 0 ; i < n ; ++i) cin >> v[i];
		
		cin >> m;
		
		cout << "Case " << caso++ << ":\n";
		while(m--)
		{
			cin >> x;
			mn = INT_MAX;
			closest = 0;
			for (int i = 0 ; i < n ; ++i)
			{
				for (int j = i + 1; j < n ; ++j)
				{
					if (abs(v[i] + v[j] - x) < mn) mn = abs(v[i] + v[j] - x), closest = v[i] + v[j];
				}
			}
			
			cout << "Closest sum to " << x << " is " << closest << ".\n";
		}
	}
}
