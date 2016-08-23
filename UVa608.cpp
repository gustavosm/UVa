#include <bits/stdc++.h>


#define MINN 200
using namespace std;


int main()
{
	int cases;
	string s1, s2, opt;
	int peso[27];
	
	cin >> cases;
	
	while (cases--)
	{
		for (int i = 0 ; i < 27; ++i) peso[i] = MINN;
		
		for (int i = 0 ; i < 3; ++i)
		{
			cin >> s1 >> s2 >> opt;
			if (opt == "even")
			{
				for (int i = 0 ; i < s1.size(); ++i)
					peso[s1[i] - 'A'] = 0;
					
				for (int i = 0 ; i < s2.size(); ++i)
					peso[s2[i] - 'A'] = 0;
			}
			else if (opt == "down")
			{
				for (int i = 0 ; i < s1.size(); ++i)
					if (peso[s1[i] - 'A'] != 0)
					{
						if(peso[s1[i] - 'A'] == MINN)
							peso[s1[i] - 'A'] = -1;
						else
							--peso[s1[i] - 'A'];
					}
					
				for (int i = 0 ; i < s2.size(); ++i)
					if (peso[s2[i] - 'A'] != 0)
					{
						if(peso[s2[i] - 'A'] == MINN)
							peso[s2[i] - 'A'] = 1;
						else
							++peso[s2[i] - 'A'];
					}
			}
			else if (opt == "up")
			{				
				for (int i = 0 ; i < s1.size(); ++i)
					if (peso[s1[i] - 'A'] != 0)
					{
						if(peso[s1[i] - 'A'] == MINN)
							peso[s1[i] - 'A'] = 1;
						else
							++peso[s1[i] - 'A'];
					}
					
				for (int i = 0 ; i < s2.size(); ++i)
					if (peso[s2[i] - 'A'] != 0)
					{
						if(peso[s2[i] - 'A'] == MINN)
							peso[s2[i] - 'A'] = -1;
						else
							--peso[s2[i] - 'A'];
					}
			}
		}
		int pos;
		for (pos = 0; pos < 13; ++pos) if (peso[pos] != MINN) break;
		for (int i = 0; i <= 12 ; ++i)
		{
			if (peso[i] < MINN && abs(peso[i]) > abs(peso[pos]))
				pos = i;
		}
		cout << (char)(pos + 'A') << " is the counterfeit coin and it is " << (peso[pos] < 0 ? "light.\n" : "heavy.\n");
	}
}
