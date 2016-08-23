#include <bits/stdc++.h>


using namespace std;


int main()
{
	char c;
	bool troca = true;
	
	while (scanf("%c", &c) != EOF)
	{
		if (c == '"')
		{
			if (troca)
			{
				cout << "``";
				troca = false;
			}
			else
			{
				cout << "''";
				troca = true;
			}
		}
		else cout << c;
	}
}
