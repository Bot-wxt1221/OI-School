#include <iostream>
#include <cstdio>
#include <stack>
#include <set>
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
std::set<int>se[100005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  se[x].insert(y);
  se[y].insert(x);
  return ;
}
int dfn[100005];
int low[100005];
int cntt;
std::stack<int>st;
int n;
namespace ng{
int fir[200005];
int nxt[400005];
int v[400005];
int fa[200005][25];
int dp1[200005];
int dp2[200005];
int in[200005];
int out[200005];
int cntt=0;
int dep[200005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs1(int now,int fa){
  ng::fa[now][0]=fa;
  dep[now]=dep[fa]+1;
  in[now]=++cntt;
  for(int i=1;i<=20;i++){
    ng::fa[now][i]=ng::fa[ng::fa[now][i-1]][i-1];
  }
  dp1[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs1(v[i],now);
    dp1[now]&=dp1[v[i]];
    if(now>n){
      dp1[now]&=se[fa].count(v[i]);
    }
  }
  out[now]=cntt;
  return ;
}
void dfs2(int now,int fa){
  std::set<int>se;
  int cnt1=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    se.insert(v[i]);
    if(dp1[v[i]]==0&&v[i]!=fa){
      cnt1++;
    }
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]!=fa){
      dp2[v[i]]=dp2[now]&&(cnt1==0||(cnt1==1&&!dp1[v[i]]));
      if(now>n){
        int cnt2=0;
        for(int j=::fir[v[i]];j!=-1;j=::nxt[j]){
          if(se.count(::v[j])){
            cnt2++;
          }
        }
        dp2[v[i]]&=(cnt2+1==se.size());
      }
    }
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now);
  }
  return ;
}
bool check(int x,int y){
  return in[x]<=in[y]&&in[y]<=out[x];
}
int jump(int x,int y){
  for(int i=20;i>=0;i--){
    if(y>=(1<<i)){
      y-=(1<<i);
      x=fa[x][i];
    }
  }
  return x;
}
}
int bcccnt=0;
void dfs(int now){
  dfn[now]=low[now]=++cntt;
  st.push(now);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(!dfn[v[i]]){
      dfs(v[i]);
      low[now]=std::min(low[now],low[v[i]]);
      if(low[v[i]]==dfn[now]){//(u,v) is a new BCC
        ng::add(now,++bcccnt);
        ng::add(bcccnt,now);
        while(st.size()>0&&st.top()!=v[i]){
          ng::add(st.top(),bcccnt);
          ng::add(bcccnt,st.top());
          st.pop();
        }
        ng::add(st.top(),bcccnt);
        ng::add(bcccnt,st.top());
        st.pop();
      }
    }else{
      low[now]=std::min(low[now],dfn[v[i]]);
    }
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  int m=read();
  int q=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    ng::fir[i]=ng::fir[n+i]=-1;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  bcccnt=n;
  dfs(1);
  ng::dfs1(1,1);
  ng::dp2[1]=1;
  ng::dfs2(1,1);
  for(int i=1;i<=n;i++){
    if(ng::dp1[i]&&ng::dp2[i]){
      for(int j=1;j<=q;j++){
        printf("Yes\n");
      }
      return 0;
    }
  }
  for(int i=1;i<=q;i++){
    int a=read();
    int b=read();
    if(!ng::check(a,b)){
      if(ng::dp2[a]){
        printf("Yes\n");
      }else{
        printf("No\n");
      }
    }else{
      if(ng::dp1[ng::jump(b,ng::dep[b]-ng::dep[a]-1)]){
        printf("Yes\n");
      }else{
        printf("No\n");
      }
    }
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
