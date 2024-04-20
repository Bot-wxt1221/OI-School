#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define mod 1000000007
inline int read();
class node{
  public:
    int x,y;
    node(int xx=0,int yy=0){
      x=xx;
      y=yy;
      return ;
    }
}aa[1000005];
bool operator < (node a,node b){
  return a.y<b.y;
}
int a[1000005];
int lowbit(int x){
  return x&(-x);
}
void upd(int &a1,int &a2,int &a3,int k){
  if(k>=a1){
    a3=a2;
    a2=a1;
    a1=k;
  }else if(k>=a2){
    a3=a2;
    a2=k;
  }else if(k>=a3){
    a3=k;
  }
  return ;
}
class BIT{
public:
  int tree1[1000005],tree2[1000005],tree3[1000005];
  std::vector<int> query(int now){
    int ans1=0,ans2=0,ans3=0;
    while(now>0){
      upd(ans1,ans2,ans3,tree1[now]);
      upd(ans1,ans2,ans3,tree2[now]);
      upd(ans1,ans2,ans3,tree3[now]);
      now-=lowbit(now);
    }
    return {ans1,ans2,ans3};
  }
  std::vector<int> query(int now,int t){
    int ans1=0,ans2=0,ans3=0;
    while(now>0){
      upd(ans1,ans2,ans3,tree1[now]);
      upd(ans1,ans2,ans3,tree2[now]);
      upd(ans1,ans2,ans3,tree3[now]);
      now-=lowbit(now);
    }
    return {1000004-ans1,1000004-ans2,1000004-ans3};
  }
  void add(int x,int y){
    while(x<=1000003){
      upd(tree1[x],tree2[x],tree3[x],y);
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x){
    while(x<=1000003){
      tree1[x]=tree2[x]=tree3[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}b,c;
std::vector<int> lmn[1000005],lmx[1000005],rmn[1000005],rmx[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    aa[i]=node(i,read());
  }
  std::sort(aa+1,aa+n+1);
  for(int i=1;i<=n;i++){
    a[aa[i].x]=i;
  }
  lmx[0]=lmn[0]=lmx[1000004]=lmn[1000004]={0,0,0};
  rmx[0]=rmn[0]=rmx[1000004]=rmn[1000004]={1000004,1000004,1000004};
  for(int i=1;i<=n;i++){
    lmn[i]=b.query(a[i]);
    lmx[i]=c.query(1000001-a[i]+1);
    b.add(a[i],i);
    c.add(1000001-a[i]+1,i);
  }
  for(int i=1;i<=n;i++){
    b.clear(a[i]);
    c.clear(1000001-a[i]+1);
  }
  for(int i=n;i>=1;i--){
    rmn[i]=b.query(a[i],1);
    rmx[i]=c.query(1000001-a[i]+1,1);
    b.add(a[i],1000003-i+1);
    c.add(1000001-a[i]+1,1000003-i+1);   
  }
  long long tans=0;
  for(int i=1;i<=n;i++){
    int l1=i;
    int l2=lmx[i][0];
    l2=std::max(l2,0);
    int r1=rmx[i][1];
    int r2=rmx[i][2];
    r2=std::min(r2,n+1);
    if(l1<l2||r2<r1){
      
    }else{
      tans+=1ll*(l1-l2)*(r2-r1)%mod*aa[a[i]].y%mod*aa[a[rmx[i][0]]].y%mod*aa[a[r1]].y%mod;
      tans%=mod;
    }
    l1=lmx[i][0];
    r1=rmx[i][0];
    r2=rmx[i][1];
    l2=lmx[i][1];
    r2=std::min(r2,n+1);
    l2=std::max(l2,0);
    if(l1<l2||r2<r1){
      
    }else{
      tans+=1ll*(l1-l2)*(r2-r1)%mod*aa[a[i]].y%mod*aa[a[l1]].y%mod*aa[a[r1]].y%mod;
      tans%=mod;
    }
    l1=lmx[i][1];
    l2=lmx[i][2];
    l2=std::max(l2,0);
    r1=i;
    r2=rmx[i][0];
    r2=std::min(r2,n+1);
    if(l1<l2||r2<r1){
      
    }else{
      tans+=1ll*(l1-l2)*(r2-r1)%mod*aa[a[i]].y%mod*aa[a[lmx[i][0]]].y%mod*aa[a[l1]].y%mod;
      tans%=mod;
    }
  }
  printf("%lld",tans);
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

