#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
inline int read();
int a[100005];
int b[100005];
int c[100005];
std::pair<int,int>tt[100005];
int tree[200005];
int lowbit(int a){
    return a&-a;
}
void add(int a,int i){
  a+=2;
    while(a<=200002){
        tree[a]+=i;
        a+=lowbit(a);
    }
    return ;
}
int query(int a){
  a+=2;
    int ans=0;
    while(a>0){
        ans+=tree[a];
        a-=lowbit(a);
    }
    return ans;
}

namespace cdq{
class node{
    public:
        int a,b,c;
        int cnt;
        int i;
        node(int aa=0,int bb=0,int cc=0){
            a=aa;
            b=bb;
            c=cc;
            return ;
        }
}a[1000005],tem[1000005];
int cnt2[1000005];
int end[1000005];
int f[1000005];
int ans;
int ans1[100005];
bool cmp(node a,node b){
    if(a.a!=b.a){
        return a.a<b.a;
    }
    if(a.b!=b.b){
        return a.b<b.b;
    }
    return a.c<b.c;
}
void cdq(int l,int r){
    if(l>=r){
        return ;
    }
    int mid=(l+r)/2;
    cdq(l,mid);
    cdq(mid+1,r);
    int ii1=l,ii2=mid+1;
    int da=l-1;
    while(ii1<=mid&&ii2<=r){
        if(a[ii1].b<=a[ii2].b){
            add(a[ii1].c,a[ii1].cnt);
            tem[++da]=a[ii1];
            ii1++;
        }else{
      int ret=query(a[ii2].c);
            ans+=ret;
      ans1[a[ii2].i]+=ret;
            tem[++da]=a[ii2];
            ii2++;
        }
    }
    while(ii1<=mid){
        add(a[ii1].c,a[ii1].cnt);
        tem[++da]=a[ii1];
        ii1++;
    }
    while(ii2<=r){
      int ret=query(a[ii2].c);
            ans+=ret;
      ans1[a[ii2].i]+=ret;
        tem[++da]=a[ii2];
        ii2++;
    }
 for(int i=l;i<=mid;i++){
        add(a[i].c,-a[i].cnt);
    }
    for(int i=l;i<=r;i++){
        a[i]=tem[i];
    }
    return ;
}
};
int solve(int *a,int *b,int n){
  for(int i=1;i<=n;i++){
    tt[i]={a[i],b[i]};
  }
  std::sort(tt+1,tt+n+1);
  int ans=0;
  for(int i=1;i<=n;i++){
    int ttt=query(tt[i].second);
    ans+=ttt*(ttt-1)/2;
    add(tt[i].second,1);
  }
  for(int i=1;i<=n;i++){
    add(tt[i].second,-1);
  }
  return ans;
}

signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
      b[i]=read();
      c[i]=read();
      cdq::a[i].a=a[i];
      cdq::a[i].b=b[i];
      cdq::a[i].c=c[i];
      cdq::a[i].i=i;
      cdq::a[i].cnt=1;
      cdq::ans1[i]=0;
    }
    int ans=n+(n*(n-1))/2;
    ans+=(n*(n-1)*(n-2))/6;
    cdq::ans=0;
    std::sort(cdq::a+1,cdq::a+n+1,cdq::cmp);
    cdq::cdq(1,n);
    ans-=cdq::ans;
    ans-=solve(a,b,n);
    ans-=solve(a,c,n);
    ans-=solve(b,c,n);
    for(int i=1;i<=n;i++){
      ans+=(cdq::ans1[i]*(cdq::ans1[i]-1));
    }
    printf("%lld\n",ans);
  }
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
