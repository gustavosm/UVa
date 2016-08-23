#include <bits/stdc++.h>


using namespace std;


int main()
{
	string in;
	string aux;
	
	string palindrome;
	
	stringstream ss;
	
	while (1)
	{
		getline(cin, in);
		
		if (in == "DONE") return 0;
		
		
		for (int i = 0 ; i < in.size(); ++i)
		{
			if (!isalpha(in[i])) in[i] = ' ';
			else in[i] = tolower(in[i]);
		}
		
		ss << in;
		
		while (ss >> aux)
		{
			palindrome += aux;
		}
		ss.clear();
		string aux2 = palindrome;
		reverse(aux2.begin(), aux2.end());
		
		if (aux2 == palindrome) cout << "You won't be eaten!\n";
		else cout << "Uh oh..\n";
		palindrome.clear();
	}
}
