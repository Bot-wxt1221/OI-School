#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int now;
class hp{
  public:
    std::priority_queue<int>a,b;
    int siz=0;
    int size(){
      return siz;
    }
    void erase(int x){
      siz--;
      b.push(x);
    }
    void push(int x){
      siz++;
      a.push(x);
    }
    void upd(){
      while(b.size()>0&&a.size()>0&&a.top()==b.top()){
        a.pop();
        b.pop();
      }
      return ;
    }
    int top(){
      upd();
      return a.top();
    }
    void pop(){
      siz--;
      upd();
      a.pop();
      return ;
    }
    int top2(){
      int tp=top();
      pop();
      int ret=top();
      push(tp);
      return ret;
    }
}dis[100005],ch[100005],ans;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int col[100005];
bool vised[100005];
int maxx[100005];
int siz[100005];
int dep[100005];
int sum,rt;
void calcsiz(int now,int fa){
  siz[now]=1;
  maxx[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    calcsiz(v[i],now);
    siz[now]+=siz[v[i]];
    maxx[now]=std::max(maxx[now],siz[v[i]]);
  }
  maxx[now]=std::max(maxx[now],sum-siz[now]);
  if(maxx[now]<maxx[rt]||rt==0){
    rt=now;
  }
  return ;
}
int tp;
void calcdis(int now,int fa,int ddis){
  dis[tp].push(ddis);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    calcdis(v[i],now,ddis+1);
  }
  return ;
}
int fa[100005];
void dfs(int now,int fa){
  vised[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    sum=siz[v[i]];
    rt=0;
    calcsiz(v[i],now);
    calcsiz(rt,-1);
    ::fa[rt]=now;
    dep[rt]=dep[now]+1;
    tp=rt;
    calcdis(v[i],now,1);
    dfs(rt,-1);
  }
  return ;
}
int dd[100005][30];
namespace LCA{
int dep[150005];
int to[150005][30];
int dis[150005][30];
void dfs(int now,int fa){
  dep[now]=dep[fa]+1;
  to[now][0]=fa;
  if(now==fa){
    dis[now][0]=0;
  }
  for(int i=1;i<30;i++){
    to[now][i]=to[to[now][i-1]][i-1];
    dis[now][i]=dis[now][i-1]+dis[to[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dis[v[i]][0]=1;
    dfs(v[i],now);
  }
  return ;
}
int gdis(int x,int y){
  if(dep[x]<dep[y]){
    std::swap(x,y);
  }
  int ret=0;
  while(dep[x]>dep[y]){
    int i=29;
    for(i=29;i>0;i--){
      if(dep[to[x][i]]>dep[y]){
        break;
      }
    }
    ret+=dis[x][i];
    x=to[x][i];
  }
  while(x!=y){
    int i=29;
    for(i=29;i>0;i--){
      if(to[x][i]!=to[y][i]){
        break;
      }
    }
    ret+=dis[y][i];
    ret+=dis[x][i];
    x=to[x][i];
    y=to[y][i];
  }
  return ret;
}
}
char temp[20];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
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
  sum=n;
  calcsiz(1,1);
  calcsiz(rt,-1);
  int rtt=rt;
  dfs(rt,-1);
  LCA::dfs(1,1);
  for(int i=1;i<=n;i++){
    int j=i;
    while(j!=rtt){
      dd[i][dep[i]-dep[j]]=LCA::gdis(i,j);
      j=fa[j];
    }
    dd[i][dep[i]-dep[j]]=LCA::gdis(i,j);
    j=fa[j];
  }
  for(int i=1;i<=n;i++){
    if(fa[i]!=0){
      ch[fa[i]].push(dis[i].top());
    }
    ch[i].push(0);
  }
  for(int i=1;i<=n;i++){
    if(ch[i].size()>=2){
      ans.push(ch[i].top()+ch[i].top2());
    }
  }
  int q=read();
  int cnt=n;
  for(int ii=1;ii<=q;ii++){
    scanf("%s",temp+1);
    switch(temp[1]){
      case 'G':{
        if(ans.size()!=0){
          printf("%d\n",ans.top());
        }else if(cnt!=1){
          printf("-1\n");
        }else{
          printf("0\n");
        }
        break;
      }
      case 'C':{
        int i=read();
        if(col[i]){
          if(ch[i].size()>=2){
            ans.erase(ch[i].top()+ch[i].top2());
          }
          ch[i].push(0);
          if(ch[i].size()>=2){
            ans.push(ch[i].top()+ch[i].top2());
          }
          cnt++;
          col[i]=0;
          int ti=i;
          while(i!=rtt){
            if(ch[fa[i]].size()>=2){
              ans.erase(ch[fa[i]].top()+ch[fa[i]].top2());
            }
            if(dis[i].size()){
              ch[fa[i]].erase(dis[i].top());
            }
            dis[i].push(dd[ti][dep[ti]-dep[fa[i]]]);
            ch[fa[i]].push(dis[i].top());
            if(ch[fa[i]].size()>=2){
              ans.push(ch[fa[i]].top()+ch[fa[i]].top2());
            }
            i=fa[i];
          }
          dis[i].push(dd[ti][dep[ti]-dep[fa[i]]]);
        }else{
          if(ch[i].size()>=2){
            ans.erase(ch[i].top()+ch[i].top2());
          }
          ch[i].erase(0);
          if(ch[i].size()>=2){
            ans.push(ch[i].top()+ch[i].top2());
          }
          cnt--;
          col[i]=1;
          int ti=i;
          while(i!=rtt){
            if(ch[fa[i]].size()>=2){
              ans.erase(ch[fa[i]].top()+ch[fa[i]].top2());
            }
            ch[fa[i]].erase(dis[i].top());
            dis[i].erase(dd[ti][dep[ti]-dep[fa[i]]]);
            if(dis[i].size()){
              ch[fa[i]].push(dis[i].top());
            }
            if(ch[fa[i]].size()>=2){
              ans.push(ch[fa[i]].top()+ch[fa[i]].top2());
            }
            i=fa[i];
          }
          dis[i].erase(dd[ti][dep[ti]-dep[fa[i]]]);
        }
      }
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


