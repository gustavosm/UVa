#include <bits/stdc++.h>



using namespace std;

typedef long long ll;


ll dp[15][1005];

ll m[15][1005];
int n;

int main()
{
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n;
		
		n /= 100;
		
		for (int i = 9 ; i >= 0; --i)
		{
			for (int j = 0 ; j < n ; ++j)
				cin >> m[i][j];
		}
		
		memset(dp, -1, sizeof dp);  
		
		for(int y = 0; y < 10; ++y)
			dp[y][0] = 0x3f3f3f3f;
	
		for(int x = 0; x < n; ++x)
			dp[0][x] = 0x3f3f3f3f;

		dp[0][0] = 0;

		for(int x = 1; x < n; ++x) 
		{
			for(int y = 1; y < 10; ++y) 
			{
				ll tmp = INT_MAX;
				
				tmp = min(dp[y][x - 1] + 30 - m[y][x - 1], tmp);
				
				tmp = min(dp[y - 1][x - 1] + 60 - m[y - 1][x - 1], tmp);
				
				if(y < 9) tmp = min(dp[y + 1][x - 1] + 20 - m[y + 1][x - 1], tmp);

				dp[y][x] = tmp;
			}
		}

		dp[0][n] = dp[1][n - 1] + 20 - m[1][n - 1];
		
		cout << dp[0][n] << "\n\n";
	}
}
