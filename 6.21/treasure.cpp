#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
inline int read();
int a[35];
std::set<int>se;
std::vector<std::pair<std::pair<int,int>,std::pair<int,int> > >vec,vec2;
int lowbit(int x){
  return x&(-x);
}
int seq[10000005];
std::pair<int,int> temp2,temp;
class BIT{
  public:
    int tree[20000005];
    std::pair<int,int> num[20000005];
    int query(int x){
      x++;
      int ans=-0x3f3f3f3f;
      while(x>0){
        ans=std::max(ans,tree[x]);
        if(ans==tree[x]){
          temp=num[x];
        }
        x-=lowbit(x);
      }
      return ans;
    }
    void mod(int x,int y){
      x++;
      while(x<=20000002){
        tree[x]=std::max(tree[x],y);
        if(y==tree[x]){
          num[x]=temp2;
        }
        x+=lowbit(x);
      }
    }
}t1;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("treasure.in","r",stdin);
  freopen("treasure.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  int cnt=0;
  for(int i=0;i<(1<<(n/2));i++){
    int aa=0;
    for(int s=i;;s=(s-1)&i){
      if(aa==1){
        break;
      }
      if(s==0){
        aa=1;
      }
      int x=0,y=0,z=0;
      int sx=0,sy=0,sz=0;
      for(int j=1;j<=n/2;j++){
        if(i&(1<<(j-1))){
          if(s&(1<<(j-1))){
            x+=a[j];
            sx|=(1<<(j-1));
          }else{
            y+=a[j];
            sy|=(1<<(j-1));
          }
        }else{
          z+=a[j];
          sz|=(1<<(j-1));
        }
      }
      int ti=0,ts=0;
      for(int j=1;j<=n/2;j++){
        if((1<<(j-1))&sy){
          ti|=(1<<(j-1));
        }else if((1<<(j-1))&sz){
          ti|=(1<<(j-1));
          ts|=(1<<(j-1));
        }
      }
      vec.push_back(std::make_pair(std::make_pair(x-y,y-z),std::make_pair(ti,ts)));
      seq[++cnt]=y-z;
      if(ti==1&&ts==1){
        std::cerr<<' ';
      }
    }
  }
  memset(t1.tree,-0x3f,sizeof(t1.tree));
  std::sort(vec.begin(),vec.end());
  for(int i=0;i<(1<<(n-n/2));i++){
    int aa=0;
    for(int s=i;;s=(s-1)&i){
      if(aa==1){
        break;
      }
      if(s==0){
        aa=1;
      }
      int x=0,y=0,z=0;
      int sx=0,sy=0,sz=0;
      for(int j=n/2+1;j<=n;j++){
        if(i&(1<<(j-n/2-1))){
          if(s&(1<<(j-1-n/2))){
            x+=a[j];
            sx|=(1<<(j-n/2-1));
          }else{
            y+=a[j];
            sy|=(1<<(j-n/2-1));
          }
        }else{
          z+=a[j];
          sz|=(1<<(j-n/2-1));
        }
      }
      int ti=0,ts=0;
      for(int j=n/2+1;j<=n;j++){
        if((1<<(j-n/2-1))&sy){
          ti|=(1<<(j-n/2-1));
        }else if((1<<(j-n/2-1))&sz){
          ti|=(1<<(j-n/2-1));
          ts|=(1<<(j-n/2-1));
        }
      }
      vec2.push_back(std::make_pair(std::make_pair(y-x,z-y),std::make_pair(ti,ts)));
      seq[++cnt]=z-y;
    }
  }
  std::sort(seq+1,seq+cnt+1);
  cnt=std::unique(seq+1,seq+cnt+1)-seq-1;
  std::sort(vec2.begin(),vec2.end());
  int ans=0x3f3f3f3f,sta,sta2,sta3,sta4;
  int ti=0;
  for(int i=0;i<vec2.size();i++){
    while(ti<vec.size()&&vec[ti].first.first<=vec2[i].first.first){
//      se.insert(vec[ti].first+vec[ti].second);
      temp2=vec[ti].second;
      t1.mod(std::lower_bound(seq+1,seq+cnt+1,vec[ti].first.second)-seq,vec[ti].first.first+vec[ti].first.second);
      ti++;
    }
    int ttt=0;
    ans=std::min(ans,ttt=(-t1.query(std::lower_bound(seq+1,seq+cnt+1,vec2[i].first.second)-seq)+vec2[i].first.first+vec2[i].first.second));
    if(ttt==ans){
      sta3=vec2[i].second.first;
      sta4=vec2[i].second.second;
      sta=temp.first;
      sta2=temp.second;
    }
  }
  for(int i=1;i<=n/2;i++){
    printf("%d ",((sta&1)+(sta2&1)+1));
    sta>>=1;
    sta2>>=1;
  }
  for(int i=n/2+1;i<=n;i++){
    printf("%d ",1+(sta3&1)+(sta4&1));
    sta3>>=1;
    sta4>>=1;
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
