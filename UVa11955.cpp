#include <bits/stdc++.h>


using namespace std;


typedef long long ll;

ll cmb[51][51];

void comb()
{
	cmb[0][0] = 0;
	for (int i = 1; i <= 50; ++i)
	{
		cmb[0][i] = cmb[i][0] = 1;
		
		for (int j = 1; j <= i; ++j)
			cmb[i][j] = cmb[i - 1][j] + cmb[i - 1][j - 1];
	}
}

int main()
{
	comb();
	
	int cases;
	char str1[105], str2[105];
	int k;
	
	cin >> cases;
	getchar();
	for (int c = 1; c <= cases; ++c)
	{
		scanf("(%[a-z]+%[a-z])^%d", str1, str2, &k);
		getchar();
		cout << "Case " << c << ": ";
		for (int i = k; i >= 0; --i)
		{
			if (i != k) printf("+");
			if (cmb[k][i] != 1)
				cout << cmb[k][i] << '*';
			if (i)
			{
				if (i > 1)
					printf("%s^%d", str1, i);
				else printf("%s", str1);
				
				if (abs(i - k))
					printf("*");
			}
			if (abs(i - k))
			{
				if (abs(i - k) > 1)
					printf("%s^%d", str2, abs(i - k));
				else printf("%s", str2);
			}
		}
		printf("\n");
	}
}
