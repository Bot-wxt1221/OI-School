#include <ctime>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
inline int read();
int fa[205];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
bool vised[205];
int ans[205];
bool tp[205];
int siz[205];
int a[205];
int b[205];
int tt[205];
int cnt;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n*2;i++){
    fa[i]=i;
  }
  for(int i=1;i<=n;i++){
    int p=read();
    fa[getfa(p+n)]=getfa(i);
    fa[getfa(i+n)]=getfa(p);
  }
  for(int i=1;i<=n;i++){
    if(vised[i]==0&&fa[i]==i){
      int cnt1=0,cnt2=0;
      int ti=0,ti2=0;
      for(int j=1;j<=n;j++){
        if(getfa(j)==i){
          cnt1++;
          ti2=ti;
          ti=j;
          vised[getfa(j)]=vised[getfa(j+n)]=1;
        }else if(getfa(j+n)==i){
          ti2=ti;
          ti=-j;
          cnt2++;
          vised[getfa(j)]=vised[getfa(j+n)]=1;
        }
      }
      siz[i]=cnt1+cnt2;
      if(cnt1+cnt2==2){
        b[i]=std::abs(ti);
        a[i]=std::abs(ti2);
        ans[b[i]]=0;
        ans[a[i]]=1;
      }else{
        tt[++cnt]=i;
      }
    }
  }
  int tt=cnt;
  for(int i=0;i<(1<<(tt));i++){
    for(int j=1;j<=cnt;j++){
      tp[::tt[j]]=((i&(1<<(j-1)))>0);
    }
    int pre=0;
    for(int j=1;j<=n;j++){
      int ttt=fa[j];
      if(siz[ttt]>2){
        ans[j]=tp[ttt];
      }
      ttt=fa[j+n];
      if(siz[ttt]>2){
        ans[j]=!tp[ttt];
      }
      pre+=ans[j]*2-1;
      if(pre<0){
        break;
      }
    }
    if(pre!=0){
      continue;
    }
    for(int j=1;j<=n;j++){
      printf("%c",ans[j]?'(':')');
    }
    exit(0);
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
