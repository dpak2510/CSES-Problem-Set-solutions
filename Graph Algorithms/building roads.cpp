#include<bits/stdc++.h>
using namespace std;
 
int n, m, u, v, vis[100001];
vector<int> grp[100001], sol;
 
void dfs(int src)
{
	vis[src] = 1;
	for(int i=0;i<grp[src].size();i++)
		if(!vis[grp[src][i]])
			dfs(grp[src][i]);
}
 
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>u>>v, grp[u].push_back(v), grp[v].push_back(u);
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			sol.push_back(i);
			dfs(i);
		}
	cout<<sol.size()-1<<"\n";
	for(int i=1;i<sol.size();i++)
		cout<<sol[i-1]<<" "<<sol[i]<<endl;
	return 0;
}