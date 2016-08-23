#include <bits/stdc++.h>


using namespace std;

int waked[27];
int v[27][27];
vector<int> l;
	

int main()
{
	int n, m;
	int years, acordei;
	char c1,c2,c3;
	int ok;
	while(cin >> n >> m)
	{
		cin >> c1 >> c2 >> c3;
		
		for (int i = 0 ; i < 27; ++i)
		{
			for (int j = 0 ; j < 27; ++j) v[i][j] = 0;
			waked[i] = 0;
		}
		
		waked[c1 - 'A'] = waked[c2 - 'A'] = waked[c3 - 'A'] = 1;
		
		while (m--)
		{
			cin >> c1 >> c2;
			
			v[c1 - 'A'][c2 - 'A'] = v[c2 - 'A'][c1 - 'A'] = 1;
		}
		years = acordei = 0;
		
		for (int j = 0 ; j < n - 3; ++j)
		{
			for (int i = 0 ; i < 26; ++i)
			{
				if (!waked[i])
				{
					ok = 0;
					for (int k = 0 ; k < 26; ++k)
						if (waked[k] && v[i][k]) 
							++ok;
					
					if (ok >= 3)
						l.push_back(i);
				}
			}
			if (l.size() == 0) break;
			
			acordei += l.size();
			++years;
			
			for (int g = 0 ; g < l.size(); ++g) waked[l[g]] = 1;
			l.clear();
		}
		if (acordei == n - 3) cout << "WAKE UP IN, " << years << ", YEARS\n";
		else cout << "THIS BRAIN NEVER WAKES UP\n";
	}
}
