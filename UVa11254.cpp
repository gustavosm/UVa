#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

int main()
{
	ll n, r, a;
	
	
	while (cin >> n)
	{
		if (n == -1) return 0;
		
		
		r = (ll)sqrt(2 * n) + 1;
		
		while (r)
		{
			a = (2 * n + r - r * r) / (2 * r);
			
			if ((((2 * a + r - 1) * r) / 2) == n) break;
			--r;
		}
		cout << n << " = " << (a? a : 1) << " + ... + " << a + r - 1 << '\n';
	}	
}
