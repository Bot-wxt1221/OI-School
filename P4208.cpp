#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int fir[1005];
int u[1005];
int v[1005];
int w[1005];
int w2[1005];
int cntt[1005];
int cnt2[1005];
std::vector<int>vec[1005];
bool chose[1005];
class ng{
public:
  int a,b,c,d;
  ng(int x=0,int y=0,int z=0,int zz=0){
    a=x;
    b=y;
    c=z;
    d=zz;
    return ;
  }
}seq[1005];
bool operator<(ng a,ng b){
  return a.c<b.c;
}
int fa[200005];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    fa[i]=i;
  }
  for(int i=1;i<=m;i++){
    u[i]=read();
    v[i]=read();
    w[i]=read();
    w2[i]=w[i];
    seq[i]=ng(u[i],v[i],w[i],i);
  }
  std::sort(w2+1,w2+m+1);
  int cnt=std::unique(w2+1,w2+m+1)-w2-1;
  std::sort(seq+1,seq+m+1);
  int cnttt=0;
  for(int i=1;i<=m;i++){
    vec[std::lower_bound(w2+1,w2+cnt+1,seq[i].c)-w2].push_back(seq[i].d);
    int tx=getfa(seq[i].a);
    int ty=getfa(seq[i].b);
    if(tx==ty){
      continue;
    }
    fa[tx]=ty;
    cnttt++;
    chose[seq[i].d]=1;
    cnt2[std::lower_bound(w2+1,w2+cnt+1,seq[i].c)-w2]++;
  }
  if(cnttt!=n-1){
    printf("0\n");
    return 0;
  }
  int ans=1;
  for(int i=1;i<=cnt;i++){
    int tt=0;
    int siz=vec[i].size();
    for(int j=0;j<(1<<(siz));j++){
      for(int k=1;k<=n;k++){
        fa[k]=k;
      }
      for(int k=1;k<=m;k++){
        if(w[k]!=w2[i]&&chose[k]){
          fa[getfa(u[k])]=getfa(v[k]);
        }
      }
      int cntt=0;
      for(int k=0;k<siz;k++){
        if(j&(1<<(k))){
          cntt++;
          if(getfa(u[vec[i][k]])==getfa(v[vec[i][k]])){
            goto end;
          }
          fa[getfa(u[vec[i][k]])]=getfa(v[vec[i][k]]);
        }
      }
      if(cntt!=cnt2[i]){
        continue;
      }
      tt++;
      end:{}
    }
    ans*=tt;
    ans%=31011;
  }
  printf("%d",ans);
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
