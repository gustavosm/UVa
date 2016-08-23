#include <bits/stdc++.h>


using namespace std;


int OK;

int ans;
int g[16][16];

void bckt(int col, int rw, int ld, int rd)
{
	if (rw == OK)
	{
		++ans;
		return;
	}
		
	int pos = OK & (~(rw | ld | rd));
	
	while (pos)
	{
		int p = pos & (-pos);
		
		pos -= p;
		int row = ffs(p);
		if (g[row][col])
			bckt(col + 1, rw | p, (ld | p) << 1, (rd | p) >> 1);
	}
}

int main()
{
	int caso = 1;
	
	int n;
	char c;
	
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		OK = (1 << n) - 1;
		ans = 0;
		
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < n ; ++j)
			{
				cin >> c;
				
				g[i][j] = (c == '.' ? 1 : 0);
			}
		}
		
		bckt(0, 0, 0, 0);
		
		cout << "Case " << caso++ << ": " << ans << '\n';
	}
}
