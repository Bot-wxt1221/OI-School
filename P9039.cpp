#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
char temp1[100005];
char temp2[100005];
int fir[100005];
int nxt[200005];
int v[200005];
int kk[100005];
int now;
std::vector<int>tt12,tt22;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  tt12.push_back(temp1[now]);
  tt22.push_back(temp2[now]);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
  }
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    tt12.clear();
    tt22.clear();
    now=0;
    int n=read();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
      kk[i]=0;
    }
    bool tt=0;
    bool tt2=0;
    bool tt3=0;
    int temp;
    scanf("%s",temp1+1);
    scanf("%s",temp2+1);
    if(memcmp(temp1+1,temp2+1,n)==0){
      for(int i=1;i<=(2*(n-1));i++){
        read();
      }
      printf("TAK\n");
      goto end;
    }
    for(int i=2;i<=n;i++){
      if(temp1[i]!=temp1[i-1]){
        tt3=1;
      }
    }
    for(int i=1;i<n;i++){
      int a=read();
      int b=read();
      kk[a]++;
      kk[b]++;
      if(temp2[a]==temp2[b]){
        tt2=1;
      }
      add(a,b);
      add(b,a);
    }
    for(int i=1;i<=n;i++){
      if(kk[i]>2){
        tt=1;
      }
      if(kk[i]==1){
        temp=i;
      }
    }
    if(!tt2||!tt3){
      printf("NIE\n");
      goto end;
    }
    if(!tt){
      dfs(temp,temp);
      int cur=0;
      for(int i=1;i<=n;i++){
        if(i>1&&tt22[i-1]==tt22[i-2]){
          continue;
        }
        while(cur<tt12.size()&&tt22[i-1]!=tt12[cur]){
          cur++;
          continue;
        }
        if(cur==tt12.size()||tt22[i-1]!=tt12[cur]){
          printf("NIE\n");
          goto end;
        }
      }
    }else{
      printf("TAK\n");
      goto end;
    }
    printf("TAK\n");
    end:{}
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
