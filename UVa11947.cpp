#include <bits/stdc++.h>


using namespace std;


int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool bissexto(int a)
{
	return ((a % 400 == 0) || (a % 4 == 0 && a % 100 != 0));
}

string getsig(int day, int month)
{
	
  if (day >= 21 && month == 1 || day <= 19 && month == 2)
    return "aquarius";
  if (day >= 20 && month == 2 || day <= 20 && month == 3)
    return "pisces";
  if (day >= 21 && month == 3 || day <= 20 && month == 4)
    return "aries";
  if (day >= 21 && month == 4 || day <= 21 && month == 5)
    return "taurus";
  if (day >= 22 && month == 5 || day <= 21 && month == 6)
    return "gemini";
  if (day >= 22 && month == 6 || day <= 22 && month == 7)
    return "cancer";
  if (day >= 23 && month == 7 || day <= 21 && month == 8)
    return "leo";
  if (day >= 22 && month == 8 || day <= 23 && month == 9)
    return "virgo";
  if (day >= 24 && month == 9 || day <= 23 && month == 10)
    return "libra";
  if (day >= 24 && month == 10 || day <= 22 && month == 11)
    return "scorpio";
  if (day >= 23 && month == 11 || day <= 22 && month == 12)
    return "sagittarius";
  if (day >= 23 && month == 12 || day <= 20 && month == 1)
    return "capricorn";
}
int main ()
{
	int cases;
	int date;
	int m, d, y;


	cin >> cases;

	for (int caso = 1; caso <= cases; ++caso) 
	{
		cin >> date;

		y = date % 10000;
		date /= 10000;
		d = date % 100;
		m = date / 100;

		if (bissexto(y))
		  days[1] = 29;
		else
		  days[1] = 28;

		for (int i = 0; i < 40 * 7; ++i) 
		{
			++d;
			if (d > days[m - 1]) 
			{
				d = 1;
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
			}
		}
		
		cout << caso << ' ';
		printf("%02d/%02d/%0004d ", m, d, y);
		cout << getsig(d, m) << '\n';
	}
    return 0; 
}
