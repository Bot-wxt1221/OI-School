#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int mx=0,n;
int dp[30];
class node{
  public:
    int op,x,y,k,z;
    node(int opp=0,int xx=0,int yy=0,int kk=0,int zz=0){
      op=opp;
      x=xx;
      y=yy;
      k=kk;
      z=zz;
      return ;
    }
}a[10005];
bool ans=0;
void dfs(int now){
  if(ans){
    return ;
  }
  if(now==mx){
    for(int i=0;i<26;i++){
      if(dp[i]==n){
        goto nxt;
      }
    }
    return ;
    nxt:{};
    printf("%d\n",mx);
    for(int i=0;i<now;i++){
      if(a[i].op==1){
        printf("lea e%cx, [e%cx]\n",a[i].x,a[i].y);
      }
      if(a[i].op==2){
        printf("lea e%cx, [e%cx + e%cx]\n",a[i].x,a[i].y,a[i].z);
      }
      if(a[i].op==3){
        printf("lea e%cx, [%d*e%cx]\n",a[i].x,a[i].k,a[i].z);
      }
      if(a[i].op==4){
         printf("lea e%cx, [e%cx + %d*e%cx]\n",a[i].x,a[i].y,a[i].k,a[i].z);      
      }
    }
    ans=1;
    return ;
  }
  for(int i=0;i<=now;i++){
    for(int j=-1;j<=now;j++){
      for(int k=1;k<9;k*=2){
        if(j+1){
          dp[now+1]=dp[i]*k+dp[j];
        }else{
          dp[now+1]=dp[i]*k;
        }
        a[now].x=now+'a'+1;
        a[now].y=j+'a';
        a[now].z=i+'a';
        a[now].k=k;
        if(a[now].y!=-1+'a'){
          a[now].op=4;
        }else{
          a[now].op=3;
        }
        dfs(now+1);
      }
    }
  }
  return ;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  for(int i=0;i<=n;i++){
    mx=i;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dfs(0);
    if(ans){
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


