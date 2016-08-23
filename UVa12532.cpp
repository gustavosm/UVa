#include <bits/stdc++.h>

#define VN 100005
#define STN 400005

using namespace std;

int v[VN];
int st[STN];


int value(int x)
{
	return (x == 0? 0 : (x > 0 ? 1 : -1));
}
void init(int idx, int i, int j)
{
	if (i == j)
		st[idx] = value(v[i - 1]);
	else
	{
		init(idx * 2, i, (i + j) / 2);
		init(idx * 2 + 1, (i + j) / 2 + 1, j);
	
		st[idx] = st[idx * 2] * st[idx * 2 + 1];
	}
}
void update(int idx, int a, int b, int i, int val)
{
	if (i < a || i > b) return;
	
	if (a == b && b == i)
		st[idx] = value(val);
	else
	{
		update(idx * 2, a, (a + b) / 2, i, val);
		update(idx * 2 + 1, (a + b) / 2 + 1, b, i, val);	
	
		st[idx] = st[idx * 2] * st[idx * 2 + 1];
	}
}

int query(int idx, int a, int b, int i, int j)
{
	if (i > b || j < a) return 1;
	
	else if (j >= b && i <= a) return st[idx];
	
	int x1 = query(idx * 2, a, (a + b) / 2, i, j);
	int x2 = query(idx * 2 + 1, 1 + (a + b) / 2, b, i, j);
	
	return x1 * x2;
}

int main()
{
	int n;
	int m;
	char c;
	int x, y;
	while (cin >> n >> m)
	{
		for (int i = 0 ; i < n ; ++i) cin >> v[i];
		
		init(1, 1, n);
		
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> c >> x >> y;
			
			if (c == 'C')
			{
				update(1, 1, n, x, y);
			}
			else
			{
				int ans = query(1, 1, n, x, y);
				
				cout << (ans == 0 ? '0' : (ans < 0 ? '-' : '+'));
			}
		}
		cout << '\n';
	}
}

