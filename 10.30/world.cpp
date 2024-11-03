#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
inline int read();
int a[1000005];
int b[1000005];
int seqq[1000005];
int cnttt;
int tme[1000005];
int lstans[1000005];
int cntt[1000005];
int seq[1000005];
int ans[1000005];
int cnt;
int bigger=0,sum=0;
int cur;
int curcnt;
int tottime;
int presum;
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[1000005];
  void add(int x,int y){
    x++;
    while(x<=1000002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
  int query(int now){
    now++;
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
}A,B,C;
int check(int curcnt){
  int sum=B.query(curcnt-1);
  int ret=C.query(1000000)-C.query(curcnt-1);
  int ret2=A.query(1000000)-A.query(curcnt-1);
  sum+=(ret*seq[curcnt]*seq[curcnt]);
  sum+=ret2-ret*seq[curcnt];
  return sum;
}
int check(int curcnt,int sum,int ret,int ret2){
  return sum+ret*curcnt*curcnt+ret2-ret*curcnt;
}
int check3(int curcnt,int mid){
  return mid*((curcnt+1)*(curcnt+1)-curcnt*curcnt)-mid;
}
int check2(int curcnt,int sum,int anssum,int ret,int tp){
  int l=0,r=ret;
  while(r-l>3){
    int mid=(l+r)/2;
    if(check3(curcnt,mid)+sum<=tp){
      l=mid;
    }else{
      r=mid;
    }
  }
  for(int i=r;i>=l;i--){
    if(check3(curcnt,i)+sum<=tp){
      return anssum-i;
    }
  }
  return 114514;
}
int getans(int curcnt,int tp){
  int sum=B.query(curcnt);
  int ret=C.query(1000000)-C.query(curcnt);
  int ret2=A.query(1000000)-A.query(curcnt);
  int l=seq[curcnt];
  int r=seq[curcnt+1];
  while(r-l>3){
    int mid=(l+r)/2;
    if(check(mid,sum,ret,ret2)>tp){
      r=mid;
    }else{
      l=mid;
    }
  }
  for(int i=r;i>=l;i--){
    if(check(i,sum,ret,ret2)<=tp){
      return check2(i,check(i,sum,ret,ret2),ret2-ret*i,ret+(i==seq[curcnt]?(C.query(curcnt)-C.query(curcnt-1)):0),tp);
    }
  }
  return 114514;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("world.in","r",stdin);
	freopen("world.out","w",stdout);
	#endif
  int n=read();
  int k=read();
  for(int i=1;i<=n;i++){
    ans[i]=0x3f3f3f3f3f3f3f3f;
    a[i]=read();
    seqq[++cnttt]=a[i];
    b[i]=a[i];
  }
  std::sort(seqq+1,seqq+cnttt+1);
  cnttt=std::unique(seqq+1,seqq+cnttt+1)-seqq-1;
  for(int i=2;i<=n;i++){
    if(b[i]>=b[i-1]){
      b[i]=b[i-1];
    }else{
      seq[++cnt]=b[i-1]-b[i];
    }
  }
  std::sort(seq+1,seq+cnt+1);
  cnt=std::unique(seq+1,seq+cnt+1)-seq-1;
  seq[++cnt]=0x3f3f3f3f;
  curcnt=cnt-1;
  tottime=0;
  for(int i=2;i<=n;i++){
    tottime++;
    if(a[i]>a[i-1]){
      a[i]=a[i-1];
      tottime++;
      tme[i]=-1;
    }else if(a[i]<a[i-1]){
      int ret=k-a[i];
      int curr=a[i-1]-a[i];
      A.add(std::lower_bound(seq+1,seq+cnt+1,curr)-seq,curr);
      B.add(std::lower_bound(seq+1,seq+cnt+1,curr)-seq,curr*curr);
      C.add(std::lower_bound(seq+1,seq+cnt+1,curr)-seq,1);
      cntt[std::lower_bound(seq+1,seq+cnt+1,curr)-seq]++;
      if(curr>cur){
        bigger++;
        sum+=curr;
      }
      while(check(curcnt)>ret){
        curcnt--;
      }
      tme[i]=getans(curcnt,ret)+tottime+a[i];
    }else{
      tme[i]=getans(curcnt,k-a[i])+tottime+a[i];
    }
  }
  tme[1]=a[1];
  int mn=0x3f3f3f3f3f3f3f3f;
  for(int i=1;i<=n;i++){
    a[i]=std::lower_bound(seqq+1,seqq+cnttt+1,a[i])-seqq;
    if(tme[i]!=-1){
      mn=std::min(mn,tme[i]-i*2);
    }
    ans[i]=std::min(ans[i],mn+i*2);
  }
  mn=0x3f3f3f3f3f3f3f3f;
  for(int i=n;i>=1;i--){
    if(tme[i]!=-1){
      mn=std::min(mn,tme[i]+i*2);
    }
    ans[i]=std::min(ans[i],mn-i*2);
  }
  for(int i=1;i<=n;i++){
    printf("%lld ",ans[i]);
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
