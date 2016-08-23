#include <bits/stdc++.h>


using namespace std;

int row[10];
int memo[1005][10];
int qtde;
int in[10];

int place(int r, int c)
{
	for (int p = 0 ; p < c; ++p)
	{
		if (row[p] == r || abs(row[p] - r) == abs(c - p))
			return 0;
	}
	return 1;
}

void bkt(int col)
{
	if (col >= 8)
	{
		for (int i = 0; i < 8; ++i)
			memo[qtde][i] = row[i];
		++qtde;
		return;
	}
	
	for (int r = 0; r < 8; ++r)
	{
		if (place(r, col))
		{
			row[col] = r;
			bkt(col + 1);
		}
	}
}

int calc()
{
	int ans = INT_MAX;
	for (int i = 0 ; i < qtde; ++i)
	{
		int steps = 0;
		for (int j = 0 ; j < 8 ; ++j)
		{	
			steps += (memo[i][j] != in[j] - 1);
		}
		ans = min(ans, steps);
	}
	return ans;
}

int main()
{
	qtde = 0;
	bkt(0);
	int caso = 1;
	while (cin >> in[0])
	{
		for (int i = 1; i < 8 ; ++i)
			cin >> in[i];
		cout << "Case " << caso << ": "; ++caso;
		cout << calc() << '\n';
	}
}

