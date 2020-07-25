#include<bits/stdc++.h>
using namespace std;
 
#define inf 9999999
 
int n, m, u, v;
vector<int> grp[100001], succ(100001,-1), vis(100001,-1);
 
int dfs(int src)
{
	if(vis[src]!=-1)
		return vis[src];
	int mx = -inf, node=-1;
	for( int i=0 ; i<grp[src].size() ; i++ )
	{
		int u = grp[src][i];
		int dp = dfs(u);
		if(mx < dp)
			mx = dp, node = u;
	}
	return succ[src] = node, vis[src] = ( mx == -inf ? mx: mx+1);
}
 
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>u>>v, grp[u].push_back(v);
	vis[n] = 0;
	succ[n] = -1;
	dfs(1);
	if(succ[1] == -1)
		cout<<"IMPOSSIBLE\n";
	else
	{
		queue<int> q;
		u = 1;
		while(u != -1)
			q.push(u), u = succ[u];
		cout<<q.size()<<"\n";
		while(!q.empty())
			cout<<q.front()<<" ", q.pop();
		cout<<"\n";
	}
	return 0;
}