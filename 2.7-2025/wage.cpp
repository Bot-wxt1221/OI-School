#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define MAXD 18
#define MAXX (1<<18)
#define mod 998244353
#define inv2 (mod+1)/2
inline int read();
int ww[1000005];
int line[35];
void insert(int now){
	for(int i=30;i>=0;i--){
		if(now&(1<<i)){
			if(line[i]){
				now^=line[i];
			}else{
				line[i]=now;
				return ;
			}
		}
	}
	return ;
}
int query(int now){
	for(int i=30;i>=0;i--){
		if(now&(1<<i)){
		}else{
			now^=line[i];
		}
	}
	return now;
}
int fir[1000005];
int nxt[2000005];
int v[2000005];
int w[2000005];
int now;
void add(int x,int y,int z){
	v[++now]=y;
	w[now]=z;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
void dfs(int now,int fa){
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(ww[v[i]]!=-1){
			insert(ww[v[i]]^ww[now]^w[i]);
		}else{
			ww[v[i]]=ww[now]^w[i];
			dfs(v[i],now);
		}
	}
	return ;
}

void xxor(int *f,int V,int n) {
  for(int k=1;k*2<=V;k=k<<1){
    for(int i=0;i<V;i+=k*2) {
      for(int j=0;j<k;j++) {
        auto x=f[i+j];
        auto y=f[i+j+k];
        f[i+j]=x+y;
        f[i+j+k]=x-y;
      }
    }
  }
}
int p1[1000005],p2[1000005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("wage.in","r",stdin);
	freopen("wage.out","w",stdout);
	#endif
	int test_num=read();
	int n=read();
	int m=read();
	int q=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	memset(ww,-1,sizeof(ww));
	for(int i=1;i<=m;i++){
		int u=read();
		int v=read();
		int w=read();
		add(u,v,w);
		add(v,u,w);
	}
	ww[1]=0;
	dfs(1,1);
  for(int i=1;i<=n;i++){
    p1[ww[i]<<1^ww[i]]=1;
  }
  for(int i=0;i<=30;i++){
    for(int j=0;j<MAXX;j++){
      p1[j^(line[i]<<1)]|=p1[j];
    }
  }
  xxor(p1,MAXX,1);
	for(int i=1;i<=q;i++){
		int s=read();
		int t=read();
		int d=read();
		int k=read();
    memset(p2,0,sizeof(p2));
    p2[d^ww[s]]=1;
    int ans=0;
    for(int j=1;j<=k;j++){
      for(int ii=MAXX/2-1;ii>=0;ii--){
        p2[ii*2]=p2[ii];
        p2[ii*2+1]=0;
      }
      xxor(p2,MAXX,1);
      for(int ii=0;ii<MAXX;ii++){
        p2[ii]*=p1[ii];
        p2[ii]%=mod;
      }
      xxor(p2,MAXX,inv2);
      bool tt=0;
      for(int ii=0;ii<MAXX;ii++){
        p2[ii]=!!p2[ii];
        if(p2[ii]&&(ii&(1<<(MAXD-1)))){
          tt=1;
        }
      }
      ans=(ans<<1)|(tt<<(MAXD-1));
      if(tt){
        for(int iii=(1<<(MAXD-1));iii<MAXX;iii++){
          p2[iii^(1<<(MAXD-1))]=p2[iii];
          p2[iii]=0;
        }
      }
    }
    int ans2=0;
    for(int ii=0;ii<(1<<(MAXD-1));ii++){
      if(p2[ii]){
        p2[ii]=0;
        ans2=std::max(ans2,query(ii^ww[t]));
      }
    }
    printf("%lld\n",(long long)(ans+ans2));
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
