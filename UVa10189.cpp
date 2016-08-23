#include <bits/stdc++.h>


using namespace std;

int n, m;

string v[105];

char count(int i , int j)
{
	int ans = 0;
	if (i > 0)
	{
		if (v[i - 1][j] == '*') ++ans;
		if (j < m - 1)
			if (v[i - 1][j + 1] == '*') ++ans;
		if (j > 0)
			if (v[i - 1][j - 1] == '*') ++ans;
	}
	if (i < n - 1)
	{
		if (v[i + 1][j] == '*') ++ans;
		if (j < m - 1)
			if (v[i + 1][j + 1] == '*') ++ans;
		if (j > 0)
			if (v[i + 1][j - 1] == '*') ++ans;
	}
	if (j > 0)
		if (v[i][j - 1] == '*') ++ans;
	if (j < m - 1)
		if (v[i][j + 1] == '*') ++ans;
		
	return (char)(ans + '0');
}

int main()
{
	int field = 1;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	int pl = 0;
	
	while (1)
	{
		cin >> n >> m;
		
		if (!n && !m) return 0;
		if (pl) cout << '\n';
		pl = 1;
		for (int i = 0 ; i < n ; ++i) cin >> v[i];
		
		for (int i = 0 ; i < n; ++i)
		{
			for (int j = 0 ; j < m ; ++j)
			{
				if (v[i][j] == '.')
					v[i][j] = count(i, j);
			}
		}
		cout << "Field #" << field++ << ":\n";
		for (int i = 0 ; i < n ; ++i) cout << v[i] << '\n';
	}
}
