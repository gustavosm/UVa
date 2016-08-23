#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n, b, h, w;
	int price, qtde;
	
	while (cin >> n >> b >> h >> w)
	{
		unsigned int mn = INT_MAX;
		
		
		for (int i = 0 ; i < h ; ++i)
		{
			cin >> price;
			for (int wk = 0; wk < w; ++wk)
			{
				cin >> qtde;
				
				if (qtde >= n && n * price <= b)
					mn = min(mn, (unsigned int)(n * price));
			}
		}
		
		if (mn == INT_MAX) cout << "stay home\n";
		else cout << mn << '\n';
	}
}
