#include <bits/stdc++.h>


using namespace std;


int mdc[105][105];
int ans[35];
int qtde;


void preenche()
{
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = i; j <= 100; ++j)
			mdc[i][j] = mdc[j][i] = __gcd(j, i);
	}
}

void calc(int n, int sum, int mn)
{
	//cout << "aqui " << n << "\n";
	if (n == qtde)
	{
		if (sum == 0)
		{
			for (int i = 0 ; i < n ; ++i)
			{
				if (i) cout << ' ';
				cout << ans[i];
			}
			cout << '\n';
		}
		return;
	}
	int ok;
	for (int i = mn; i * (qtde - n) <= sum; ++i)
	{
		ok = 1;
		for (int j = 0 ; j < n && ok; ++j) if (mdc[ans[j]][i] != 1)
			ok = 0;
			
		if (ok)
		{
			ans[n] = i;
			calc(n + 1, sum - i, i);
		}
	}
}


int main()
{
	int cases;
	int c = 1;
	int tot;
	
	ios_base :: sync_with_stdio(0); cout.tie(0);
	
	preenche();
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> tot >> qtde;
		
		cout << "Case " << c << ":\n";
		++c;
		calc(0, tot, 1);
		
	}
}
