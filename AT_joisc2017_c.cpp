#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int seq[100005];
int a[100005];
int n,k,t;
int check(int now){
  for(int i=1;i<=n;i++){
    a[i]=seq[i]-2*now*t*i;
  }
  if(a[1]<a[n]){
    return 0;
  }
  int mn=k;
  for(int i=k-1;i>=1;i--){
    if(a[i]>=a[mn]){
      mn=i;
    }
  }
  int mx=k;
  for(int i=k+1;i<=n;i++){
    if(a[i]<=a[mx]){
      mx=i;
    }
  }
  int l=k,r=k;
  while(l!=mn||r!=mx){
    bool ok=0;
    int nwl=l,nwr=r;
    while(nwl>mn&&a[nwl-1]>=a[r]){
      nwl--;
      if(a[nwl]>=a[l]){
        break;
      }
    }
    if(nwl<l&&a[l]<=a[nwl]){
      ok=1;
      l=nwl;
    }
    while(nwr<mx&&a[nwr+1]<=a[l]){
      nwr++;
      if(a[nwr]<=a[r]){
        break;
      }
    }
    if(nwr>r&&a[nwr]<=a[r]){
      ok=1;
      r=nwr;
    }
    if(!ok){
      return 0;
    }
  }
  l=1;
  r=n;
  while(l!=mn||r!=mx){
    bool ok=0;
    int nwl=l,nwr=r;
    while(nwl<mn&&a[nwl+1]>=a[r]){
      nwl++;
      if(a[nwl]>=a[l]){
        break;
      }
    }
    if(nwl>l&&a[l]<=a[nwl]){
      ok=1;
      l=nwl;
    }
    while(nwr>mx&&a[nwr-1]<=a[l]){
      nwr--;
      if(a[nwr]<=a[r]){
        break;
      }
    }
    if(nwr<r&&a[nwr]<=a[r]){
      ok=1;
      r=nwr;
    }
    if(!ok){
      return 0;
    }
  }
  return 1;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  k=read();
  t=read();
  for(int i=1;i<=n;i++){
    seq[i]=read();
  }
  int l=0,r=0x3f3f3f3f;
  int ans;
  while(l<=r){
    int mid=(l+r)/2;
    if(check(mid)){
      ans=mid;
      r=mid-1;
    }else{
      l=mid+1;
    }
  }
  printf("%lld\n",ans);
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
