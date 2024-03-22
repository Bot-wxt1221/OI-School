#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
inline int read();
int a[100005];
int l[18][18][100005];
int r[18][18][100005];
int llg[100005];
inline int getr1(int l,int r,int k){
  int lg=::llg[r-l+1];
  return std::max(::r[k][lg][l],::r[k][lg][r-(1<<lg)+1]);
}
inline int getl1(int l,int r,int k){
  int lg=::llg[r-l+1];
  return std::min(::l[k][lg][l],::l[k][lg][r-(1<<lg)+1]);
}
int n;
int ll[100005];
int rr[100005];
bool check(int k){
  for(int i=1;i<=n;i++){
    ll[i]=i;
    rr[i]=i;
    int tk=k;
    int kk=0;
    while(tk){
      if((tk&1)==0){
        tk>>=1;
        kk++;
        continue;
      }
      int tl=ll[i];
      int tr=rr[i];
      rr[i]=getr1(tl,tr,kk);
      ll[i]=getl1(tl,tr,kk);
      tk>>=1;
      kk++;
    }
  }
  for(int i=n-1;i>=1;i--){
    ll[i]=std::max(ll[i],ll[i+1]);
  }
  for(int i=1;i<=n;i++){
    int min=rr[i];
    if(min+1>n){
      continue;
    }
    int mx=ll[min+1];
    if(i<mx){
      return 1;
    }
  }
  return 0;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("jump.in","r",stdin);
  freopen("jump.out","w",stdout);
  #endif
  n=read();
  llg[1]=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=2;i<=n;i++){
    llg[i]=llg[i/2]+1;
  }
  for(int i=1;i<=n;i++){
    l[0][0][i]=std::max(i-a[i],1);
    r[0][0][i]=std::min(i+a[i],n);
  }
  for(int kk=1;kk<=17;kk++){
    for(int k=1;k<=17;k++){
      for(int i=1;i<=n&&(i+(1<<(k-1)))<=n;i++){
        l[kk-1][k][i]=std::min(l[kk-1][k-1][i],l[kk-1][k-1][i+(1<<(k-1))]);
        r[kk-1][k][i]=std::max(r[kk-1][k-1][i],r[kk-1][k-1][i+(1<<(k-1))]);
      }
    }
    for(int i=1;i<=n;i++){
      l[kk][0][i]=getl1(l[kk-1][0][i],r[kk-1][0][i],kk-1);
      r[kk][0][i]=getr1(l[kk-1][0][i],r[kk-1][0][i],kk-1);
    }
  }
  int kk=18;
  for(int k=1;k<=17;k++){
    for(int i=1;i<=n&&(i+(1<<(k-1)))<=n;i++){
      l[kk-1][k][i]=std::min(l[kk-1][k-1][i],l[kk-1][k-1][i+(1<<(k-1))]);
      r[kk-1][k][i]=std::max(r[kk-1][k-1][i],r[kk-1][k-1][i+(1<<(k-1))]);
    }
  }
  int l=1,r=n;
  while(r-l>3){
    int mid=(l+r)/2;
    if(check(mid)){
      l=mid;
    }else{
      r=mid;
    }
  }
  for(int i=l;i<=r;i++){
    if(!check(i)){
      printf("%d",i);
      return 0;
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


