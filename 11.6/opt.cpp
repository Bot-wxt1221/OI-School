#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int fir[500005];
int nxt[1000005];
int v[1000005];
int fac[5000005];
int inv[5000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int temp=pow(x,y/2);
    return (1ll*temp*temp)%mod;
  }
  return (1ll*pow(x,y-1)*x)%mod;
}
int CC(int n,int m){
  if(n<m){
    return 0;
  }
  if(n<0||m<0){
    return 0;
  }
  return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int siz[500005];
int bson[500005];
int dfn[500005];
int seq2tree[500005];
char seq1[500005];
char seq2[500005];
int z[500005];
int xx[500005];
int yy[500005];
int cnt,A,B,C,X,Y;
void dfs(int now,int fa,int dep){
  xx[now]=(seq1[now]=='?');
  yy[now]=(seq2[now]=='?');
  if(seq1[now]!='?'){
    int t1=(seq1[now]-'0')^(dep&1);
    z[now]+=t1;
  }
  if(seq2[now]!='?'){
    int t2=(seq2[now]-'0')^(dep&1);
    z[now]-=t2;
  }
  dfn[now]=++cnt;
  seq2tree[cnt]=now;
  siz[now]=1;
  bson[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now,dep+1);
    z[now]+=z[v[i]];
    xx[now]+=xx[v[i]];
    yy[now]+=yy[v[i]];
    if(bson[now]==0||siz[v[i]]>siz[bson[now]]){
      bson[now]=v[i];
    }
  }
  return ;
}
class Gval{
public:
  int x,y,val;
}seq[500005];
class Gval2{
public:
  int x,y,val;
}seq22[500005];
Gval calcg(int n,int m){
  int ans=0;
  for(int i=0;i<=m;i++){
    ans+=1ll*CC(n,i)*CC(X-n,Y-i)%mod;
    ans%=mod;
  }
  Gval ret;
  ret.x=n;
  ret.y=m;
  ret.val=ans;
  return ret;
}
Gval moveto(Gval a,int n,int m){
  if(n<=5||m<=5){
    return calcg(n,m);
  }
  Gval ret=a;
  while(ret.x<n){
    ret.val-=CC(ret.x,ret.y)*CC(X-ret.x-1,Y-ret.y-1)%mod;
    ret.val%=mod;
    ret.x++;
  }
  while(ret.y<m){
    ret.val+=CC(ret.x,ret.y+1)*CC(X-ret.x,Y-ret.y-1)%mod;
    ret.val%=mod;
    ret.y++;
  }
  while(ret.y>m){
    ret.y--;
    ret.val-=CC(ret.x,ret.y+1)*CC(X-ret.x,Y-ret.y-1)%mod;
    ret.val%=mod;
  }
  return ret;
}
Gval2 calcg2(int n,int m){
  int ans=0;
  for(int i=0;i<=m;i++){
    ans+=1ll*CC(n,i)*CC(X-n-1,Y-i-1)%mod;
    ans%=mod;
  }
  Gval2 ret;
  ret.x=n;
  ret.y=m;
  ret.val=ans;
  return ret;
}
Gval2 moveto2(Gval2 a,int n,int m){
  if(a.x<0||a.y<0){
    return calcg2(n,m);
  }
  if(n<=5||m<=5){
    return calcg2(n,m);
  }
  Gval2 ret=a;
  while(ret.x<n){
    ret.val-=CC(ret.x,ret.y)*CC(X-ret.x-2,Y-ret.y-2)%mod;
    ret.val%=mod;
    ret.x++;
  }
  while(ret.y<m){
    ret.val+=CC(ret.x,ret.y+1)*CC(X-ret.x-1,Y-ret.y-2)%mod;
    ret.val%=mod;
    ret.y++;
  }
  while(ret.y>m){
    ret.y--;
    ret.val-=CC(ret.x,ret.y+1)*CC(X-ret.x-1,Y-ret.y-2)%mod;
    ret.val%=mod;
  }
  return ret;
}
int getf(int now,int x,int y){
  int ret=-1ll*CC(X,Y)*y%mod;
  ret+=1ll*x*CC(X-1,Y-1)%mod;
  ret%=mod;
  if(bson[now]==0){
    seq[now]=calcg(x,y);
    seq22[now]=calcg2(x-1,y-1);
  }else{
    seq[now]=moveto(seq[bson[now]],x,y);
    seq22[now]=moveto2(seq22[bson[now]],x-1,y-1);
  }
  ret+=seq[now].val*1ll*y%mod*2%mod;
  ret%=mod;
  ret-=2*1ll*(seq22[now].val)%mod*x%mod;
  ret%=mod;
  return ret;
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
  fac[0]=1;
  for(int i=1;i<=5000000;i++){
    fac[i]=1ll*fac[i-1]*i%mod;
  }
  inv[5000000]=pow(fac[5000000],mod-2);
  for(int i=5000000-1;i>=0;i--){
    inv[i]=1ll*inv[i+1]*(i+1)%mod;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  scanf("%s",seq1+1);
  scanf("%s",seq2+1);
  dfs(1,1,0);
  A=B=C=0;
  for(int i=1;i<=n;i++){
    A+=(seq1[i]=='?');
    B+=(seq2[i]=='?');
  }
  C=z[1];
  X=A+B;
  int ans=0;
  Y=A+C;
  for(int i=n;i>=1;i--){
    ans+=getf(i,xx[i]+yy[i],xx[i]+z[i]);
    ans%=mod;
  }
  ans+=mod;
  ans%=mod;
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
