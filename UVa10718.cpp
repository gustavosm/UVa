#include <bits/stdc++.h>


using namespace std;


int main()
{
	unsigned int N, L, U;
	while (cin >> N >> L >> U) 
	{
		unsigned int M = ~N;
		for (int i = 31; i >= 0; --i) 
		{
			unsigned int MM = M >> i;
			unsigned int LL = L >> i;
			unsigned int UU = U >> i;
			unsigned int mask = 1 << i;
			if (MM < LL)
				M |= mask;
			else if (MM > UU)
				M &= ~mask;
			
		}
		cout << M << '\n';
	}
	return 0;
}
