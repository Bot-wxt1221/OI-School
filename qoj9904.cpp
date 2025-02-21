#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
inline int read();
std::vector<int>sto[200005];
int beg[200005];
std::vector<std::pair<int,int> >vec;
int lowbit(int x){
  return x&(-x);
}
int tt=200005+1;
int mod=998244353;
int fac[200005];
int inv[200005];
int pow(int x,int y){
  int ans=1;
  while(y){
    if(y&1){
      ans*=x;
      ans%=mod;
    }
    y>>=1;
    x*=x;
    x%=mod;
  }
  return ans;
}
class BIT{
public:
  int tree[200005];
  int query(int now){
    int ans=0;
    while(now>0){
      ans+=tree[now];
      if(ans>mod){
        ans-=mod;
      }
      now-=lowbit(now);
    }
    return ans;
  }
  void add(int x,int y){
    while(x<=200000){
      tree[x]+=y;
      if(tree[x]>mod){
        tree[x]-=mod;
      }
      x+=lowbit(x);
    }
    return ;
  }
}A,B;
int queryA(int l,int r){
  return 1ll*(A.query(r)-A.query(l-1)+mod)%mod*inv[l]%mod;
}
int queryB(int l,int r){
  return 1ll*(B.query(200000-l+1)-B.query(200000-r)+mod)%mod*inv[200000-r+1]%mod;
}
bool isPa(int l,int r){
  return (queryA(l,r)+mod)%mod==(queryB(l,r)+mod)%mod;
}
void modD(int l,int op){
  A.add(l,-1ll*fac[l]*beg[l]%mod);
  B.add(200000-l+1,-1ll*fac[200000-l+1]*beg[l]%mod);
  beg[l]=op;
  A.add(l,1ll*fac[l]*beg[l]%mod);
  B.add(200000-l+1,1ll*fac[200000-l+1]*beg[l]%mod);
  return ;
}
void merge(int l,int r){
  l=beg[l];
  r=beg[r];
  if(sto[l].size()>sto[r].size()){
    std::swap(l,r);
  }
  for(int i=0;i<sto[l].size();i++){
    modD(sto[l][i],r);
    sto[r].push_back(sto[l][i]);
  }
  return ;
}
int work(int ll,int rr){
  if(ll==rr){
    return 0;
  }
  int ans=0;
  while(!isPa(ll,rr)){
    int l=0,r=(rr-ll+1)/2;
    while(r-l>3){
      int mid=(l+r)/2;
      if(isPa(ll+mid,rr-mid)){
        r=mid;
      }else{
        l=mid;
      }
    }
    ans++;
    for(int i=r;i>=l;i--){
      if(!isPa(ll+i,rr-i)){
        merge(ll+i,rr-i);
        goto end;
      }
    }
    end:{}
  }
  return ans;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=3;i<=2*n-1;i++){
    vec.push_back({read(),i});
  }
  std::sort(vec.begin(),vec.end());
  fac[0]=1;
  for(int i=1;i<=200001;i++){
    fac[i]=1ll*fac[i-1]*tt%mod;
  }
  inv[200001]=pow(fac[200001],mod-2);
  for(int i=200001-1;i>=0;i--){
    inv[i]=1ll*inv[i+1]*(tt)%mod;
  }
  for(int i=1;i<=n;i++){
    sto[i].push_back(i);
    beg[i]=i;
    A.add(i,1ll*fac[i]*i%mod);
    B.add(200000-i+1,1ll*fac[200000-i+1]*i%mod);
  }
  long long ans=0;
  for(int i=0;i<vec.size();i++){
    int ll=0,rr=0;
    if(vec[i].second%2==1){
      int siz=std::min(vec[i].second/2,n-vec[i].second/2)-1;
      ll=vec[i].second/2-siz;
      rr=vec[i].second/2+1+siz;
    }else{
      int siz=std::min(vec[i].second/2,n-vec[i].second/2+1)-1;
      ll=vec[i].second/2-siz;
      rr=vec[i].second/2+siz;
    }
    ans+=1ll*work(ll,rr)*vec[i].first;
  }
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
