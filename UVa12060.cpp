#include <bits/stdc++.h>


using namespace std;

int mdc(int a, int b)
{
	return (b? mdc(b, a % b) : a);
}

int tam(int c)
{
	int ans = 0;
	if (!c) return 1;
	
	while (c)
	{
		++ans;
		c /= 10;
	}
	return ans;
}
int main()
{
	int n;
	
	int avg;
	int x;
	int caso = 1;
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		
		avg = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x;
			avg += x;
		}
		cout << "Case " << caso++ << ":\n";
		if (!avg) cout << "0\n";
		else
		{
			if (abs(avg) % n)
			{
				int a = abs(avg) / n;
				
				int b = abs(avg) % n;
				
				int c = n;
				
				int gcd = mdc(b, c);
				
				b /= gcd;
				c /= gcd;
				
				int tc = tam(c);
				int ta;
				if (a != 0) ta = tam(a) + (avg < 0? 2 : 0);
				else ta = (avg < 0 ? 2 : 0);
				
				int spaces = ta + tc - tam(b);
				
				for (int i = 0 ; i < spaces; ++i) cout << ' ';
				cout << b << '\n';
				
				if (avg < 0)
					cout << "- ";
				if (a) cout << a;
				
				for (int i = 0 ; i < tc; ++i) cout << '-';
				
				cout << '\n';
				
				for (int i = 0 ; i < ta; ++i) cout << ' ';
				
				cout << c << '\n';
			}
			else
			{
				if (avg < 0) cout << "- ";
				cout << abs(avg) / n << '\n';
			}
		}
	}
}
