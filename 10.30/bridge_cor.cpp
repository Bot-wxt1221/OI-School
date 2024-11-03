#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
inline int read();
int sta[1000005];//1-> no forever 2 -> yes forever 0 -> ???
int fa[1000005];
int to[1000005];
bool vised[1000005];
int a[35];
int b[35];
int getfa(int x){
  return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
class edge{
public:
  int x,y,z,i;
  edge(int a=0,int b=0,int c=0,int d=0){
    x=a;
    y=b;
    z=c;
    i=d;
    return ;
  }
}seq[500005];
std::vector<edge>vec;
std::vector<int>left;
bool operator < (edge a,edge b){
  return a.z<b.z;
}
int fa2[1000005];
int getfa2(int x){
  return fa2[x]==x?x:fa2[x]=getfa2(fa2[x]);
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=m;i++){
    seq[i].x=read();
    seq[i].y=read();
    seq[i].z=read();
    seq[i].i=i;
  }
  std::sort(seq+1,seq+m+1);
  for(int i=1;i<=n;i++){
    fa[i]=i;
  }
  for(int i=1;i<=m;i++){
    to[seq[i].i]=i;
    int x=seq[i].x;
    int y=seq[i].y;
    if(getfa(x)==getfa(y)){
      sta[i]=1;
      continue;
    }
    fa[getfa(x)]=getfa(y);
  }
  for(int i=1;i<=n;i++){
    fa[i]=i;
  }
  int q=read();
  for(int i=1;i<=q;i++){
    a[i]=read();
    b[i]=read();
    int num=to[a[i]];
    int x=seq[num].x;
    int y=seq[num].y;
    fa[getfa(x)]=getfa(y);
    num=to[b[i]];
    x=seq[num].x;
    y=seq[num].y;
    fa[getfa(x)]=getfa(y);
  }
  for(int i=1;i<=m;i++){
    int x=seq[i].x;
    int y=seq[i].y;
    if(getfa(x)==getfa(y)){
      continue;
    }
    sta[i]=2;
    fa[getfa(x)]=getfa(y);
  }
  for(int i=1;i<=n;i++){
    fa[i]=i;
  }
  int base=0;
  int ans=0x3f3f3f3f;
  for(int i=1;i<=m;i++){
    if(sta[i]==0){
      vec.push_back(seq[i]);
    }else if(sta[i]==2){
      fa[getfa(seq[i].x)]=getfa(seq[i].y);
      base+=seq[i].z;
    }
  }
  int leftn=0;
  for(int i=1;i<=n;i++){
    if(getfa(i)==i){
      left.push_back(i);
      leftn++;
    }
  }
  for(int sta=0;sta<(1<<q);sta++){
    int curans=base;
    for(int i=0;i<left.size();i++){
      fa2[left[i]]=left[i];
    }
    int siz=leftn;
    for(int i=1;i<=q;i++){
      if(!(sta&(1<<(i-1)))){
        int num=to[a[i]];
        int x=getfa(seq[num].x);
        int y=getfa(seq[num].y);
        if(getfa2(x)==getfa2(y)){
          curans+=seq[num].z*(::sta[num]!=2&&vised[num]==0);
          vised[num]=1;
          continue;
        }
        vised[num]=1;
        siz--;
        curans+=seq[num].z;
        fa2[getfa2(x)]=getfa2(y);
      }else{
        int num=to[b[i]];
        int x=getfa(seq[num].x);
        int y=getfa(seq[num].y);
        if(getfa2(x)==getfa2(y)){
          curans+=seq[num].z*(::sta[num]!=2&&vised[num]==0);
          vised[num]=1;
          continue;
        }
        vised[num]=1;
        siz--;
        curans+=seq[num].z;
        fa2[getfa2(x)]=getfa2(y);
      }
    }
    for(int i=1;i<=q;i++){
      vised[to[a[i]]]=0;
      vised[to[b[i]]]=0;
    }
    for(int i=0;i<vec.size();i++){
      int x=getfa(vec[i].x);
      int y=getfa(vec[i].y);
      if(getfa2(x)==getfa2(y)){
        continue;
      }
      siz--;
      curans+=vec[i].z;
      fa2[getfa2(x)]=getfa2(y);     
    }
    if(siz==1){
      ans=std::min(ans,curans);
    }
  }
  if(ans==0x3f3f3f3f){
    printf("mumuyibarenkoumumumu");
    return 0;
  }
  printf("%d",ans);
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
