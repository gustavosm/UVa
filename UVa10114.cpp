#include <bits/stdc++.h>


using namespace std;


int main()
{
	int mth;
	double pymt, vle;
	
	int qtde;
	int idx;
	double valor;
	
	double v[105];
	while (1)
	{
		cin >> mth >> vle >> pymt >> qtde;
		
		if (mth < 0) return 0;
		
		double deve = pymt;
		
		double value_car = pymt + vle;
		
		
		cin >> idx >> valor;
		
		v[idx] = valor;
		double ant = valor;
		int idx_ant = idx;
		
		for (int i = 1; i < qtde; ++i)
		{
			cin >> idx >> valor;
			for (int j = idx_ant + 1; j < idx; ++j) v[j] = ant;
			
			v[idx] = valor;
			
			ant = valor;
			idx_ant = idx;
			
		}
		for (int j = idx_ant + 1; j <= mth; ++j) v[j] = ant;
		
		int cnt;
		value_car *= (1 - v[0]);
		double taxa = pymt / (double)mth;
		
		for (cnt = 1; cnt <= mth; ++cnt)
		{
			if (deve < value_car)
				break;	
			deve -= taxa;
			value_car *= (1. - v[cnt]);	

		}
		
		cout << cnt - 1 << " month";
		if (cnt - 1 != 1) cout << 's';
		cout << '\n';
	}
}
