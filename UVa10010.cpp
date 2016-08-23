#include <bits/stdc++.h>


using namespace std;

string m1[55];
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;

int val(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < m;
}

int find(string &h, int i, int j, int direcaoi, int direcaoj, int pos)
{
	if (pos == h.size())
		return 1;
		
	if (!val(i, j)) return 0;
	
	if (tolower(h[pos]) != tolower(m1[i][j])) return 0;
	
	return find(h, i + direcaoi, j + direcaoj, direcaoi, direcaoj, pos + 1);
}

int main()
{
	int cases;
	int query;
	string k;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	cin >> cases;
	
	while (cases--)
	{
		cin >> n >> m;
		
		for (int i = 0 ; i < n ; ++i)
			cin >> m1[i];
			
		cin >> query;
		
		while (query--)
		{
			cin >> k;
			int flag = 0;
			for (int i = 0 ; i < n ; ++i)
			{
				for (int j = 0 ; j < m ; ++j)
				{
					for (int k1 = 0 ; k1 < 8; ++k1)
					{
						if (find(k, i, j, dr[k1], dc[k1], 0))
						{
							cout << i + 1 << ' ' << j + 1 << '\n';
							flag = 1;
							break;
						}
					}
					if (flag) break;
				}
				if (flag) break;
			}
		}
		if (cases) cout << '\n';
	}
}
	
