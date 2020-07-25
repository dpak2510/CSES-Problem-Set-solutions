#include<bits/stdc++.h>
using namespace std;
 
int n, m, x, v;
bool flag;
vector<int> grp[100001], vis(100001);
stack<int> stk;
 
void dfs(int src)
{
	for( int i=0 ; i<grp[src].size() ; i++)
	{
		int u = grp[src][i];
		if(!vis[u])
		{
			vis[u] = 1;
			dfs(u);
			vis[u] = 2;
			stk.push(u);
		}
		else if(vis[u]==1)
			flag = 1;
	}
}
 
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>x>>v, grp[x].push_back(v);
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i] = 1;
			dfs(i);
			vis[i] = 2;
			stk.push(i);
		}
	if(flag)
		cout<<"IMPOSSIBLE\n";
	else
		while(!stk.empty())
			cout<<stk.top()<<" ", stk.pop();
	return 0;
}