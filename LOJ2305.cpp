#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
inline int read();
char temp[50005];
int fir[100005];
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
  return x+(y)*50002;
}
int dfn[100005];
int low[100005];
bool in_stack[100005];
char ans[100005];
int cnt;
int st[100005];
int tp;
int toscc[200005];
int scccnt=0;
void dfs(int now,int fa){
  dfn[now]=low[now]=++cnt;
  in_stack[now]=1;
  st[++tp]=now;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(dfn[v[i]]==0){
      dfs(v[i],now);
      low[now]=std::min(low[now],low[v[i]]);
    }else if(in_stack[v[i]]){
      low[now]=std::min(low[now],dfn[v[i]]);
    }
  }
  if(dfn[now]==low[now]){
    toscc[now]=++scccnt;
    in_stack[now]=0;
    while(tp&&st[tp]!=now){
      toscc[st[tp]]=scccnt;
      in_stack[st[tp]]=0;
      tp--;
    }
    tp--;
  }
  return ;
}
int ii[1000005];
int hii[1000005];
int jj[1000005];
int hjj[1000005];
int n,m;
int seq[15];
void dfs(int nw){
  if(nw==vec.size()){
    now=0;
    memset(fir,-1,sizeof(fir));
    memset(dfn,0,sizeof(dfn));
    cnt=0;
    scccnt=0;
    for(int iii=1;iii<=m;iii++){
      int i=ii[iii];
      int hi=hii[iii]-'A';
      int j=jj[iii];
      int hj=hjj[iii]-'A';
      if(hi==temp[i]-'A'){
        continue;
      }
      if(hi>temp[i]-'A'){
        hi--;
      }
      if(hj==temp[j]-'A'){
        add(get(i,hi),get(i,!hi));
        continue;
      }
      if(hj>temp[j]-'A'){
        hj--;
      }
      add(get(i,hi),get(j,hj));
      add(get(j,!hj),get(i,!hi));
    }
    for(int i=0;i<=100000;i++){
      if(dfn[i]==0){
        dfs(i,i);
      }
    }
    for(int i=1;i<=n;i++){
      if(toscc[get(i,0)]==toscc[get(i,1)]){
        return ;
      }
      if(toscc[i]>toscc[i+50002]){
        if(temp[i]!='C'){
          ans[i]='C';
        }else{
          ans[i]='B';
        }
      }else{
        if(temp[i]!='A'){
          ans[i]='A';
        }else{
          ans[i]='B';
        }
      }
    }
    for(int i=1;i<=n;i++){
      if(toscc[i]>toscc[i+50002]){
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
  for(int i=0;i<2;i++){
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
  puts("-1");
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
