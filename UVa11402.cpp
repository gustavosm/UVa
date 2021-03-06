#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class SegmentTree 
{
private:
	vi st;
	vector<char> lazy;
	string sA;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }
	int div(int p) {return (p >> 1);}
	
	void build(int p, int L, int R)
	{
		if(L == R) st[p] = sA[L] - '0';
		else
		{
			int mid = div(L + R);
			build( left(p), L, mid);
			build(right(p), mid + 1, R);
			int s1 = st[left(p)], s2 = st[right(p)];
			st[p] = (s1 + s2);
		}
	}
	
	int rsq(int p, int L, int R, int i, int j)
	{
		if(lazy[p] != 'n')
		{
			switch(lazy[p])
			{
				case 'F':
					st[p] = (R - L + 1);
				break;
				
				case 'E':
					st[p] = 0;
				break;
				
				case 'I':
					st[p] = (R - L + 1) - st[p];
					break;
			}
			if(L != R)
			{
				if(lazy[p] == 'I')
				{
					if(lazy[left(p)] == 'F') lazy[left(p)] = 'E';
					else if(lazy[left(p)] == 'E') lazy[left(p)] = 'F';
					else if(lazy[left(p)] == 'I') lazy[left(p)] = 'n';
					else lazy[left(p)] = 'I';
					
					if(lazy[right(p)] == 'F') lazy[right(p)] = 'E';
					else if(lazy[right(p)] == 'E') lazy[right(p)] = 'F';
					else if(lazy[right(p)] == 'I') lazy[right(p)] = 'n';
					else lazy[right(p)] = 'I';
				}
				else
				{
					lazy[left(p)] = lazy[p];
					lazy[right(p)] = lazy[p];
				}
			}
			lazy[p] = 'n'; 
		}
		if( i > R || j < L ) return -1;
		if (L >= i && R <= j) return st[p];
		
		int mid = div(L + R);
		int s1 = rsq(left(p), L, mid, i, j);
		int s2 = rsq(right(p), mid + 1, R, i, j);
		if(s1 == -1) return s2;
		if(s2 == -1) return s1;
		return (s1 + s2);
	}
	
	void update(int p, int i, int j, int L, int R, char val)
	{
		if(lazy[p] != 'n')
		{
			switch(lazy[p])
			{
				case 'F':
					st[p] = (R-L+1);
				break;
				case 'E':
					st[p] = 0;
				break;
				case 'I':
					st[p] = (R-L+1)-st[p];
			}
			if(L != R)
			{
				if(lazy[p] == 'I')
				{
					if(lazy[left(p)] == 'F') lazy[left(p)] = 'E';
					else if(lazy[left(p)] == 'E') lazy[left(p)] = 'F';
					else if(lazy[left(p)] == 'I') lazy[left(p)] = 'n';
					else lazy[left(p)] = 'I';
					
					if(lazy[right(p)] == 'F') lazy[right(p)] = 'E';
					else if(lazy[right(p)] == 'E') lazy[right(p)] = 'F';
					else if(lazy[right(p)] == 'I') lazy[right(p)] = 'n';
					else lazy[right(p)] = 'I';
				}
				else
				{
					lazy[left(p)] = lazy[p];
					lazy[right(p)] = lazy[p];
				}
			}
			lazy[p] = 'n'; 
		}
		if(i > R || j < L) return ;	
		if(L >= i && R <= j)
		{
			switch(val)
			{
				case 'F':
					st[p] = (R-L+1);
				break;
				case 'E':
					st[p] = 0;
				break;
				case 'I':
					st[p] = (R-L+1)-st[p];
			}
			if(L != R)
			{ // lazy prop.
				if(val == 'I')
				{
					if(lazy[left(p)] == 'F') lazy[left(p)] = 'E';
					else if(lazy[left(p)] == 'E') lazy[left(p)] = 'F';
					else if(lazy[left(p)] == 'I') lazy[left(p)] = 'n';
					else lazy[left(p)] = 'I';
					
					if(lazy[right(p)] == 'F') lazy[right(p)] = 'E';
					else if(lazy[right(p)] == 'E') lazy[right(p)] = 'F';
					else if(lazy[right(p)] == 'I') lazy[right(p)] = 'n';
					else lazy[right(p)] = 'I';
				}
				else
				{
					lazy[left(p)] = val;
					lazy[right(p)] = val;
				}
			}
			return ;
		}
		int mid = div(L + R);
		update(left(p), i, j, L, mid, val);
		update(right(p), i, j, mid + 1, R, val);
		st[p] = st[left(p)] + st[right(p)];
	}
public:
	SegmentTree(const string &_A)
	{
		sA = _A; n = (int)sA.size();
		st.assign(4 * n, 0);
		lazy.assign(4 * n, 'n');
		build(1, 0, n - 1);
	}
	int rsq(int i, int j){ return rsq(1, 0, n - 1, i, j); }
	
	void update(int i, int j, char val){ update(1, i, j, 0, n - 1, val); }
};
int main()
{	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	int t, m, n, q, a, b;
	char c, cbits[60];
	string bits, pir;
	cin >> t;
	for(int caso = 1; caso <= t; ++caso)
	{
		pir = "";
		cin >> m;
		while(m--)
		{
			cin >> n;
			cin >> cbits;
			while(n--)
				pir += cbits;
				
		}
		SegmentTree st(pir);
		
		cin >> q;
		int ind = 0;
		cout << "Case " << caso << ":\n";
		while(q--)
		{
			cin >> c;
			cin >> a >> b;
			if(c == 'S')
				cout << "Q" << ++ind << ": " << st.rsq(a, b) << '\n';
			
			else
				st.update(a,b,c);
		}
	}
}
