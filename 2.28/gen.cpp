#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n = 1e5;
mt19937 mt(time(0));
ll rand(ll l,ll r)
{
	return mt() % (r - l + 1) + l;
}
int main()
{
	freopen("1.in","w",stdout);
	cout<<522<<" "<<n<<" "<<n<<"\n";
	for(int i = 1;i <= n;i++)
		cout<<(1 << rand(0,25))<<" ";
	for(int i = 1;i < n;i++)
		cout<<"1 "<<rand(1,n)<<" "<<(1 << rand(0,25))<<"\n";
	cout<<"2 "<<(1 << rand(0,25))<<endl;
}
