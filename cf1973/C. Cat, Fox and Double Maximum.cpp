#include <iostream>
#include <cstdio>
inline int read();
int a[100005];
int mod[100005];
int to[100005];
bool yes[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
      to[a[i]]=i;
      yes[i]=0;
      mod[i]=0;
    }
    int ans=0;
    for(int i=n;i>=1;i--){
      if(mod[to[i]+1]||mod[to[i]-1]||to[i]==n||to[i]==1){
        continue;
      }
      ans++;
      mod[to[i]]=ans;
      yes[i]=1;
    }
    int cnt=0;
    for(int i=n;i>=1;i--){
      if(mod[to[i]]==0){
        cnt++;
        mod[to[i]]=cnt;
      }
    }
    for(int i=n;i>=1;i--){
      if(yes[i]){
        mod[to[i]]+=cnt;
      }
    }
    for(int i=1;i<=n;i++){
    //  printf("%d ",mod[i]);
      a[i]+=mod[i];
    }
    ans=0;
    for(int i=2;i<n;i++){
      if(a[i]>a[i-1]&&a[i]>a[i+1]){
        ans++;
      }
    }
    printf("%d",ans);
    printf("\n");
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
