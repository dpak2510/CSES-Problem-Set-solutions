#include<bits/stdc++.h>
using namespace std;
int n, m, u, v;
vector<int> grp[100001], vis(100001), par(100001);
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>u>>v, grp[u].push_back(v), grp[v].push_back(u);
	queue<int> q;
	q.push(n);
	par[n] = -1;
	vis[n] = 1;
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		for(int i=0;i<grp[u].size();i++)
		{
			v = grp[u][i];
			if(!vis[v])
				q.push(v), par[v] = u, vis[v] = vis[u]+1;
		}
	}
	u=1;
	if(vis[u])
	{
		cout<<vis[u]<<endl;
		while(u != -1)
			cout<<u<<" ", u = par[u];
	}
	else
		cout<<"IMPOSSIBLE\n";
	return 0;
}