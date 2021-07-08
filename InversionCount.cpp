#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define int long long int 
const int MOD = 1e9 + 7;
int bit[200001];
void update(int i, int x)
{
	for (;i<200001;i += (i&(-i)))
	{
		bit[i]+=x;
	}
}
int sum(int i)
{
	int ans=0;
	for (;i>0;i-=(i&(-i)))
	{
		ans+=bit[i];
	}
	return ans;
}
void solve()
{
	memset(bit,0,sizeof(bit));
	int n;
	cin>>n;
	vector<int> nums(n+1);
	for (int i=1;i<=n;i++)
	{
		cin>>nums[i];
	}
	map<int,int> mp;
	for (int i=1;i<=n;i++)
	{
		mp[nums[i]];
	}
	int count=1;
	for (auto &i:mp)
	{
		i.second=count;
		count++;
	}
	for (int i=1;i<=n;i++)
	{
		nums[i]=mp[nums[i]];
	}
	int res=0;
	for (int i=1;i<=n;i++)
	{
		res+=(sum(20000)-sum(nums[i]));
		update(nums[i],1);
	}
	cout<<res<<"\n";
}
int32_t main()
{
	IOS;
	solve();
	return 0;
}
