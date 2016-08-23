#include <bits/stdc++.h>


using namespace std;

int main()
{
      string a, b;
      stringstream ss;
      int cases;
      
      cin >> cases;
      getchar();
      for (int c = 1; c <= cases; ++c)
      {
             getline(cin, a);
             for (int i = 0 ; i < a.size(); ++i) if (!isalpha(a[i])) a[i] = ' ';

             ss << a;
             string aux, aux2;
             while (ss >> b)
             {
                    aux += b;
             }
             ss.clear();
             aux2 = aux;
             reverse(aux.begin(), aux.end());
             cout << "Case #" << c << ":\n";
             if (aux2 != aux) cout << "No magic :(\n";
             else
             {
                    int sqt = (int)sqrt(aux.size());
                    if (sqt * sqt == aux.size()) cout << sqt << '\n';
                    else cout << "No magic :(\n";
             }
      }
}
