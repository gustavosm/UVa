#include <bits/stdc++.h>


using namespace std;


char t[700];
int sfx[700];
int lcp[700];
int n;
int maior;
int tam_a;

set<string> s;


int cmp(int a, int b)
{
	return strcmp(t + a, t + b) < 0;
}

void monta_lcp()
{
	lcp[0] = 0;
	
	maior = 0;
	for (int i = 1 ; i < n; ++i)
	{
		int l = 0;
		
		while (t[sfx[i] + l] == t[sfx[i - 1] + l]) ++l;
		
		if ((sfx[i] < tam_a) != (sfx[i - 1] < tam_a))
			lcp[i] = l, maior = max(maior, l);
		else lcp[i] = 0;
	}
}

int main()
{
	int pl = 0;
	char a[305];
	ios_base :: sync_with_stdio(0) ; cin.tie(0);
	while (cin >> a)
	{
		strcpy(t, "");
		strcat(t, a);
		tam_a = strlen(a);
		strcat(t, "$");
		cin >> a;
		strcat(t, a);
		strcat(t, "#");
		
		n = strlen(t);
		
		if (pl) cout << '\n';
		pl = 1;
		
		for (int i = 0 ; i < n ; ++i) sfx[i] = i;
		
		sort(sfx, sfx + n, cmp);
		
		monta_lcp();
		
		if (maior == 0) cout << "No common sequence.\n";
		else
		{
			string ans;
			
			for (int i = 1 ; i < n; ++i)
			{
				//if ((sfx[i] < tam_a) != (sfx[i - 1] < tam_a))
				//{
					if (lcp[i] == maior)
					{
						ans.clear();
						for (int j = 0 ; j < maior; ++j)
						{
							ans += t[sfx[i] + j];
						}
						s.insert(ans);
					}
			//	}
			}
			for (set<string> :: iterator it = s.begin(); it != s.end() ; ++it)
				cout << *it << '\n';
			s.clear();
			
		}
	}
}
