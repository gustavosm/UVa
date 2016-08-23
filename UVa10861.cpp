#include <bits/stdc++.h>


using namespace std;

typedef long long l;

l dp[105][105];
l v[105];
int n;

l values(int i, int j)
{
	return (i ? v[j] - v[i - 1] : v[j]);
}

l calc(int i, int j)
{
	if (i > j) return 0;
	if (i == j) return values(i, j);
	
	l &ans = dp[i][j];
	
	if (ans == -1)
	{
		ans = 0;
		for (int k = 0 ; k <= j - i; ++k)
		{
			l r = max(values(i, i + k) - calc(i + k + 1, j), values(j - k, j) - calc(i, j - k - 1));
			ans = max(ans, r);
		}
	}
	return ans;
}

int main()
{
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		
		for (int i =0  ; i < n ; ++i)
		{
			cin >> v[i];
			if (i) v[i] += v[i - 1];
		}
		memset(dp, -1, sizeof dp);
		
		cout << calc(0, n - 1) << '\n';
	}	
}
