#include <bits/stdc++.h>


using namespace std;


char t[1005];
int lcp[1005];
int sfx[1005];
int n;
int idx;
int maior;

int cmp(int x, int y)
{
	return strcmp(t + x, t + y) < 0;
}

void monta_lcp()
{
	lcp[0] = 0;
	maior = 0;
	for (int i = 1 ; i < n; ++i)
	{
		int l = 0;
		
		while (t[sfx[i] + l] == t[sfx[i - 1] + l]) ++l;
		
		lcp[i] = l;
		if (l > maior)
		{
			maior = l;
			idx = i;
		}		
	}
}
int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	int cases;
	cin >> cases;
	while (cases--)
	{
		cin >> t;
		n = strlen(t);
		for (int i = 0 ; i < n; ++i) sfx[i] = i;
		
		sort(sfx, sfx + n, cmp);
		
		monta_lcp();
		int l = 0;
		if (maior == 0) cout << "No repetitions found!\n";
		else
		{
			string ans = "";
			for (int i = 0 ; i < maior; ++i)
			{
				ans += t[sfx[idx] + i];
			}
			while (idx + l < n && lcp[idx] == lcp[idx + l]) ++l;
			
			cout << ans << ' ' << l + 1 << '\n';
		}
		
		
	}
}



