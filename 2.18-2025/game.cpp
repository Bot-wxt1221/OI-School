#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
inline int read();
std::unordered_map<int,int>mp;
int seq[3000005];
int a[3000005];
int b[3000005];
int ans[3000005];
int ql[3000005];
int qr[3000005];
int val[3000005];
std::vector<int>vec[1<<21];
int buc[1<<21];
int sum[3000005][35];
int getcnt(int l,int v){
  auto itl=std::lower_bound(vec[v].begin(),vec[v].end(),l);
  if(itl==vec[v].end()){
    return 0;
  }
  return (itl-vec[v].begin())&1;
}
void solve(int i,int o){
  int prea=a[qr[i]]^a[ql[i]-1];
  int preb=b[qr[i]]^b[ql[i]-1];
  if(preb==0){
    if(prea!=(1<<o)-1){
      ans[i]=1;
    }
    return ;
  }
  if(mp.count(preb)){
    int x=mp[preb];
    if(getcnt(ql[i],x)){
      prea^=x;
    }
    if((prea^x)!=(1<<o)-1){
      ans[i]=1;
    }
    return ;
  }else{
    ans[i]=1;
    for(int ii=0;ii<32;ii++){
      if(preb&(1<<(ii))){
        int t=sum[qr[i]][ii]^sum[ql[i]-1][ii];
        if(mp.count(t)&&mp.count(preb^t)){
          int x=mp[t];
          int y=mp[preb^t];
          if(getcnt(ql[i],x)){
            prea^=x;
          }
          if(getcnt(ql[i],y)){
            prea^=y;
          }
          if((prea^x)==((1<<o)-1)){
            ans[i]=0;
          }
          if((prea^y)==((1<<o)-1)){
            ans[i]=0;
          }
        }
        return ;
      }
    }
    return ;
  }
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  read();
  srand(time(NULL));
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    seq[i]=read();
  }
  for(int i=0;i<(1ll<<m);i++){
    val[i]=rand();
    mp[val[i]]=i;
  }
  int q=read();
  for(int i=1;i<=q;i++){
    ql[i]=read();
    qr[i]=read();
  }
  for(int o=m;o>=1;o--){
    for(int i=0;i<(1ll<<(m-o+1));i++){
      vec[i].clear();
      buc[i]=0;
    }
    for(int i=1;i<=n;i++){
      int cur=seq[i]>>(o-1);
      a[i]=a[i-1];
      b[i]=b[i-1];
      buc[cur]++;
      if(buc[cur]%2==0){
        a[i]^=cur;
      }
      b[i]^=val[cur];
      vec[cur].push_back(i);
      for(int j=0;j<32;j++){
        sum[i][j]=sum[i-1][j];
        if(val[cur]&(1ll<<j)){
          sum[i][j]^=val[cur];
        }
      }
    }
    for(int i=1;i<=q;i++){
      if(ans[i]){
        continue;
      }
      solve(i,(m-o+1));
      if(ans[i]){
        ans[i]=o;
      }
    }
  }
  for(int i=1;i<=q;i++){
    printf("%d\n",ans[i]);
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
