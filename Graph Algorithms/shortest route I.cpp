#include<bits/stdc++.h>
using namespace std;
 
#define mp make_pair
typedef long long ll;
ll n,m,u,v,w;
vector<pair<ll,ll> > grp[100001];
vector<ll> dis(100001, (ll)10e15), vis(100001);
priority_queue<pair<ll,ll> , vector<pair<ll,ll> >, greater<pair<ll, ll> > > pq;
 
int main()
{
	cin>>n>>m;
	for(ll i=0;i<m;i++)
		cin>>u>>v>>w, grp[u].push_back(mp(v,w));
	pq.push(mp(0,1));
	dis[1] = 0;
	while(!pq.empty())
	{
		pair<ll,ll> cur = pq.top();
		pq.pop();
		if(vis[cur.second])
			continue;
		vis[cur.second] = 1;
		for(ll i=0;i<grp[cur.second].size();i++)
		{
			pair<ll,ll> tmp = grp[cur.second][i];
			if(dis[tmp.first] > dis[cur.second] + tmp.second)
			{
				dis[tmp.first] = dis[cur.second]+tmp.second;
				pq.push(mp(dis[tmp.first], tmp.first));
			}
		}
	}
	for(ll i=1;i<=n;i++)
		cout<<dis[i]<<" ";
	return 0;
}