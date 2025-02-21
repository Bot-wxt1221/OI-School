#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
char temp[200005];
int z[200005];
std::vector<int>vec[200005];
int fa[200005];
std::vector<int>jump[200005];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int fail[200005];
int fir[200005];
int nxt[400005];
int v[400005];
int to[200005][25];
int dep[200005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  scanf("%s",temp+1);
  //fail tree
  int j=0;
  for(int i=2;i<=n;i++){
    while(j&&temp[i]!=temp[j+1]){
      j=fail[j];
    }
    j+=(temp[i]==temp[j+1]);
    fail[i]=j;
  }
  for(int i=1;i<=n;i++){
    to[i][0]=fail[i];
    dep[i]=dep[fail[i]]+1;
  }
  for(int i=1;i<=20;i++){
    for(int j=1;j<=n;j++){
      to[j][i]=to[to[j][i-1]][i-1];
    }
  }
  //calc Z
  int l=0,r=0;
  fa[1]=1;
  z[1]=n;
  for(int i=2;i<=n;i++){
    fa[i]=i;
    if(i<=r&&z[i-l+1]<r-i+1){
      z[i]=z[i-l+1];
    }else{
      z[i]=std::max(0,r-i+1);
      while(i+z[i]<=n&&temp[z[i]+1]==temp[i+z[i]]){
        z[i]++;
      }
    }
    if(i+z[i]-1>r){
      l=i;
      r=i+z[i]-1;
    }
    vec[z[i]].push_back(i);
  }
  fa[n+1]=n+1;
  for(int j=0;j<vec[0].size();j++){
    fa[getfa(vec[0][j])]=getfa(vec[0][j]+1);
  }
  for(int i=1;i<=n;i++){
    int cur=i;
    while(cur+i<=n){
      cur=getfa(cur+1);
      if(cur>n){
        break;
      }
      cur+=i-1;
      jump[i].push_back(cur);
    }
    for(int j=0;j<vec[i].size();j++){
      fa[getfa(vec[i][j])]=getfa(vec[i][j]+1);
    }
  }
  int q=read();
  for(int ii=1;ii<=q;ii++){
    int i=read();
    int k=read();
    if(k==1){
      printf("1\n");
      continue;
    }
    int iii=i;
    for(int j=20;j>=0;j--){
      if(to[i][j]){
        if(jump[to[i][j]].size()<k-1||jump[to[i][j]][k-2]>iii){
          i=to[i][j];
        }
      }
    }
    i=to[i][0];
    printf("%d\n",dep[i]);
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
