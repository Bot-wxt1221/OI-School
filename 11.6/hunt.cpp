#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
inline int read();
int n;
std::pair<int,int>pa[500005];
std::pair<int,int>pb[500005];
std::pair<int,int>pc[500005];
int x[500005],y[500005],z[500005];
bool vised[500005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  for(int i=1;i<=n;i++){
    pa[i]={(x[i]=read()),i};
    pb[i]={(y[i]=read()),i};
    pc[i]={(z[i]=read()),i};
  }
  std::sort(pa+1,pa+n+1);
  std::sort(pb+1,pb+n+1);
  std::sort(pc+1,pc+n+1);
  int cura=1,curb=1,curc=1;
  int k=0;
  while(cura<=n||curb<=n||curc<=n){
    int a=pa[cura].second;
    int b=pb[curb].second;
    int c=pc[curc].second;
    if(vised[a]){
      cura++;
      continue;
    }
    if(vised[b]){
      curb++;
      continue;
    }
    if(vised[c]){
      curc++;
      continue;
    }
    int va=0x3f3f3f3f,vb=0x3f3f3f3f,vc=0x3f3f3f3f;
    if(cura<=n){
      va=std::max(y[a]-y[b],z[a]-z[c]);
    }
    if(curb<=n){
      vb=std::max(x[b]-x[a],z[b]-z[c]);
    }
    if(curc<=n){
      vc=std::max(y[c]-y[b],x[c]-x[a]);
    }
    if(va<=vb&&va<=vc){
      k=std::max(k,va);
      cura++;
      vised[a]=1;
    }else if(vb<=va&&vb<=vc){
      k=std::max(k,vb);
      curb++;
      vised[b]=1;
    }else{
      k=std::max(k,vc);
      curc++;
      vised[c]=1;
    }
  }
  k=(k/2)+(k%2);
  printf("%lld",k);
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
