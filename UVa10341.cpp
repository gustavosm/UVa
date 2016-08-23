#include <bits/stdc++.h>

#define EPS 1e-4

using namespace std;


int nosolution;
int p, q, r, s, t, u;

double evaluate(double x)
{
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}
double bs()
{
	double e = 1.0;
	double b = 0.0;
	double mid;	

	while (e - b > EPS)
	{
		mid = (e + b) / 2.0;
		double eval = evaluate(mid);
		double ehigh = evaluate(e);
		if (fabs(eval) < EPS)
			return mid;
		if((ehigh < 0 && eval > 0) || 
	            (ehigh >= 0 && eval > ehigh) ||
	            (ehigh <= 0 && ehigh > eval)) 
	        b = mid;
	    else 
	        e = mid;
	}
	nosolution = 1;

	return -1;
} 


int main()
{
	while (cin >> p >> q >> r >> s >> t >> u)
	{
		nosolution = 0;
	
		double ans = bs();
	
		if (nosolution) cout << "No solution\n";
		else cout << setprecision(4) << fixed << ans << '\n';
	}
}
