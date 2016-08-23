#include <bits/stdc++.h>


using namespace std;


int main()
{
	int cases;
	int a, b, c;
	
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> a >> b >> c;
		
		bool sol = false;
		
		for (int i = -100; i <= 100 && !sol; ++i)
		{
			for (int j = -100; j <= 100 && !sol; ++j)
			{
				if (i == j) continue;
				for (int k = -100; k <= 100 && !sol; ++k)
				{
					if (k == i || k == j) continue;
					if (i + j + k == a && i * j * k == b && i * i + j * j + k * k == c)
					{
						cout << i << ' ' << j << ' ' << k << '\n';
						sol = true;
					}
				}
			}
		}
		if (!sol) cout << "No solution.\n";
	}
}
