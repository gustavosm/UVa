#include <bits/stdc++.h>


#define EPS 0.000000001
using namespace std;

typedef long long ll;

int main()
{
	cout.precision(2);
	ios_base :: sync_with_stdio(0);
	for (ll a = 1; 4 * a <= 2000; ++a)
	{
		for (ll b = a; a + 3 * b <= 2000; ++b)
		{
			for (ll c = b; a + b + 2 * c <= 2000; ++c)
			{
				ll p = (a * b * c);
				ll s = a + b + c;
				
				if (p > 1000000)
				{
					ll d = (1000000 * s) / (p - 1000000);
					
					
					if (d < c || s + d > 2000) continue;
					
					if (fabs((double)(p * d) / 100000000.0 - (double)(s + d) / 100.) < EPS)
						cout << fixed << (double)a / 100. << ' ' << (double)b / 100. << ' ' << (double)c / 100. << ' ' << (double)d / 100. << '\n';
				}
			}
		}
	}
}
