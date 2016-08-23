#include <bits/stdc++.h>


using namespace std;


int main()
{
	int k;
	int n, m;
	int x, y;
	
	
	while (1)
	{
		cin >> k;
		
		if (!k) return 0;
		
		
		cin >> n >> m;
		
		for (int i = 0 ; i < k; ++i)
		{
			cin >> x >> y;
			x -= n;
			y -= m;
			
			if (x == 0 || y == 0) cout << "divisa\n";
			else if (x > 0 && y > 0) cout << "NE\n";
			else if (x > 0 && y < 0) cout << "SE\n";
			else if (x < 0 && y > 0) cout << "NO\n";
			else cout << "SO\n";
		}
		
	}
	return 0;
}
