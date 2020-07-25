#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mp make_pair
#define pr pair<ll,ll>
 
ll n, m, u, v, w, k, cnt=0;
vector<pr > grp[100001];
priority_queue<pr, vector<pr >, greater<pr > > pq;
vector<ll> sol, vis(100001);
 
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
		cin>>u>>v>>w, grp[u].push_back(mp(v,w));
	pq.push(mp(0,1));
	while(!pq.empty())
	{
		pr cur = pq.top(); pq.pop();
		vis[cur.second]++;
		if( vis[cur.second] > k )
			continue;
		if(cur.second == n && vis[n]<=k)
			sol.push_back(cur.first);
		for(int i=0;i<grp[cur.second].size();i++)
		{
			pr tmp = grp[cur.second][i];
			pq.push(mp(cur.first + tmp.second, tmp.first));
		}
	}
	for(int i=0;i<sol.size();i++)
		cout<<sol[i]<<" ";
	cout<<"\n";
	return 0;
}