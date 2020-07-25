#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a, b, val, ret;
vector<ll> grph[200001], cgrph[100001], wghts(100001), vis(200001), cwghts(100001), dp(100001, -1);
stack<ll> stk;

ll dfs(ll src, ll val, bool flag = 1)
{
	vis[src] = val;
	ll ret;
	if(!flag)
		ret = wghts[src-n];
	for( auto u: grph[src] )
		if(!vis[u])
			ret += dfs(u, val, flag);
	if(flag) stk.push(src);
	return ret;	
}

ll dfs2(ll src)
{
	if(dp[src]!=-1)
		return dp[src];
	ll ret = cwghts[src], mx=0;
	for(auto u: cgrph[src])
		mx = max(dfs2(u),mx);
	return dp[src] = ret+mx;
}

int main()
{
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>wghts[i];
	for(ll i=0;i<m;i++)
		cin>>a>>b, grph[a].push_back(b), grph[n+b].push_back(n+a);
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i, ++val);
	val=1;
	while(!stk.empty())
		if(!vis[n+stk.top()])
			cwghts[val] = dfs(n+stk.top(), val, 0), stk.pop(), val++;
		else
			stk.pop();
	for(int i=1;i<=n;i++)
	{
		for(auto u: grph[i])
			if(vis[n+i]!=vis[n+u])
				cgrph[vis[n+i]].push_back(vis[n+u]);
	}
	for(int i =1;i<=n;i++)
		dfs2(i);
	val=0;
	for(int i=1;i<=n;i++)
		val = max(val, dp[i]);
	cout<<val<<"\n";
	return 0;	
}
