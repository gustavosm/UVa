/*

Eq1:  x + y = S
Eq2:  |x - y| = D
x = S - y
|S - y - y| = D ->
				-(S - y - y) = D
				(S - y - y) = D
				
				2y - S = D
				y = (D + S) / 2 -> (D + S) tem que ser par pra isso dar certo
				
				S - 2y = D
				2y = S - D
				y = (S - D) / 2 -> (S - D) tem que ser par e positivo pra dar certo
				
				
				Os dois tem que dar certo, senao eh impossivel determinar
				
				*/
				
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
	ll S, D;
	
	ll x, y;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	int cases;
	cin >> cases;
	while (cases--)
	{
		cin >> S >> D;
		if (((S + D) & 1) || (S < D) || ((S - D) & 1)) cout << "impossible\n";
		else
		{
			y = (S + D) / 2;
			x = S - y;
			if (x < y) swap(x, y);
			
			if (x + y == S && (abs(x - y) == D)) cout << x << ' ' << y << '\n';
			else
			{
				y = (S - D) / 2;
				x = S - y;
				if (x < y) swap(x, y);
			
				if (x + y == S && (abs(x - y) == D)) cout << x << ' ' << y << '\n';
				else cout << "impossible\n";
			}
		}
	}
}
