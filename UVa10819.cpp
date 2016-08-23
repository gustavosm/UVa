#include <bits/stdc++.h>


using namespace std;


int dp[105][10205];
int p[105], f[105];

int m, n;

int calc(int i, int j)
{
	if (j > m && m < 1800) return -10000;
	if (j > m + 200) return -10000;
	if (i == n)
	{
		if (j > m && j <= 2000) return -1000;
		return 0;
	}
	
	int &ans = dp[i][j];
	
	if (ans == -1)
		ans = max(calc(i + 1, j), f[i] + calc(i + 1, j + p[i]));
	
	return ans;
}

int main()
{
	while (cin >> m >> n)
	{
		for (int i = 0 ; i < n ; ++i) cin >> p[i] >> f[i];
		memset(dp, -1, sizeof dp);
		
		cout << calc(0,0) << '\n';
		
	}
}
