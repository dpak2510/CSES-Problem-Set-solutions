#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll n, m, u, v, w, q, adj[501][501];
#define inf 9999999999999L
 
int main()
{
	cin>>n>>m>>q;
	for( ll i=1 ; i<=n ; i++ )
		for( ll j=1 ; j<=n ; j++ )
			if(i!=j) adj[i][j] = inf;
	for( ll i=1 ; i<=m ; i++ )
		cin>>u>>v>>w, adj[u][v] = min(adj[u][v],w), adj[v][u] = min(adj[v][u],w);
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				if(adj[i][k] + adj[k][j] < adj[i][j])
					adj[i][j] = adj[i][k] + adj[k][j];
	while(q--)
	{
		cin>>u>>v;
		cout<<(adj[u][v]==inf?-1:adj[u][v])<<endl;
	}
	return 0;
}