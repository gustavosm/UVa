#include <bits/stdc++.h>


using namespace std;

int main()
{
	int cases;
	int n, m;
	
	char x;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> x >> n >> m;
		
		if (x == 'r' || x == 'Q')
			cout << min(n, m) << '\n';
		else
		{
			if (x == 'k')
				cout << (n * m) / 2 + (n * m) % 2 << '\n';
			else if (x == 'K')
				cout << (n / 2 + n % 2) * (m / 2 + m % 2) << '\n';
		}
	}
}
