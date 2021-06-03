#include <bits/stdc++.h>
using namespace std;
const int MAX=10001;
const int LOG=14;
vector<int> children[MAX];
int up[MAX][LOG];
int depth[MAX];
void dfs(int a)
{
	for (int b:children[a])
	{
		depth[b]=depth[a]+1;
		up[b][0]=a;
		for (int j=1;j<LOG;j++)
		{
			up[b][j]=up[up[b][j-1]][j-1];
		}
		dfs(b);
	}
}
int LCA(int x,int y)
{
	if (depth[x]<depth[y])
	{
		swap(x,y);
	}
	int k=depth[x]-depth[y];
	for (int j=LOG-1;j>=0;j--)
	{
		if (k&(1<<j))
		{
			x=up[x][j];
		}
	}
	if (x==y) return x;
	for (int j=LOG-1;j>=0;j--)
	{
		if (up[x][j]!=up[y][j])
		{
			x=up[x][j];
			y=up[y][j];
		}
	}
	return up[x][0];
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int count;
		cin>>count;
		for (int j=0;j<count;j++)
		{
			int x;
			cin>>x;
			children[i].push_back(x);
		}
	}
	dfs(0);
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<LCA(x,y)<<"\n";
	}
	return 0;
}
