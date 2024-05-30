#include <iostream>
#include <cstdio>
#include <algorithm>
#define double long double
inline int read();
double a[100005];
double b[100005];
double rate[100005];
double dp[100005];
int seq[100005];
int tp;
int sta[100005];
double X(int x){
  return (dp[x]*rate[x])/(a[x]*rate[x]+b[x]);
}
double Y(int x){
  return dp[x]/(a[x]*rate[x]+b[x]);
}
double K(int x){
  return -a[x]/b[x];
}
bool cmpK(int x,int y){
  return a[x]*b[y]>a[y]*b[x];
}
bool cmpK2(int x1,int y1,int x2,int y2){
  if(X(x1)==X(y1)){
    return 0;
  }
  if(X(x2)==X(y2)){
    return 1;
  }
  return (Y(y1)-Y(x1))*(X(y2)-X(x2))<(Y(y2)-Y(x2))*(X(y1)-X(x1));
}
bool cmp(int x,int y){
  return X(x)<X(y);
}
void cdq(int l,int r){
  if(l>=r){
    dp[l]=std::max(dp[l],dp[l-1]);
    return ;
  }
  int mid=(l+r)/2;
  cdq(l,mid);
  for(int i=l;i<=r;i++){
    seq[i]=i;
  }
  std::sort(seq+l,seq+mid+1,cmp);
  std::sort(seq+mid+1,seq+r+1,cmpK);
  tp=0;
  for(int i=l;i<=mid;i++){
    while(tp>1&&cmpK2(sta[tp-1],sta[tp],sta[tp],seq[i])){
      tp--;
    }
    sta[++tp]=seq[i];
  }
  for(int i=mid+1;i<=r;i++){
    while(tp>1&&(Y(sta[tp-1])-Y(sta[tp]))/(X(sta[tp-1])-X(sta[tp]))<K(seq[i])){      
      tp--;
    }
    int &j=sta[tp];
    dp[seq[i]]=std::max(dp[seq[i]],X(j)*a[seq[i]]+Y(j)*b[seq[i]]);
  }
  cdq(mid+1,r);
  return ;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),s;
  s=read();
  dp[1]=s;
  for(int i=1;i<=n;i++){
    scanf("%Lf%Lf%Lf",&a[i],&b[i],&rate[i]);
  }
  cdq(1,n);
  printf("%.3Lf\n",dp[n]);
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


