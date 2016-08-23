#include <bits/stdc++.h>

#define EPS 1e-9
using namespace std;



int main()
{
	int n, m;
	int terra[35][35];
	int mn;
	int qtde_agua;
	int rg = 1;
	double pctg;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	cout.precision(2);
	
	while (1)
	{
		cin >> n >> m;
		if (!n) return 0;
		mn = INT_MAX;
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < m ; ++j)
			{
				cin >> terra[i][j];
				mn = min(mn, terra[i][j]);
			}
		}
		
		cin >> qtde_agua;
		
		double low = mn;
		double upper = qtde_agua + mn;
		double mid;
		
		while (low <= upper)
		{
			mid = (low + upper) / 2.;
			double agua = 0.;
			for (int i = 0 ; i < n ; ++i)
			{
				for (int j = 0 ; j < m ; ++j)
				{
					if (terra[i][j] < mid)
						agua += (mid - terra[i][j]) * 100;
				}
			}
			
			if (fabs(agua - qtde_agua) < EPS)
				break;
			if (agua > qtde_agua) upper = mid;
			else low = mid;
		}
		int qtde = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < m ; ++j)
			{
				if (mid - terra[i][j] > EPS)
					++qtde;
			}
		}
		
		pctg = (double)(qtde * 100.) / (n * m);
		cout << "Region " << rg++ << '\n';
		cout << fixed << "Water level is " << mid << " meters.\n";
		cout << fixed << pctg << " percent of the region is under water.\n\n";
	}
}
