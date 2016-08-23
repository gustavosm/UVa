#include <iostream>

using namespace std;

struct rec
{
	int mn, mx;
};

rec make_rec(int mn, int mx){  rec r;  r.mn = mn;  r.mx = mx;  return r; }

struct cubo
{
	rec x, y, z;
	cubo(rec X, rec Y, rec Z){x = X; y = Y; z = Z;}
};


bool intersect(rec a, rec b, rec &c)
{
	if (a.mn > b.mx || b.mn > a.mx) return false;
	c.mn = max(a.mn,b.mn);
	c.mx = min(a.mx,b.mx);
	return true;
}

bool intersect2(cubo a, cubo b, cubo &c)
{
	if (!intersect(a.x, b.x, c.x)) return false;
	if (!intersect(a.y, b.y, c.y)) return false;
	if (!intersect(a.z, b.z, c.z)) return false;
	return true;
}


int main()
{
	int noCubos;
	while (1)
	{
		cin >> noCubos;
		if (!noCubos) return 0;
		
		bool ok = false;
		int x, y, z, r;
		
		cin >> x >> y >> z >> r;
		cubo resultado(make_rec(x, x + r), make_rec(y, y + r), make_rec(z, z + r));  

		for (int i = 1; i < noCubos; ++i)
		{
			cin >> x >> y >> z >> r;
			cubo temp(make_rec(x, x + r), make_rec(y, y + r), make_rec(z, z + r));  
			if (!intersect2(resultado, temp, resultado))
			{
				cout << "0\n";
				ok = true;
			}
		}

		if (!ok)
			cout << (resultado.x.mx - resultado.x.mn) * (resultado.y.mx - resultado.y.mn) * (resultado.z.mx - resultado.z.mn) << '\n';
	}
	return 0;
}
