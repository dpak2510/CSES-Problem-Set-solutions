#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pr pair<int,int>

int n, m;
vector<vector<int>> vis(1001, vector<int> (1001,10000001));
vector<string> mat(1001);
queue<pr> q;
deque<char> qu;

void dfs(int i, int j, int val)
{
	vis[i][j]=0;
	if(i==n-1 || j==m-1 || i==0 || j==0)
	{
		cout<<"YES\n"<<qu.size()<<"\n";
		while(!qu.empty())
			cout<<qu.front(), qu.pop_front();
		exit(0);
	}
	if(i+1<n && vis[i+1][j]>val+1 && mat[i+1][j]=='.')
		qu.push_back('D'), dfs(i+1,j,val+1), qu.pop_back();
	if(j+1<m && vis[i][j+1]>val+1 && mat[i][j+1]=='.')
		qu.push_back('R'), dfs(i,j+1,val+1), qu.pop_back();
	if(i-1>=0 && vis[i-1][j]>val+1 && mat[i-1][j]=='.')
		qu.push_back('U'), dfs(i-1,j,val+1), qu.pop_back();
	if(j-1>=0 && vis[i][j-1]>val+1 && mat[i][j-1]=='.')
		qu.push_back('L'), dfs(i,j-1,val+1), qu.pop_back();
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>mat[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j] == 'M') q.push(mp(i,j)), vis[i][j] = 1;
	while(!q.empty())
	{
		pr cur = q.front();
		q.pop();
		int i=cur.first, j=cur.second;
		if(i+1<n && vis[i+1][j]==10000001 && mat[i+1][j]!='#' && mat[i+1][j]!='M')
			vis[i+1][j] = vis[i][j] + 1, q.push(mp(i+1,j));
		if(j+1<m && vis[i][j+1]==10000001 && mat[i][j+1]!='#' && mat[i][j+1]!='M')
			vis[i][j+1] = vis[i][j] + 1, q.push(mp(i,j+1));
		if(i-1>=0 && vis[i-1][j]==10000001 && mat[i-1][j]!='#' && mat[i-1][j]!='M')
			vis[i-1][j] = vis[i][j] + 1, q.push(mp(i-1,j));
		if(j-1>=0 && vis[i][j-1]==10000001 && mat[i][j-1]!='#' && mat[i][j-1]!='M')
			vis[i][j-1] = vis[i][j] + 1, q.push(mp(i,j-1));
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j]=='A')
				dfs(i,j,1);
	cout<<"NO\n";
	return 0;
}
