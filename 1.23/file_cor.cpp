#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
class node{
  public:
    int i,data;
    node(int xx=0,int yy=0){
      i=xx;
      data=yy;
      return ;
    }
}aa[200005];
bool operator < (node a,node b){
  return a.data>b.data;
}
std::vector<std::pair<int,int> > quea[200005];
int pos[200005];
int ans[200005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=n;i++){
    aa[i].i=i;
    aa[i].data=0;
  }
  for(int i=1;i<=m;i++){
    int a=read();
    int b=read();
    int c=read();
    aa[b].data++;
    quea[a].push_back(std::make_pair(b,c));
    quea[c].push_back(std::make_pair(b,a));
  }
  std::sort(aa+1,aa+n+1);
  int l=n;
  int r=n;
  for(int i=1;i<=n;i++){
    int a=0;
    int b=0;
    for(int j=0;j<quea[aa[i].i].size();j++){
      int x=quea[aa[i].i][j].first;
      int y=quea[aa[i].i][j].second;
      if(pos[x]==0||pos[y]==0){
        continue;
      }
      if(pos[x]<pos[y]){
        a++;
      }else{
        b++;
      }
    }
    if(a>=b){
      ans[l--]=aa[i].i;
      pos[aa[i].i]=l+1;
    }else{
      ans[++r]=aa[i].i;
      pos[aa[i].i]=r;
    }
  }
  for(int i=l+1;i<=r;i++){
    printf("%d ",ans[i]);
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


