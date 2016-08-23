#include <bits/stdc++.h>


using namespace std;


int player[1000005];
int snake_ladder[105];

int main()
{
	int cases;
	
	int a, b, c;
	
	
	cin >> cases;
	int comeco, fim, x;
	int win;
	
	while (cases--)
	{
		cin >> a >> b >> c;
		memset(snake_ladder, 0, sizeof snake_ladder);
		
		for (int i = 0 ; i < a;  ++i) player[i] = 1;
		
		for (int i = 0 ; i < b; ++i)
		{
			cin >> comeco >> fim;
			
			snake_ladder[comeco] = fim;
		}
		int player_atual = 0;
		win = 0;
		
		for (int i = 0 ; i < c; ++i)
		{
			cin >> x;
			if (!win)
			{
				int get = player[player_atual];
			
				
				if (snake_ladder[get + x] != 0) player[player_atual] = snake_ladder[get + x];
				else player[player_atual] = get + x;
				
				if (player[player_atual] >= 100) player[player_atual] = 100, win = 1;
				
				player_atual = (player_atual + 1) % a;
			}
		}
		
		for (int i = 0 ; i < a; ++i)
			cout << "Position of player " << (i + 1) << " is " << player[i] << ".\n";
	}
}
