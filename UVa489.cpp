#include <bits/stdc++.h>


using namespace std;


int main()
{
	int frequencia[27];
	
	int round;
	string s1, s2;
	
	while(1)
	{
		cin >> round;
		
		if (round == -1) break;
		getchar();
		getline(cin, s1);
		getline(cin, s2);
		memset(frequencia, -1, sizeof frequencia);
		
		for (int i = 0 ; i < s1.size(); ++i)
		{
			if (frequencia[s1[i] - 'a'] == -1)
				frequencia[s1[i] - 'a'] = 1;
			else ++frequencia[s1[i] - 'a'];
		}
		
		int wrong = 0;
		int acerto = 0;
		for (int i = 0 ; i < s2.size(); ++i)
		{
			if (frequencia[s2[i] - 'a'] > 0)
			{
				acerto += frequencia[s2[i] - 'a'];
				frequencia[s2[i] - 'a'] = 0;
			}
			else if (frequencia[s2[i] - 'a'] == -1)
			{
				++wrong;
				frequencia[s2[i] - 'a'] = 0;
			}
			
			if (wrong == 7) break;
		}
		cout << "Round " << round << '\n';
		if (acerto == s1.size())
			cout << "You win.\n";
			
		else if (wrong == 7) 
			cout << "You lose.\n";
			
		else 
			cout << "You chickened out.\n";
	}
}
