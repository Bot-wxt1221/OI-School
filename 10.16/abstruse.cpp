#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
inline int read();
std::vector<int>tt[25][100005];
int T,n;
int cnt[100005];
std::vector<int>ccc[100005];
std::vector<int>ans[100005];
namespace ng{
int fir[600005];
std::vector<int>ans;
int nxt[2000005];
bool del[2000005];
int point[2000005];
int tt[2000005];
int u[2000005];
int v[2000005];
bool vised[600005];
int now=1;
void add1(int x,int y){
  tt[y]++;
  v[++now]=y;
  u[now]=x;
  nxt[now]=fir[x];
  del[now]=0;
  fir[x]=now;
  point[now]=0;
  return ;
}
void add(int x,int y){
  if(tt[y]==0){
    ans.push_back(y);
  }
  add1(x,y);
  return ;
}
void dfs(int now,int fa){
  vised[now]=1;
  for(int &i=fir[now];i!=-1;){
    if(del[i]){
      i=nxt[i];
      continue;
    }
    del[i]=del[i^1]=1;
    point[i]=1;
    dfs(v[i],now);
    if(i!=-1){
      i=nxt[i];
    }
  }
  return ;
}
};
void dfs(int nw,int l,int r,int depth){
  if(l==r){
    for(int i=1;i<=n;i++){
      ans[i][l]=tt[depth][i][0];
    }
    return ;
  }
  std::vector<int> *tmp=new std::vector<int>[n+5];
  std::vector<std::pair<int,int> >ttt;
  int mid=(l+r)/2;
  ng::now=1;
  int TT=0;
  int TT2=0x3f3f3f3f;
  for(int i=1;i<=n;i++){
    for(int j=l;j<=r;j++){
      TT=std::max(TT,tt[depth][i][j-l]);
      TT2=std::min(TT2,tt[depth][i][j-l]);
    }
  }
  TT2--;
  for(int i=1;i<=n;i++){
    for(int j=l;j<=r;j++){
      cnt[tt[depth][i][j-l]]++;
    }
    for(int j=l;j<=r;j++){
      int curnum=tt[depth][i][j-l];
      for(int k=1;k<=cnt[curnum]/2;k++){
        tt[depth+1][i].push_back(curnum);
        tmp[i].push_back(curnum);
      }
      if(cnt[curnum]%2==1){
        ng::add(curnum-TT2,i+TT-TT2);
        ng::add(i+TT-TT2,curnum-TT2);
      }
      cnt[tt[depth][i][j-l]]=0;
    }
  }
  int x=TT-TT2+n;
  for(int ii=1;ii<=ng::ans.size();ii++){
    int i=ng::ans[ii-1];
    if(ng::tt[i]%2){
      ng::add1(0,++x);
      ng::add1(x,0);
      ng::add1(x,i);
      ng::add1(i,x);
    }
  }
  ng::ans.push_back(0);
  for(int ii=1;ii<=ng::ans.size();ii++){
    int i=ng::ans[ii-1];
    if(ng::vised[i]){
      continue;
    }
    ng::dfs(i,i);
  }
  for(int i=1;i<=ng::now;i++){
    if(ng::point[i]){
      if(ng::u[i]>TT-TT2+n){
        continue;
      }
      if(ng::v[i]>TT-TT2+n){
        continue;
      }
      if(ng::u[i]>TT-TT2){
        tmp[ng::u[i]-(TT-TT2)].push_back(ng::v[i]+TT2);
      }else{
        tt[depth+1][ng::v[i]-(TT-TT2)].push_back(ng::u[i]+TT2);
      }
    }
    ng::fir[ng::u[i]]=-1;
    ng::fir[ng::v[i]]=-1;
    ng::vised[ng::u[i]]=0;
    ng::vised[ng::v[i]]=0;
    ng::tt[ng::u[i]]=0;
    ng::tt[ng::v[i]]=0;
  }
  ng::ans.clear();
  ng::fir[0]=-1;
  ng::vised[0]=0;
  ng::tt[0]=0;
  dfs(nw*2,l,mid,depth+1);
  for(int i=1;i<=n;i++){
    std::swap(tmp[i],tt[depth+1][i]);
  }
  dfs(nw*2+1,mid+1,r,depth+1);
  delete [] tmp;
  for(int i=1;i<=n;i++){
    tt[depth+1][i].clear();
  }
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("abstruse.in","r",stdin);
	freopen("abstruse.out","w",stdout);
	#endif
  n=read();
  int S=read();
  T=read();
  memset(ng::fir,-1,sizeof(ng::fir));
  for(int i=1;i<=n;i++){
    tt[1][i].resize(S+5);
    ans[i].resize(S+5);
    for(int j=1;j<=S;j++){
      tt[1][i][j-1]=read();
    }
  }
  dfs(1,1,S,1);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=S;j++){
      printf("%d ",ans[i][j]);
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
