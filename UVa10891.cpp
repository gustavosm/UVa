#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

ll dp[105][105];
bool vis[105][105];

ll v[105];

ll getValue(int i, int j)
{
	return v[j] - (i - 1 >= 0? v[ i - 1 ] : 0 );
}
ll calc(int i, int j)
{
	if (i > j) return 0;
	
	if (vis[i][j]) return dp[i][j];
	
	vis[i][j] = true;
	ll &ans = dp[i][j];
	ans = -124141;
	for (int k = i; k <= j; ++k)
	{
		ll val = getValue(i, k);
		ans = max(ans, val - calc(k + 1, j));
    }
    for (int k = j; k >= i; --k)
	{
		ll val = getValue(k, j);
		ans = max(ans, val - calc(i, k - 1));
    }
	return ans;
}

int main()
{
	int n;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> v[i];
			if (i) v[i] += v[i - 1];
		}
		
		memset(vis, false, sizeof vis);
		
		cout << calc(0, n - 1) << '\n';
	}
}
