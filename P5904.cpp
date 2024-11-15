#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int siz[100005];
int bson[100005];
long long *orif[100005],*curf[100005];
long long *orig[100005],*curg[100005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  siz[now]=1;
  bson[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]=std::max(siz[now],siz[v[i]]+1);
    if(bson[now]==0||siz[v[i]]>siz[bson[now]]){
      bson[now]=v[i];
    }
  }
  return ;
}
long long ans=0;
void dfs2(int now,int fa,int tp){
  if(bson[now]){
    dfs2(bson[now],now,tp+1);
    curf[now]=curf[bson[now]]-1;
    orif[now]=orif[bson[now]];
    curg[now]=curg[bson[now]]+1;
    orig[now]=orig[bson[now]];
    ans+=curg[now][0];
  }else{
    orif[now]=(long long *)malloc(tp*2*sizeof(long long));
    curf[now]=orif[now]+tp-1;
    orig[now]=(long long *)malloc(tp*2*sizeof(long long));
    curg[now]=orig[now];
    memset(orif[now],0,tp*2*sizeof(long long));
    memset(orig[now],0,tp*2*sizeof(long long));
  }
  curf[now][0]=1;
 for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    dfs2(v[i],now,5);
    for(int j=0;j<siz[v[i]];j++){
      if(j){
        ans+=curg[v[i]][j]*curf[now][j-1];
      }
      ans+=curf[v[i]][j]*curg[now][j+1];
    }
    for(int j=0;j<siz[v[i]];j++){
      curg[now][j+1]+=curf[now][j+1]*curf[v[i]][j];
      curf[now][j+1]+=curf[v[i]][j];
      curg[now][j]+=curg[v[i]][j+1];
    }
    free(orif[v[i]]);
    free(orig[v[i]]);
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
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
  dfs(1,1);
  dfs2(1,1,5);
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
