#include<bits/stdc++.h>
using namespace std;
 
int n, m, u, x;
vector<int> grp[100001], vis(100001), v, inds(100001);
 
void dfs(int src)
{
	for( int i=0 ; i<grp[src].size() ; i++ )
	{
		u = grp[src][i];
		if(!vis[u])
		{
			vis[u] = 1;
			inds[u] = inds[src]+1;
			v.push_back(u);
			dfs(u);
			vis[u] = 2;
			v.pop_back();
		}
		else if(vis[u] == 1)
		{
			cout<<inds[src]-inds[u]+2<<"\n";
			for(int i=inds[u];i<=inds[src];i++)
				cout<<v[i]<<" ";
			cout<<u;
			exit(0);
		}
	}
}
 
int main()
{
	cin>>n>>m;
	for( int i=0 ; i<m ; i++ )
		cin>>u>>x, grp[u].push_back(x);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			v.push_back(i);
			vis[i] = 1;
			inds[i] = 0;
			dfs(i);
			v.pop_back();
			vis[i] = 2;
		}
	}
	cout<<"IMPOSSIBLE\n";
}