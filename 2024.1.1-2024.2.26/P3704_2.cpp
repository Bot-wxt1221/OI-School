#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;typedef unsigned long long ll;ll mod=1e9+7;const int N=1e6+10;
inline ll po(ll a,ll p){ll r=1;for(;p;p>>=1,a=(a*a)%mod){if(p&1){r=(r*a)%mod;}}return r;}
int t;int miu[N];int zhi[N];bool book[N];int cnt;ll f[N];ll prp[N];int sn;int sm;int n=1e6;
int main()
{
	f[1]=1;f[2]=1;for(int i=3;i<=n;i++){f[i]=(f[i-1]+f[i-2])%mod;}miu[1]=1;//打表fibonacci数列 
	for(int i=2;i<=n;i++)//线性筛筛miu函数 
	{
		if(book[i]==false){miu[i]=-1,zhi[++cnt]=i;}
		for(int j=1;j<=cnt&&zhi[j]*i<=n;j++)
		{
			book[i*zhi[j]]=true;
			if(i%zhi[j]==0){miu[i*zhi[j]]=0;break;}
			else {miu[i*zhi[j]]=miu[i]*miu[zhi[j]];}
		}
	}for(int i=0;i<=n;i++){prp[i]=1;}//处理前缀积 
	for(int i=1;i<=n;i++)
	{
		ll inv=po(f[i],mod-2);//这里一定先把-1次幂处理出来，不然复杂度多个log 
		for(int j=i;j<=n;j+=i)//枚举约数太慢换成枚举倍数了，自己就是倍数的约数 
		{	
			if(miu[j/i]==-1){prp[j]*=inv;prp[j]%=mod;}//这样写似乎常数最小？ 
			else if(miu[j/i]==1){prp[j]*=f[i];prp[j]%=mod;} 
		}
	}for(int i=1;i<=n;i++){prp[i]*=prp[i-1];prp[i]%=mod;}//前缀积 
	scanf("%d",&t);
	for(int z=1;z<=t;z++)
	{
		scanf("%d%d",&sn,&sm);int p;ll res=1;
		for(int i=1;i<=min(sn,sm);i=p+1)//这里是数论分块的板子 
		{
			p=min(sn/(sn/i),sm/(sm/i));//像这样的话[i,p]内的值，(n/i)*(m/i)都是一样的 
			res=res*po(prp[p]*po(prp[i-1],mod-2)%mod,(ll)(sn/i)*(ll)(sm/i))%mod;
		}printf("%lld\n",res);
	}return 0;//拜拜程序~ 
}
