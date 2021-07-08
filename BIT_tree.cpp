#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define int long long int 
const int MOD = 1e9 + 7;
int bit[100001];
void update(int i, int x)
{
	for (;i<100001;i += (i&(-i)))
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
	int n,m;
	cin>>n>>m;
	vector<int> nums(n+1);
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		nums[i]=x;
		update(i,x);
	}
	while(m--)
	{
		int op;
		cin>>op;
		if (op==2)
		{
			int l,r;
			cin>>l>>r;
			l+=1;
			r+=1;
			cout<<(sum(r-1)-sum(l-1))<<"\n";
		}
		else
		{
			int i,v;
			cin>>i>>v;
			i+=1;
			int temp=v-nums[i];
			nums[i]=v;
			update(i,temp);
		}
	}
	
}
int32_t main()
{
	IOS;
	solve();
	return 0;
}
