#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define inf 9999999999999999LL
#define tp tuple<ll,ll,ll>
 
ll n, m, u, x, w, cnt=0;
bool flag = 0;
vector<tp > grp;
vector<ll> dis(2501, inf), par(2501), vis(2501);
 
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>u>>x>>w, grp.push_back({u,x,w});
		
	for( int i=1 ; i<=n ; i++ )
	{
		if(dis[i] == inf)
			dis[i] = 0, vis[i] = i;
		else
			continue;
		for(int j=0;j<n-1;j++)
		{
			flag = 0;
			for(int k=0;k<grp.size();k++)
			{
				tie(u,x,w) = grp[k];
				if( dis[u]+w < dis[x] && ( !vis[x] || vis[x]==i ))
				{
					flag = 1;
					vis[x] = i;
					par[x] = u;
					dis[x] = dis[u] + w;
				}
			}
			if(!flag)
				break;
		}
		for(int k=0;k<grp.size();k++)
		{
			tie(u,x,w) = grp[k];
			if( dis[u]+w < dis[x] && ( !vis[x] || vis[x]==i ))
			{
				par[x] = u;
				cout<<"YES\n";
				stack<int> stk;
				//cout<<">>>>"<<x<<"\n";
				ll s1=x,s2=par[x];
				while(s1!=s2) s1 = par[s1], s2 = par[par[s2]];
				u = s1;
				x = u, stk.push(u), u = par[u];
				while(u!=x)
					stk.push(u), u = par[u];//, cout<<"---->"<<u<<"\n";
				cout<<x<<" ";
				while(!stk.empty())
					cout<<stk.top()<<" ", stk.pop();
				exit(0);
				
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	    cout<<dis[i]<<" ";*/
	cout<<"NO\n";
	return 0;
}
