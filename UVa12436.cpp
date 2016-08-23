#include <bits/stdc++.h>

#define MAXN 250005


using namespace std;

typedef long long ll;


const ll ZERO = (1LL << 60);

class SegTree 
{
public:
	void build(ll _n)
	{
		n = _n;
		memset(st, 0, sizeof st);
		for (int i = 0 ; i < 4 * n; ++i) for (int j = 0 ; j < 3; ++j)
			lazy[i][j] = ZERO;
	}
	
	void update(ll l, ll r, ll val, char tipo)
	{
		_update(1, 1, n, l, r, val, tipo);
	}
	
	ll query(ll l, ll r)
	{
		return _query(1, 1, n, l, r);
	}
private:
	ll st[4 * MAXN], lazy[4 * MAXN][3];
	ll n;
	
	void prop(ll u, ll b, ll e, char tipo)
	{
	
		if (lazy[u][tipo - 'A'] != ZERO)
		{
			if (tipo == 'C')
			{
				st[u] = lazy[u][2];
				
				if (b != e)
				{
					ll cl = (u << 1);
					ll cr = cl + 1;
					
					lazy[cl][0] = lazy[cr][0] = lazy[cl][1] = lazy[cr][1] = ZERO;
					lazy[cl][2] = lazy[cr][2] = lazy[u][2];
				}
				
				lazy[u][2] = ZERO;
			}
			else
			{
				ll saveA = lazy[u][0];
				ll saveB = lazy[u][1];
				
				prop(u, b, e, 'C');
				
				if (saveA != ZERO)
					st[u] += saveA, lazy[u][0] = ZERO;
					
				if (saveB != ZERO)
					st[u] += saveB, lazy[u][1] = ZERO;
				
				if (b != e)
				{
					ll cl = (u << 1);
					ll cr = cl + 1;
					ll mid = (b + e) >> 1;
					
					ll a11 = 1LL;
					ll an1 = (mid - b + 1);
					ll qtd1 = (mid - b + 1);
					
					ll a12 = (e - (mid + 1) + 1);
					ll an2 = 1LL;
					ll qtd2 = (e - mid);
					
					if (saveA != ZERO)
					{
						if (lazy[cl][0] == ZERO)
							lazy[cl][0] = ((a11 + an1) * qtd1) / 2;
						else lazy[cl][0] += ((a11 + an1) * qtd1) / 2;
						
						if (lazy[cr][0] == ZERO)
							lazy[cr][0] = ((a12 + an2) * qtd2) / 2;
						else lazy[cr][0] += ((a12 + an2) * qtd2) / 2;;
					}
					if (saveB != ZERO)
					{
						if (lazy[cr][0] == ZERO)
							lazy[cr][0] = ((a11 + an1) * qtd1) / 2;
						else lazy[cr][0] += ((a11 + an1) * qtd1) / 2;
						
						if (lazy[cl][0] == ZERO)
							lazy[cl][0] = ((a12 + an2) * qtd2) / 2;
						else lazy[cl][0] += ((a12 + an2) * qtd2) / 2;;
					}
				}
			}			
		}
	}
	
	void _update(ll idx, ll i, ll j, ll l, ll r, ll val, char tipo)
	{
		prop(idx, i, j, 'A');
		prop(idx, i, j, 'B');
		
		if (j < l || i > r) return;
		else if (i >= l && j <= r)
		{
			if (tipo <= 'B')
			{
				if (lazy[idx][tipo - 'A'] != ZERO)
					lazy[idx][tipo - 'A'] += ((1 + (j - i + 1)) * (j - i + 1)) / 2;
				else lazy[idx][tipo - 'A'] = ((1 + (j - i + 1)) * (j - i + 1)) / 2;
				//cout << tipo << " == " << lazy[idx][tipo - 'A'] << '\n';
			}
			else lazy[idx][2] = val;//, cout << "Puis " << val << " em C\n";
			
			prop(idx, i, j, tipo);
		}
		else
		{
			ll cl = (idx << 1);
			ll cr = cl + 1;
			ll mid = (i + j) >> 1;
			
			_update(cl, i, mid, l, r, val, tipo);
			_update(cr, mid + 1, j, l, r, val, tipo);
			
			st[idx] = st[cl] + st[cr];
		}
	}
	
	ll _query(ll idx, ll i, ll j, ll l, ll r)
	{
		prop(idx, i, j, 'A');
		prop(idx, i, j, 'B');
		
		if (j < l || i > r) return 0;
		if (i >= l && j <= r) return st[idx];
		
		ll cl = (idx << 1);
		ll cr = cl + 1;
		ll mid = (i + j) >> 1;
		
		ll q1 = _query(cl, i, mid, l, r);
		ll q2 = _query(cr, mid + 1, j, l, r);
		
		return q1 + q2;		
	}
};

SegTree seg;

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	ll op;
	char t;
	ll a, b, c;
	cin >> op;
	seg.build(MAXN);
	
	
	for (ll i = 0 ; i < op; ++i)
	{
		cin >> t >> a >> b;
		//cout << t << '\n';
		if (t == 'S')
			cout << seg.query(a, b) << '\n';
		else
		{
			ll val = -1;
			if (t == 'C') cin >> val;
			
			seg.update(a, b, val, t);
			cout << "id: 1 vale " << seg.query(1, 1) << '\n';
			cout << "id: 2 vale " << seg.query(2, 2) << '\n';
			cout << "id: 3 vale " << seg.query(3, 3) << '\n';
			cout << "id: 4 vale " << seg.query(4, 4) << '\n';
		}
	}
}
