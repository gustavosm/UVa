#include <bits/stdc++.h>


using namespace std;


int dp[105][105];

string s, t;
int ns, nt;

int lcs(int i, int j)
{
	if (i == ns) return 0;
	if (j == nt) return 0;
	
	int &ans = dp[i][j];
	
	if (ans == -1)
	{
		if (s[i] == t[j])
			ans = 1 + lcs(i + 1, j + 1);
		else
			ans = max(lcs(i + 1, j), lcs(i, j + 1));
	}
	
	return ans;
}

int main()
{
	int caso = 1;
	while (getline(cin, s))
	{
		if (s[0] == '#') return 0;
		
		getline(cin, t);
		ns = s.size();
		nt = t.size();
		memset(dp, -1, sizeof dp);
		int k = lcs(0, 0);
		
		cout << "Case #" << caso++ << ": you can visit at most " << k << " cities.\n";
	}
	
}
