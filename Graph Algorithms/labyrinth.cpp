#include<bits/stdc++.h>
using namespace std;
 
int n,m,vis[1000][1000], stat, par[1000001], sr, sc;
vector<char> v;
char ds[1000001];
string mat[1000];
queue<int> q;
 
void bfs(int i,int j)
{
	int cnt=0;
	q.push(i);
	q.push(j);
	vis[i][j] = 1;
	q.push(-1), q.push(-1);
	par[i*m+j] = -1;
	while(!q.empty())
	{
		int r = q.front(); q.pop();
		int c = q.front(); q.pop();
		if( r == -1 )
		{
			cnt++;
			if(q.size()==0)
				break;
			q.push(-1), q.push(-1);
			continue;
		}
		if(mat[r][c] == 'B')
		{
			stat = 1, sr = r, sc=c;
			return;
		}
		if(r+1<n && (mat[r+1][c] == '.' || mat[r+1][c] == 'B') && !vis[r+1][c])
		{
			vis[r+1][c] = 1;
			q.push(r+1), q.push(c);
			par[(r+1)*m+c] = r*m+c;
			ds[(r+1)*m+c] = 'D';
		}
		if(r-1>=0 && (mat[r-1][c] == '.' || mat[r-1][c] == 'B') && !vis[r-1][c])
		{
			vis[r-1][c] = 1;
			q.push(r-1), q.push(c);
			par[(r-1)*m+c] = r*m+c;
			ds[(r-1)*m+c] = 'U';
		}
		if(c+1<m && (mat[r][c+1] == '.' || mat[r][c+1] == 'B') && !vis[r][c+1])
		{
			vis[r][c+1] = 1;
			q.push(r), q.push(c+1);
			par[(r)*m+(c+1)] = r*m+c;
			ds[(r)*m+(c+1)] = 'R';
		}
		if(c-1>=0 && (mat[r][c-1] == '.' || mat[r][c-1] == 'B') && !vis[r][c-1])
		{
			vis[r][c-1] = 1;
			q.push(r), q.push(c-1);
			par[(r)*m+(c-1)] = r*m+c;
			ds[(r)*m+(c-1)] = 'L';
		}
	}
}
 
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>mat[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j] == 'A')
			{
				bfs(i,j);
				break;
			}
	if(stat)
	{
		stack<char> stk;
		int tmp = sr*m+sc;
		while(par[tmp]>=0)
		{
			stk.push(ds[tmp]), tmp=par[tmp];
		}
		cout<<"YES\n"<<stk.size()<<endl;
		while(!stk.empty()) cout<<stk.top(), stk.pop();
	}
	else
		cout<<"NO\n";
}