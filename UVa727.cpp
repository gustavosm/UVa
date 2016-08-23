#include <bits/stdc++.h>

using namespace std;
 
stack <char> s;
vector <char> output;
 
bool checkOperator (char p)
{
    if ( p == '+' || p == '-' || p == '*' || p == '/' || p == '^') return true;
    return false;
}
 
int hasPrecedence (char p, char q)
{
	if (p == '^') return 1;
    if ( (p == '*' || p == '/') && (q == '+' || q == '-')  ) return 1;
    if ( (p == '+' || p == '-') && (q == '*' || q == '/')  ) return -1;
 
    return 0;
}
 
bool ok(char c)
{
	return isdigit(c) || isalpha(c);
}
void setOperator (char op)
{
    queue <char> temp;
 
    if ( !s.empty () && s.top () != '(' && hasPrecedence(op, s.top ()) <= 0 ) {
        output.push_back (s.top ());
        s.pop ();
    }
 
    while ( !s.empty () && s.top () != '(' && hasPrecedence(op, s.top ()) <= 0 ) {
        temp.push (s.top ());
        s.pop ();
    }
 
    s.push (op);
 
    while ( !temp.empty ()) {
        output.push_back (temp.front ());
        temp.pop ();
    }
}
 
int main ()
{
    int testCase;
    scanf ("%d", &testCase);
 
    while ( testCase-- ) {
        string input;
        string ch;
        cin >> ch;
        output.clear ();
 		int i = 0;
        while ( i < ch.size()) {
            if ( ch [i] == '(' ) {
                if ( input.length() && !ok(input [input.length () - 1]))
                    input += 'x';
            }
            else if ( ok (ch [i]) ) {
                if ( input.length() && input [input.length () - 1] == ')')
                    input += 'x';
            }
 
            input += ch [i];
            ++i;
        }
 
        for ( size_t i = 0; i < input.length (); i++ ) {
            if ( ok (input [i]) ) output.push_back (input [i]);
            else if ( checkOperator (input [i]) ) {
                setOperator (input [i]);
            }
            else if ( input [i] == '(' ) s.push ('(');
            else if ( input [i] == ')' ) {
                while ( s.top () != '(' ) {
                    output.push_back (s.top ());
                    s.pop ();
                }
                s.pop ();
            }
        }
 
        while ( !s.empty () ) {
            output.push_back (s.top ());
            s.pop ();
        }
 
        for ( size_t i = 0; i < output.size (); i++ ) {
            if ( output [i] != 'x' )
                printf ("%c", output [i]);
        }
        printf ("\n");
    }
 
    return 0;
}
