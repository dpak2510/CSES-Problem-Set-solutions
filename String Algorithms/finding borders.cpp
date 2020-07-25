#include<bits/stdc++.h>
using namespace std;

string str;
int arr[1000001], x, y;
set<int> st;

int main()
{
	cin>>str;
	for(int i=1, j;i<str.size();i++)
	{
		if(i>y)
		{
			x = y = i;
			y--;
			j=0;
			while( y<str.size()-1 && str[y+1]==str[j] ) y++, j++;
			arr[i] = y-x+1;
		}
		else if(arr[i-x]+i > y)
		{
			x = i;
			j = y-x+1;
			while( y<str.size()-1 && str[y+1]==str[j]) y++, j++;
			arr[i] = y-x+1;
		}
		else arr[i] = arr[i-x];
	}
	for(int i=0;i<str.size();i++)
		if(arr[i]+i == str.size())
			st.insert(arr[i]);
	for( auto u : st )
		cout<<u<<" ";
	cout<<"\n";
	return 0;
}
