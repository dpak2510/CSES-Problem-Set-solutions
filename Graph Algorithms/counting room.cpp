#include<bits/stdc++.h>
using namespace std;
 
int n, m, cnt, vis[1000][1000];
string mat[1000];
 
void dfs(int i, int j)
{
	vis[i][j] = 1;
	if(i+1<n && mat[i+1][j] != '#' && !vis[i+1][j]) dfs(i+1,j);
	if(i-1>=0 && mat[i-1][j] != '#' && !vis[i-1][j]) dfs(i-1,j);
	if(j+1<m && mat[i][j+1] != '#' && !vis[i][j+1]) dfs(i,j+1);
	if(j-1>=0 && mat[i][j-1] != '#' && !vis[i][j-1]) dfs(i,j-1);
}
 
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>mat[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j] == '.' && !vis[i][j])
			{
				cnt++;
				dfs(i,j);
			}
	cout<<cnt<<endl;
}