#include <bits/stdc++.h>

using namespace std;

bool valido_m(char c)
{
	return !(c != 'A' && c != 'E' && c != 'H' && c != 'I' && c != 'J' && c != 'L' && c != 'M' && c != 'O' && c != 'S' && c != 'T' && c != 'U' && c != 'V' && c != 'W' && c != 'X' && c != 'Z' && c != 'Y' && c != '1' && c != '2' && c != '3' && c != '5' && c != '8');		
}

bool compare(char c, char d)
{
	if (c == 'S' && d != '2') return false;
	if (c == '2' && d != 'S') return false;
	if (c == '3' && d != 'E') return false;
	if (c == 'E' && d != '3') return false;
	if (c == '5' && d != 'Z') return false;
	if (c == 'Z' && d != '5') return false;
	if (c == 'L' && d != 'J') return false;
	if (c == 'J' && d != 'L') return false;
	if (c == '2' && d == 'S') return true;
	if (c == 'S' && d == '2') return true;
	if (c == '3' && d == 'E') return true;
	if (c == 'E' && d == '3') return true;
	if (c == '5' && d == 'Z') return true;
	if (c == 'Z' && d == '5') return true;
	if (c == 'L' && d == 'J') return true;
	if (c == 'J' && d == 'L') return true;
	return c == d;
}

bool mirrored(string a)
{
	int tam = a.size();
	
	for (int i = 0 ; i < tam / 2 + tam % 2; ++i)
	{
		char c = a[i];
		char d = a[tam - 1 - i];
		
		if (!valido_m(c) || !valido_m(d)) return false;
		
		if (!compare(c, d)) return false;
	}
	return true;
}

bool palindrome(string a)
{
	int tam = a.size();
	
	for (int i = 0 ; i < tam / 2; ++i)
	{
		char c = a[i];
		char d = a[tam - 1 - i];		
		if (c != d) return false;
	}
	return true;
}

int main()
{
	string a;
	bool p, m, mp;
	
	while (cin >> a)
	{
		p = palindrome(a);
		m = mirrored(a);
		if (!p && !m) cout << a << " -- is not a palindrome.\n\n";
		else if (p && !m) cout << a << " -- is a regular palindrome.\n\n";
		else if (p && m) cout << a << " -- is a mirrored palindrome.\n\n";
		else cout << a << " -- is a mirrored string.\n\n";
	}
}
