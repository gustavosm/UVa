#include <bits/stdc++.h>


using namespace std;


int main()
{
	double L, W;
	double a, b;
	
	
	int c = 1;
	
	while (cin >> a >> b)
	{
		double theta = 2 * atan(b / a);
		theta = (180. * theta) / M_PI;
		L = (400. - (theta * 2 * M_PI / 360.)) / 2.;
		W = (L * b) / a;
		
		cout << setprecision(12) << fixed << "Case " << c++ << ": " << L << ' ' << W << '\n';
	}
}
