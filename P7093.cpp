#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int seq[10005];
int sum[10005];
int a[1005][(1<<14)+5];
int high[(1<<14)+5];
int n;
inline int merge(int l,int r,int add){
  if(high[l]>high[r]){
    int t=high[l];
    l-=t;
    r+=t;
  }
  if(l&&(l&(-l))<add){
    return -1;
  }
  l+=add;
  if(high[l]==high[r]){
    int t=high[l];
    l+=t;
    r-=t;
  }
  return l;
}
int T;
bool ans[10005];
bool dfs(int now,int lf){
  int rf=sum[now]-lf;
  if(high[lf]==high[rf]&&high[lf]>0){
    lf+=high[lf];
  }else if(high[lf]<high[rf]){
    lf+=high[rf];
  }
  rf=sum[now]-lf;
  if(now==n){
    if(lf==0||lf==sum[now]||lf==sum[now]-lf){
      return 1;
    }
    return 0;
  }
  if(a[now][lf]!=0){
    return a[now][lf]-1;
  }
  a[now][lf]=1;
  if(seq[now+1]<=(lf&(-lf))||lf==0){
    if(dfs(now+1,lf+seq[now+1])){
      a[now][lf]=2;
      ans[now]=0;
      return 1;
    }
  }
  if(seq[now+1]<=(rf&(-rf))||rf==0){
    int ret=dfs(now+1,lf);
    if(ret){
      a[now][lf]=2;
      ans[now]=1;
      return 1;
    }
  }
  return 0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  T=read();
  for(int i=1;i<(1<<14);i++){
    if((i&(-i))==i){
      high[i]=i;
    }else{
      high[i]=high[i-1];
    }
  }
  while(T--){
    n=read();
    for(int i=1;i<=n;i++){
      seq[i]=read();
      sum[i]=sum[i-1]+seq[i];
    }
  if (sum[n]!=(sum[n]&(-sum[n]))) {puts("no");continue;}
    for(int i=0;i<=n;i++){
      for(int j=0;j<=sum[n];j++){
        a[i][j]=0;
      }
    }
    int ret=dfs(0,0);
    if(ret==0){
      printf("no\n");
    }else{
      for(int j=0;j<n;j++){
        if(ans[j]){
          putchar('r');
        }else{
          putchar('l');
        }
      }
      putchar('\n');
    }
  }
  return 0;
}
inline int read(){
  int d;
  scanf("%d",&d);
  return d;
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


