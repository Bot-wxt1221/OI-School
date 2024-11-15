#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define int long long
inline int read();
int n,m;
int a[305];
int x[305];
int b[305];
int y[305];
int dp[(1<<22)+5];
std::queue<int>qu;
bool sure[25];
int ans[25];
int iii;
int fir[605];
int nxt[605];
int v[605];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int getans(int ii){
  while(qu.size()>0){
    int tp=qu.front();
    qu.pop();
    for(int iii=fir[tp];iii!=-1;iii=nxt[iii]){
      int i=v[iii];
      if(((1<<(a[i]-1))&ii)==0||(((1<<(b[i]-1))&ii)==0)){
        continue;
      }
      if(a[i]==tp){
        if(x[i]==ans[tp]){
          if(sure[b[i]]){
            if(ans[b[i]]==y[i]){
              return -1;
            }
          }else if(y[i]!=2){
            sure[b[i]]=1;
            ans[b[i]]=!y[i];
            qu.push(b[i]);
          }
        }
      }else{
        if(y[i]==ans[tp]){
          if(sure[a[i]]){
            if(ans[a[i]]==x[i]){
              return -1;
            }
          }else if(x[i]!=2){
            sure[a[i]]=1;
            ans[a[i]]=!x[i];
            qu.push(a[i]);
          }
        }
      }
    }
  }
  int ret=0;
  for(int i=1;i<=n;i++){
    if(sure[i]){
      ret|=(1<<(i-1));
    }
  }
  return ret^ii;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  m=read();
  memset(fir,-1,sizeof(fir));
  for(int i=1;i<=m;i++){
    a[i]=read();
    x[i]=read();
    b[i]=read();
    y[i]=read();
    add(a[i],i);
    add(b[i],i);
  }
  for(int i=1;i<=n;i++){
    dp[(1<<(i-1))]=2;
  }
  dp[0]=1;
  for(int i=1;i<(1<<n);i++){
    int lst=0,siz=0;
    for(int j=1;j<=n;j++){
      if((1<<(j-1))&i){
        siz++;
        lst=j;
      }
    }
    if(siz==1){
      continue;
    }
    for(int color=0;color<=1;color++){
      memset(sure,0,sizeof(sure));
      sure[lst]=1;
      ans[lst]=color;
      qu=std::queue<int>();
      qu.push(lst);
      int ret=getans(i);
      if(ret!=-1){
        dp[i]+=dp[ret];
      }
    }
  }
  int ans=0;
  for(int i=0;i<(1<<n);i++){
    iii=i;
    memset(sure,0,sizeof(sure));
    qu=std::queue<int>();
    for(int j=1;j<=n;j++){
      if((1<<(j-1))&i){
        sure[j]=1;
        ::ans[j]=2;
        qu.push(j);
      }
    }
    int ret=getans((1<<(n))-1);
    if(ret!=-1){
      ans+=dp[ret];
    }
  }
  printf("%lld",ans);
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
