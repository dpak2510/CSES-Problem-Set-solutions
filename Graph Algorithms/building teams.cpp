#include<bits/stdc++.h>
using namespace std;
 
int n, m, u, v, vis[100001], stat;
vector<int> grp[100001];
 
void dfs(int src, int l)
{
	vis[src] = l;
	for(int i=0;i<grp[src].size();i++)
	{
		u = grp[src][i];
		if(!vis[u])
			dfs(u, l%2+1);
		else if( vis[u]==vis[src] )
			stat = 1;
	}
}
 
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>u>>v, grp[u].push_back(v), grp[v].push_back(u);
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i, 1);
	if(stat)
		cout<<"IMPOSSIBLE\n";
	else
		for(int i=1;i<=n;i++)
			cout<<vis[i]<<" ";
	return 0;
}