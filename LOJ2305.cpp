#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
inline int read();
char temp[50005];
int fir[200005];
int nxt[1000005];
int u[1000005];
int v[1000005];
std::vector<int>vec;
int now;
void add(int x,int y){
  v[++now]=y;
  u[now]=x;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int get(int x,int y){
  return x+(y)*70002;
}
int dfn[200005];
int low[200005];
bool in_stack[200005];
int cnt;
std::stack<int>st;
std::vector<int>tt[200005];
int toscc[200005];
void dfs(int now,int fa){
  dfn[now]=low[now]=++cnt;
  in_stack[now]=1;
  st.push(now);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(dfn[v[i]]==0){
      dfs(v[i],now);
      low[now]=std::min(low[now],low[v[i]]);
    }else if(in_stack[v[i]]){
      low[now]=std::min(low[now],dfn[v[i]]);
    }
  }
  if(dfn[now]==low[now]){
    toscc[now]=now;
    tt[now].push_back(now);
    in_stack[now]=0;
    while(st.size()>0&&st.top()!=now){
      toscc[st.top()]=now;
      tt[now].push_back(st.top());
      in_stack[st.top()]=0;
      st.pop();
    }
    st.pop();
  }
  return ;
}
int ii[1000005];
int hii[1000005];
int jj[1000005];
int hjj[1000005];
namespace ng{
int fir[200005];
int nxt[1000005];
int v[1000005];
int in[1000005];
int ans[200005];
bool used[200005];
int now;
void add(int x,int y){
  v[++now]=y;
  in[y]++;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void getans(){
  std::queue<int>qu;
  for(int i=1;i<=200000;i++){
    if(in[i]==0){
      qu.push(i);
    }
  }
  memset(used,0,sizeof(used));
  while(qu.size()>0){
    int tp=qu.front();
    qu.pop();
    for(int i=0;i<tt[tp].size();i++){
      if(used[tt[tp][i]%70002]){
        ans[tp]=1;
      }
      used[tt[tp][i]%70002]=1;
    }
    for(int i=fir[tp];i!=-1;i=nxt[i]){
      ans[v[i]]|=ans[tp];
      in[v[i]]--;
      if(in[v[i]]==0){
        qu.push(v[i]);
      }
    }
  }
  return ;
}
};
int n,m;
int seq[15];
void dfs(int nw){
  if(nw==vec.size()){
    now=0;
    memset(fir,-1,sizeof(fir));
    memset(ng::fir,-1,sizeof(ng::fir));
    memset(dfn,0,sizeof(dfn));
    for(int i=1;i<=n;i++){
      tt[i].clear();
    }
    ng::now=0;
    for(int iii=1;iii<=m;iii++){
      int i=ii[iii];
      int hi=hii[iii]-'A';
      int j=jj[iii];
      int hj=hjj[iii]-'A';
      if(hi==temp[i]-'A'||hj==temp[j]-'A'){
        continue;
      }
      if(hi>temp[i]-'A'){
        hi--;
      }
      if(hj>temp[j]-'A'){
        hj--;
      }
      add(get(i,hi),get(j,hj));
      add(get(j,!hj),get(i,!hi));
    }
    for(int i=0;i<=200000;i++){
      if(dfn[i]==0){
        dfs(i,i);
      }
    }
    for(int i=1;i<=n;i++){
      if(toscc[get(i,0)]==toscc[get(i,1)]){
        return ;
      }
    }
    for(int i=1;i<=now;i++){
      if(toscc[v[i]]==toscc[u[i]]){
        continue;
      }
      ng::add(toscc[v[i]],toscc[u[i]]);
    }
    ng::getans();
    for(int i=1;i<=n;i++){
      if(!ng::ans[toscc[i]]){
        if(temp[i]!='C'){
          printf("C");
        }else{
          printf("B");
        }
      }else{
        if(temp[i]!='A'){
          printf("A");
        }else{
          printf("B");
        }
      }
    }
    //done
    exit(0);
  }
  for(int i=0;i<3;i++){
    temp[vec[nw]]=i+'A';
    dfs(nw+1);
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  read();
  scanf("%s",temp+1);
  for(int i=1;i<=n;i++){
    if(temp[i]=='x'){
      vec.push_back(i);
    }
    temp[i]-='a';
    temp[i]+='A';
  }
  m=read();
  for(int i=1;i<=m;i++){
    ii[i]=read();
    while((hii[i]=getchar())>'Z'||hii[i]<'A');
    jj[i]=read();
    while((hjj[i]=getchar())>'Z'||hjj[i]<'A');
  }
  dfs(0);
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
