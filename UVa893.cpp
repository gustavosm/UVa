#include <bits/stdc++.h>


using namespace std;


int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool bissexto(int a)
{
	return ((a % 400 == 0) || (a % 4 == 0 && a % 100 != 0));
}

int main ()
{
	long long dias, m, d, y;
	long long i;
	while (cin >> dias >> d >> m >> y)
	{
		if (!dias && !d && !m && !y) return 0;
		
		if (bissexto(y))
		  days[1] = 29;
		else
		  days[1] = 28;

		if (dias + d <= days[m - 1])
		{
			cout << d + dias << ' ' << m << ' ' << y << '\n';
			continue;
		}
		dias -= (days[m - 1] - d);
		++m;
		if (m > 12) 
		{
			++y;
			m = 1;
			if (bissexto(y)) 
				days[1] = 29; 
			else
				days[1] = 28;
		}
		
		while (dias > days[m - 1])
		{
			dias -= days[m - 1];
			++m;
			
			if (m > 12)
			{
				++y;
				m = 1;
				days[1] = (bissexto(y)? 29 : 28);
			}
		}
		printf("%d %d %d\n", dias, m, y);
	}
}
