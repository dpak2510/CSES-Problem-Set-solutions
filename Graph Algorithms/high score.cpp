#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define inf 999999999999999
#define tp tuple<ll,ll,ll>
#define mt make_tuple
 
ll n, m, u, v, w;
vector<tp > grp;
vector<ll> dis(2501, -inf);
 
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>u>>v>>w, grp.push_back(mt(u,v,w));
	dis[1] = 0;
	for( int i=0 ; i<n-1 ; i++ )
	{
		for(int j=0;j<m;j++)
		{
			tie(u,v,w) = grp[j];
			if(dis[u] != -inf && dis[v] < dis[u]+w)
				dis[v] = dis[u]+w;
		}
	}
	for( int i=0 ; i<n-1 ; i++ )
	{
		for(int j=0;j<m;j++)
		{
			tie(u,v,w) = grp[j];
			if(dis[u] != -inf && dis[v] < dis[u]+w)
				dis[v] = inf;
		}
	}
	if( dis[n] < inf )
		cout<<dis[n];
	else cout<<-1<<endl;
	return 0;
}