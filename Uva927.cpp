#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll v[25];
int i, k, d;

ll value(ll index)
{
	ll ans = v[0];
	
	ll pot = index;
	
	for (int j = 1; j <= i; ++j)
	{
		ans += v[j] * pot;
		pot *= index;
	}	
	return ans;
}

ll monta()
{
	ll ans = 0;
	ll pos = 1;
	ll sum = 0;
	
	while (sum < k)
	{
		ans = value(pos);
		sum += pos * d;
		++pos;
	}
	return ans;
}
int main()
{
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> i;
		for (int j = 0; j <= i; ++j) cin >> v[j];
		cin >> d >> k;
		
		cout << monta() << '\n';     
	}
}
