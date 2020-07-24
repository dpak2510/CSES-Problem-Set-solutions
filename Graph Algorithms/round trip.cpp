#include<bits/stdc++.h>
using namespace std;
 
int n, m, u, x;
vector<int> grp[100001], v, vis(100001);
 
void dfs( int src, int l )
{
	vis[src] = l;
	for(int i=0;i<grp[src].size();i++)
	{
		u = grp[src][i];
		if(!vis[u])
		{
			v.push_back(u);
			dfs(u, l+1);
			v.pop_back();
		}
		else if(vis[u] < vis[src]-1)
		{
			cout<<vis[src] - vis[u]+2<<endl<<u<<" ";
			for(int i=v.size()-1;i>=0;i--)
			{
				cout<<v[i]<<" ";
				if(v[i] == u)
					break;
			}
			exit(0);
		}
	}
}
 
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>u>>x, grp[u].push_back(x), grp[x].push_back(u);
	for(int i=0;i<n;i++)
		if(!vis[i+1])
			v.push_back(i+1), dfs(i+1,1), v.pop_back();
	cout<<"IMPOSSIBLE\n";
	return 0;
}