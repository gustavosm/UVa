#include <bits/stdc++.h>


using namespace std;


int dp[1005][1005];

char s[1005];

int calc(int i, int j)
{
	if (i == j)
		return 1;
		
	if (i > j) return 0;
		
	int &ans = dp[i][j];
	
	if (ans == -1)
	{
		if (s[i] == s[j])
			ans = 2 + calc(i + 1, j - 1);
		else ans = max(calc(i + 1, j), calc(i, j - 1));
	}
	return ans;
}

int main()
{
	int cases;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	 	
	cin >> cases;
	cin.getline(s, 1005);
	while (cases--)
	{
		cin.getline(s, 1005);
		
		memset(dp, -1, sizeof dp);
		cout << calc(0, strlen(s) - 1) << '\n';
	}
}
