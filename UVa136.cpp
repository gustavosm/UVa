#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef unsigned long long ll;

string ordinal(int n)
{
	int alg = n % 10;
	int cen = n % 100;
	if (alg == 1 && cen != 11) return "st";
	if (alg == 2 && cen != 12) return "nd";
	if (alg == 3 && cen != 13) return "rd";
	return "th";
}
int main()
{
	vector<ll> s;
	
	ll pot2, pot3, pot5;
	pot2 = pot3 = pot5 = 1;
	for (int i = 0 ; i < 35; ++i)
	{
		if (i) pot2 *= 2;
		pot3 = 1;
		if (pot2 > 2000000000LL) break;
		for (int j = 0 ; j < 35; ++j)
		{		
			if (j) pot3 *= 3;
			pot5 = 1;
			if (pot3 * pot2 > 2000000000LL) break;
			for (int k = 0 ; k < 35; ++k)
			{
				if (k) pot5 *= 5;
				if (pot5 * pot3 * pot2 > 2000000000LL) break;
				s.push_back(pot2 * pot3 * pot5 );
			}
		
		}
	}
	int n;
	sort(s.begin(), s.end());
	cout << "The 1500'th ugly number is " << s[1499] << ".\n";
	
}
