#include <iostream>
#include <cstdio>
inline int read();
int a[(1<<15)+5];
int b[(1<<15)+5];
int fir[25];
int seq[25];
int nxt[55];
int v[55];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
}
int faa[25];
int dep[25];
void dfs(int now,int fa){
  faa[now]=fa;
  dep[now]=dep[fa]+1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
  }
  return ;
}
int getlca(int x,int y){
  while(x!=y){
    if(dep[x]>dep[y]){
      std::swap(x,y);
    }
    y=faa[y];
  }
  return x;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    seq[i]=read();
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
  }
  dfs(1,1);
  b[0]=1;
  for(int i=0;i<(1<<n);i++){
    int ti=-1;
    int sum=0;
    for(int j=1;j<=n;j++){
      if((1<<(j-1))&i){
        sum+=seq[j];
        sum%=m;
      }
      for(int k=1;k<=n;k++){
        if((1<<(j-1))&i){
          if((1<<(k-1))&i){
            if(j!=k){
            int cur=getlca(j,k);
            if(ti==-1||ti==cur){
              ti=cur;
              continue;
            }else{
              a[i]=0;
              goto end;
            }
            }
          }
        }
      }
    }
    a[i]=sum;
    end:{}
    for(int j=i;j;j=(j-1)&i){
      b[i]+=1ll*a[j]*b[i^j]%m;
      b[i]%=m;
    }
  }
  printf("%d",b[((1<<(n))-1)]);
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
