#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
inline int read();
int fir[5005];
int nxt[20005];
int v[20005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
std::queue<int>qu;
bool bl[5005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  int anss=0;
  for(int i=1;i<=n;i++){
    memset(bl,0,sizeof(bl));
    bl[i]=1;
    qu.push(i);
    int ans=0;
    while(qu.size()>0){
      ans++;
      if(qu.size()==1){
        int tp=qu.front();
        qu.pop();
        for(int i=fir[tp];i!=-1;i=nxt[i]){
          if(bl[v[i]]){
            continue;
          }
          bl[v[i]]=1;
          qu.push(v[i]);
        }
      }else{
       int tp=qu.front();
        qu.pop();
        for(int i=fir[tp];i!=-1;i=nxt[i]){
          if(bl[v[i]]){
            continue;
          }
          bl[v[i]]=1;
          qu.push(v[i]);
        }
        tp=qu.front();
        qu.pop();
        for(int i=fir[tp];i!=-1;i=nxt[i]){
          if(bl[v[i]]){
            continue;
          }
          bl[v[i]]=1;
          qu.push(v[i]);
        }
      }
    }
    anss=std::max(anss,ans);
  }
  printf("%d",anss-1);
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


