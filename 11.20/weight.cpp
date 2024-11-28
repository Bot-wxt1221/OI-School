#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#define int long long
#define mod 998244353
inline int read();
int fir[300005];
int nxt[600005];
int v[600005];
int w[300005];
int oriw[300005];
int siz[300005];
std::map<int,int> mp[300005][35];
int tt[300005][45];
int now;
int t;
int dfn[300005];
int dfn2[300005];
int lst[300005];
int ans[300005];//orgnize with dfn
int bson[300005];
std::vector<int>seq[45];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void adddis(std::map<int,int> mp2[35],int now,int lcaw){
  for(int i=dfn[now];i<=lst[now];i++){
    int ret=w[dfn2[i]]^lcaw;
    for(int j=0;j<32;j++){
      if((t>>(31-j))&1){
        continue;
      }
      int tt=ret>>(31-j);
      tt^=(t>>(31-j));
      tt^=1;
      ans[i]+=(mp2[j])[tt];
    }
    ans[i]+=(mp2[31])[t^ret];
  }
  for(int i=dfn[now];i<=lst[now];i++){
    for(int j=0;j<32;j++){
      (mp2[j])[w[dfn2[i]]>>(31-j)]++;
    }
  }
  return ;
}
void del(std::map<int,int> mp2[35],int now){
  for(int i=dfn[now];i<=lst[now];i++){
    for(int j=0;j<32;j++){
      (mp2[j])[w[dfn2[i]]>>(31-j)]--;
    }
  }
  return ;
}
int cnt;
void dfs(int now,int fa){
  siz[now]=1;
  bson[now]=0;
  dfn[now]=++cnt;
  dfn2[cnt]=now;
  if(fa!=now){
    w[now]^=w[fa];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    if(bson[now]==0||siz[bson[now]]<siz[v[i]]){
      bson[now]=v[i];
    }
  }
  lst[now]=cnt;
  return ;
}
void dfs2(int now,int fa){
  if(bson[now]){
    dfs2(bson[now],now);
    for(int i=0;i<32;i++){
      std::swap(mp[bson[now]][i],mp[now][i]);
    }
  }
  for(int i=0;i<32;i++){
    mp[now][i][w[now]>>(31-i)]++;
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    dfs2(v[i],now);
    adddis(mp[now],v[i],oriw[now]);
  }
  return ;
}
void dfs3(int now,int fa){
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    for(int ii=dfn[v[i]];ii<=lst[v[i]];ii++){
      int ret=w[dfn2[ii]]^oriw[now];
      for(int j=0;j<32;j++){
        mp[now][j][(ret)>>(31-j)]++;
      }
    }
  }
  int ret=w[now];
  for(int j=0;j<32;j++){
    mp[now][j][(w[now]^oriw[now])>>(31-j)]++;
    if(j==31){
      ans[dfn[now]]+=mp[now][31][ret^t];
    }
    if((t>>(31-j))&1){
      continue;
    }
    int tt=ret>>(31-j);
    tt^=(t>>(31-j));
    tt^=1;
    ans[dfn[now]]+=(mp[now][j])[tt];
  }
  if(bson[now]){
    for(int i=0;i<32;i++){
      std::swap(mp[bson[now]][i],mp[now][i]);
    }
    dfs3(bson[now],now);
  } 
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    for(int j=0;j<32;j++){
      mp[v[i]][i].clear();
    }
    dfs3(v[i],now);
  }
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("weight.in","r",stdin);
	freopen("weight.out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  for(int i=1;i<=n;i++){
    w[i]=read();
    oriw[i]=w[i];
  }
  t=read();
  dfs(1,1);
  dfs2(1,1);
  for(int i=0;i<32;i++){
    mp[1][i].clear();
  }
  dfs3(1,1);
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans*=n;
    ans%=mod;
  }
  long long tt=1;
  for(int i=1;i<=n;i++){
    tt*=(n-::ans[i]);
    tt%=mod;
  }
  ans-=tt;
  ans%=mod;
  ans+=mod;
  ans%=mod;
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
