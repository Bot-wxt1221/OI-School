#include <iostream>
#include <cstdio>
#include <queue>
#define int __int128
#define mod 1000000007
inline int read();
int a[500005];
int b[500005];
int w[500005];
int fir[500005];
int v[1000005];
int nxt[1000005];
int ans[1000005];
int rans[1000005];
int now;
int len[1000005];
int p[1000005];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int pow(int x,int y){
  int ans=1;
  while(y){
    if(y&1){
      ans*=x;
      ans%=mod;
    }
    x*=x;
    x%=mod;
    y>>=1;
  }
  return ans;
}
void dfs(int now,int fa){
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    len[v[i]]=len[now]+1;
    dfs(v[i],now);
  }
  return ;
}
void dfs2(int now,int fa){
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    len[v[i]]=1;
    dfs(v[i],now);
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("sugar.in","r",stdin);
	freopen("sugar.out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
      fir[i]=-1;
    }
    for(int i=1;i<=n;i++){
      b[i]=read();
    }
    for(int i=1;i<=n;i++){
      w[i]=read();
    }
    now=0;
    for(int i=1;i<=n;i++){
      if(a[i]>a[b[i]]+w[b[i]]){//have
        rans[i]=a[i]+w[i];
        ans[i]=2;
      }else if(a[i]>a[b[i]]){
        add(b[i],i);
        ans[i]=0;
      }else{
        rans[i]=a[i];
        ans[i]=1;
      }
    }
    for(int i=1;i<=n;i++){
      if(a[i]>a[b[i]]+w[b[i]]){
        len[i]=1;
        dfs(i,i);
      }else if(a[i]<=a[b[i]]){
        dfs2(i,i);
      }
    }
    p[1]=1;
    p[2]=1;
    for(int i=3;i<=100;i++){
      p[i]=(i-1)*(p[i-1]+p[i-2])%mod;
    }
    std::cerr<<(long long)p[100]<<std::endl;
    int tt=1;
    for(int i=1;i<=n;i++){
      tt*=pow(i,mod-2);
      tt%=mod;
      p[i]*=tt;
      p[i]%=mod;
    }
    for(int i=1;i<=n;i++){
      if(ans[i]){
        printf("%lld ",rans[i]%mod);
      }else{
        printf("%lld ",(p[len[i]]*w[i]%mod+a[i])%mod);
      }
    }
    printf("\n");
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
