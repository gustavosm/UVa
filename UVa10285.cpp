#include <bits/stdc++.h>


#define mem memset(dp, -1, sizeof dp)
using namespace std;

int g[105][105];
int dp[105][105];
int r, c;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int val(int i, int j)
{
	return 0 <= i && i < r && 0 <= j && j < c;
}
int dfs(int i, int j)
{
	int &ans = dp[i][j];
	
	if (ans == -1)
	{
		ans = 0;
		for (int x = 0 ; x < 4; ++x)
		{
			if (val(i + dr[x], j + dc[x]))
			{
				if (g[i][j] > g[i + dr[x]][j + dc[x]])
					ans = max(ans, dfs(i + dr[x], j + dc[x]) + 1);
			}
		}
	}
	return ans;
}
int main()
{
	string s;
	
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> s >> r >> c;
		
		for (int i = 0 ; i < r; ++i)
		{
			for (int j = 0 ; j < c;  ++j)
				cin >> g[i][j];
		}
		mem;
		int ans = INT_MIN;
		for (int i = 0 ; i < r; ++i)
		{
			for (int j = 0 ; j < c; ++j)
			{
				ans = max(ans, dfs(i, j) + 1);
			}
		}
		
		cout << s << ": " << ans << '\n';
	}
}
