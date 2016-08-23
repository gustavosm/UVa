#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

ll coins[1005];

int n;

ll calc(ll value, int coin)
{
	if (coin == n - 1) return 0;
	
	if (coins[coin] + value < coins[coin + 1])
		return 1 + calc(value + coins[coin], coin + 1);
	return calc(value, coin + 1);
}

int main()
{
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n;
		
		for (int i = 0 ; i < n  ; ++i)
			cin >> coins[i];
		
		if (n == 1) cout << 1 << '\n';
		else
		{
			ll ans = 2 + calc(coins[0], 1);
			cout << ans << '\n';
		}
	}
}
