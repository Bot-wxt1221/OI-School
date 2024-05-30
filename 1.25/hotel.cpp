#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define mod 1000000007
#define inv2 500000004
inline int read();
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int temp(pow(x,y/2));
    return (temp*temp)%mod;
  }
  return (pow(x,y-1)*x)%mod;
}
class node{
  public:
    int l,r;
    int id;
    node(int x,int y,int z){
      l=x;
      r=y;
      id=z;
      return ;
    }
};
bool operator< (node x,node y){
  return x.l>y.l;
}
class tim{
  public:
    std::vector<node>bef;
    int l=2000000000;
    int gnow;
}aa[300005];
int kk[300005];
int add[300005];
int plu[300005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("hotel.in","r",stdin);
	freopen("hotel.out","w",stdout);
	#endif
  int Q=read();
  int g=0;
  int now=1;
  int curadd=0;
  int pp=1;
  int lstgggg=0;
  kk[g]=0x3f3f3f3f;
  plu[g]=1;
  while(Q--){
    int op=read();
    switch(op){
      case 1:{
        int k=read();
        g++;
        kk[g]=k;
        if(k==0){
          pp*=2;
          curadd*=2;
          curadd%=mod;
          pp%=mod;
          aa[now].gnow=g;
          now++;
        }else{
          lstgggg=g;
          curadd+=k;
          curadd%=mod;
          aa[now].bef.push_back(node(aa[now].l-k,aa[now].l-1,g));
          aa[now].l-=k;
        }
        add[g]=mod-curadd;
        plu[g]=pow(pp,mod-2);
        break;
      }
      case 2:{
        int g=read();
        int x=read();
        if(kk[g]==0){
          x=2*x-1;
        }else{
          x--;
        }
        x%=mod;
        x*=pp;
        x%=mod;
        x*=plu[g];
        x%=mod;
        x+=curadd;
        x%=mod;
        x+=((add[g]*pp)%mod*plu[g])%mod;
        x%=mod;
        printf("%lld\n",x);
        break;
      }
      case 3:{
        int x=read();
        if(x==0){
          printf("%lld\n",lstgggg);
          break;
        }
        int nw=now;
        bool yes=0;
        auto idd=std::lower_bound(aa[nw].bef.begin(),aa[nw].bef.end(),node(aa[nw].l+x,0,0));
          if(aa[nw].bef.size()>0&&idd!=aa[nw].bef.end()&&(*idd).l-aa[nw].l<=x&&x<=(*idd).r-aa[nw].l&&(*idd).id!=0){
            printf("%lld\n",(*idd).id);
            yes=1;
          }
        if(aa[nw].bef.size()>0)
          x-=2000000000-aa[nw].bef[aa[nw].bef.size()-1].l;
        while(nw&&yes==0){
          nw--;
          if(x%2==1){
            printf("%lld\n",aa[nw].gnow);
            yes=1;
            break;
          }else{
            x/=2;
          auto idd=std::lower_bound(aa[nw].bef.begin(),aa[nw].bef.end(),node(aa[nw].l+x,0,0));
          if(aa[nw].bef.size()>0&&idd!=aa[nw].bef.end()&&(*idd).l-aa[nw].l<=x&&x<=(*idd).r-aa[nw].l&&(*idd).id!=0){
            printf("%lld\n",(*idd).id);
            yes=1;
          }
            if(aa[nw].bef.size()>0)
              x-=2000000000-aa[nw].bef[aa[nw].bef.size()-1].l;
            }
        }
        if(!yes){
          printf("0\n");
        }
        break;
      }
    }
  }
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


