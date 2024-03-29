#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int fir[10000005];
int nxt[10000005];
int v[10000005];
int c[10000005];
int m[10000005];
int f[10000005];
int cur[10000005];
int ans[10000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
class ques{
  public:
    int i,ans;
    ques(int x=0,int y=0){
      i=x;
      ans=y;
      return ;
    }
}que[2000005];
bool operator < (ques a,ques b){
  return a.i<b.i;
}
int x[2000005];
bool cmp(int a,int b){
  return c[a]*m[b]<c[b]*m[a];
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("farmland.in","r",stdin);
  freopen("farmland.out","w",stdout);
  #endif
  int n=read(),q;
  q=read();
  bool special=1;
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=2;i<=n;i++){
    int fi=read();
    f[i]=fi;
    c[i]=read();
    m[i]=read();
    add(fi,i);
    add(i,fi);
    if(i==2&&fi!=1){
      special=0;
    }else if(i!=2&&fi!=2){
      special=0;
    }
  }
  if(special){
    int cur2=c[2];
    int summ=0;
    for(int i=1;i<=n;i++){
      summ+=m[i];
      x[i]=i;
    }
    summ-=m[2];
    std::sort(x+3,x+n+1,cmp);
    int cur=3;
    int prett=0;
    for(int i=1;i<=q;i++){
      que[i]=ques(read(),i);
    }
    for(int i=1;i<=q;i++){
      int tt=que[i].i;
      while(tt*m[x[cur]]>=c[x[cur]]&&cur<=n){
        cur2-=(prett)*m[x[cur]];
        cur2+=c[x[cur]];
        summ-=m[x[cur]];
        cur++;
      }
      cur2+=(summ)*(tt-prett);
      prett=tt;
      ans[que[i].ans]=std::min(cur2,tt*m[2]);
    }
    for(int i=1;i<=q;i++){
      printf("%lld\n",ans[i]);
    }
    return 0;
  }
  for(int ii=1;ii<=q;ii++){
    int tt=read();
    for(int j=n;j>=1;j--){
      cur[j]=c[j];
    }
    for(int j=n;j>=1;j--){
      int ttt=std::min(tt*m[j],cur[j]);
      cur[j]-=ttt;
      cur[f[j]]+=ttt;
    }
    printf("%lld\n",cur[1]);
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

