#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

ll arredonda(double d)
{
	ll x = (ll) d;
	
	if (x != d) ++x;
	
	return x;
}

int main()
{
	ll n;
	
	while (cin >> n)
	{
		if (!n) return 0;
		
		if (n == 1) cout << 1 << '\n';
		else if (!(n & (n - 1))) cout << n << '\n';
		else
		{
			ll pot = arredonda(log2(n));
			
			ll x = (1 << pot);
			
			cout << x - (x - n) * 2 << '\n';
		}
	}
}
