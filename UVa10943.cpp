#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

ll dp[105][105];
int N, K;

ll calc(int n, int k)
{
	if (k == 1) return 1;
	
	ll &ans = dp[n][k];
	
	if (ans == -1)
	{
		ans = 0;
		for (int i = 0 ; i <= n; ++i)
		{
			ans = (ans + calc(n - i, k - 1)) % 1000000;
		}
	}
	return ans;
}

int main()
{
	memset(dp, -1, sizeof dp);
	while (1)
	{
		cin >> N >> K;
		
		if (!N && !K) return 0;
		
		cout << calc(N, K) << '\n';
	}
}
