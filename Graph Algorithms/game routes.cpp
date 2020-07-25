#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mod 1000000007
 
ll n, m, u, v;
vector<ll> grp[100001], dp(100001,-1);
 
ll dfs(int src)
{
	if(dp[src]!=-1)
		return dp[src];
	ll sum=0;
	for( int i=0 ; i<grp[src].size() ; i++ )
	{
		int u = grp[src][i];
		sum = (sum+dfs(u))%mod;
	}
	return dp[src] = sum;
}
 
int main()
{
	cin>>n>>m;
	for(ll i=0;i<m;i++)
		cin>>u>>v, grp[u].push_back(v);
	dp[n] = 1;
	cout<<dfs(1)<<endl;
	return 0;
}