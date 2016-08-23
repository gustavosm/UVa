#include <bits/stdc++.h>


using namespace std;

int main()
{
	double d, v, u;
	
	int cases;
	
	cin >> cases;
	cout.precision(3);
	for (int c = 1; c <= cases; ++c)
	{
		cin >> d >> v >> u;
		cout << "Case " << c << ": " ;
		if (v >= u || u == 0.0 || v == 0.0) cout << "can't determine\n";
		else
		{
			double aux = sqrt(u * u - v * v);
			
			double d1 = d / aux;
			double d2 = d / u;
			
			d2 -= d1;
			
			cout << fixed << fabs(d2) << '\n';
		}
	}
}
