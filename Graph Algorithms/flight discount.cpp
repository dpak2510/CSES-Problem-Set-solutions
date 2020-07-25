#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define pr pair<ll,ll>
#define mp make_pair
#define inf 9999999999999999LL
 
vector<pr > grp[100001], grpr[100001];
vector<ll> diss(100001, inf), disd(100001, inf), vis1(100001,0), vis2(100001,0);
ll n,m,u,v,w,sol=inf;
priority_queue<pr ,vector<pr > , greater<pr > >pq;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>u>>v>>w, grp[u].push_back(mp(v,w)), grpr[v].push_back(mp(u,w));
	pq.push(mp(0,1));
	diss[1] = 0;
	while(!pq.empty())
	{
		pr cur = pq.top(); pq.pop();
		if(vis1[cur.second])
			continue;
		vis1[cur.second] = 1;
		for(int i=0 ; i<grp[cur.second].size() ; i++)
		{
			pr tmp = grp[cur.second][i];
			if(diss[cur.second] + tmp.second < diss[tmp.first])
			{
				pq.push(mp(diss[cur.second] + tmp.second, tmp.first));
				diss[tmp.first] = diss[cur.second] + tmp.second;
			}
		}
	}
	pq.push(mp(0,n));
	disd[n] = 0;
	while(!pq.empty())
	{
		pr cur = pq.top(); pq.pop();
		if(vis2[cur.second])
			continue;
		vis2[cur.second] = 1;
		for(int i=0 ; i<grpr[cur.second].size() ; i++)
		{
			pr tmp = grpr[cur.second][i];
			if(disd[cur.second] + tmp.second < disd[tmp.first])
			{
				pq.push(mp(disd[cur.second] + tmp.second, tmp.first));
				disd[tmp.first] = disd[cur.second] + tmp.second;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<grp[i].size();j++)
			sol = min(sol, diss[i]+disd[grp[i][j].first]+grp[i][j].second/2);
	}
	cout<<sol<<"\n";
}