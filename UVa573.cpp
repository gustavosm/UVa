#include <bits/stdc++.h>


using namespace std;


int main()
{
	double h, u, d, f;
	
	
	while (1)
	{
		cin >> h >> u >> d >> f;
		
		
		if (h == 0.0 && u == 0.0 && d == 0.0 && f == 0.0) return 0;
		
		
		double drop = (u * f) / 100.;
		
		double dist = u;
		
		u = 0.0;
		int day = 0;
		int flag = 0;
		while (1)
		{
			++day;
			u += dist;
			if (u > h) 
			{
				flag = 1;
				break;
			}
			u -= d;
			if (u < 0.0)
			{
				flag = 2;
				break;
			}
			dist -= drop;
			
			if (dist < 0.0) dist = 0.0;
		}
		
		if (flag == 1) cout << "success on day " << day << '\n';
		else cout << "failure on day " << day << '\n';
	}
}
