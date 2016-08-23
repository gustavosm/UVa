#include <bits/stdc++.h>

#define MAXIND 300002
#define MAXN 100003
#define INF INT_MAX
using namespace std;

int N;
int v[MAXN];
int inicio[MAXN];
int fim[MAXN]; 
int A[MAXN];
int M[MAXIND];

void initialize( int node, int b, int e ) 
{ 
	if ( b == e ) M[node] = b;
	else 
	{
		int m = ( b + e ) / 2;
		initialize( 2 * node, b, m );
		initialize( 2 * node + 1, m + 1, e );
		
		if ( A[M[2 * node]] <= A[M[2 * node + 1]] ) 
			M[node] = M[2 * node];
		
		else M[node] = M[2 * node + 1];
	}
}
int query( int node, int b, int e, int i, int j ) 
{
	if ( i > e || j < b ) return -1;
	if ( b >= i && e <= j ) return M[node];
	
	int m = ( b + e ) / 2;
	
	int p1 = query( 2 * node, b, m, i, j );
	int p2 = query( 2 * node + 1, m + 1, e, i, j );
	
	if ( p1 == -1 ) return p2;
	if ( p2 == -1 ) return p1;

	if ( A[p1] < A[p2] ) return p1;

	return p2;
}
int preprocess_most_frequent_value() 
{
	int freq = 0, last = INF, first_index = 0;
	for (int i = 0 ; i < N; i++)
	{
		if ( v[i] != last ) 
		{
			for (int j = first_index; j <= i - 1; j++)
			{
				A[j] = -freq; 
				inicio[j] = first_index; 
				fim[j] = i - 1;
			}
			freq = 1; 
			first_index = i;
		}
		else freq++;
		last = v[i];
	}
	for (int j = first_index; j <= N - 1; j++)
	{
		A[j] = -freq; 
		inicio[j] = first_index; 
		fim[j] = N - 1;
	}
	memset( M, -1, sizeof( M ) );
	initialize( 1, 0, N - 1 );
}
// retorna o indice do valor mais frequente. trata o primeiro e o ultimo valores
// do intervalo como casos especiais
int query_most_frequent_value( int b, int e ) 
{
	int freq1, freq2, freq3 = -INF, index, MAXF;
	
	freq1 = min( fim[b], e ) - b + 1; 
	freq2 = e - max( inicio[e], b ) + 1;
	
	if ( b + freq1 < e - freq2 ) 
	{
		index = query( 1, 0, N - 1, b + freq1, e - freq2 );
		freq3 = -A[index];
	}
	MAXF = max( freq1, max( freq2, freq3 ) );
	return ( MAXF == freq1 ) ? ( b ) : ( MAXF == freq2 ? e : index );
}

int main()
{
	int q;
	int x;
	int y;
	while(1)
	{
		cin >> N;
		if (!N) return 0;
		
		cin >> q;
		
		for (int i = 0 ; i < N; i++)
		{
			cin >> v[i];
		}
		preprocess_most_frequent_value();
		
		for (int i = 0 ; i < q; i++)
		{
			cin >> x >> y;
			--x;
			--y;
			cout << query_most_frequent_value(x, y) << '\n';
		}
	}
}
