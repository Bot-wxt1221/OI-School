#include <iostream>
#include <cstdio>
#include <set>
#define int long long
inline int read();
int a[200005];
int lowbit(int x){
  return x&(-x);
}
std::set<int>se;
class BIT{
public:
  int tree[200005];
  int query(int now){
    now++;
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    x++;
    while(x<=200002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x,int y){
    x++;
    while(x<=200002){
      tree[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}aa;
int rev[200005];
int cnt[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("rev.in","r",stdin);
  freopen("rev.out","w",stdout);
  #endif
  int n=read();
  int q=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  se.insert(0);
  int pre=1;
  for(int i=2;i<=n;i++){
    if(a[i]==a[i-1]){
      cnt[i-1]=i-pre;
      se.insert(i-1);
      aa.mod(i-1,cnt[i-1]*(cnt[i-1]+1)/2);
      pre=i;
    }
  }
  int i=n+1;
  cnt[i-1]=i-pre;
  se.insert(i-1);
  aa.mod(i-1,cnt[i-1]*(cnt[i-1]+1)/2);
  pre=i;
  for(int i=1;i<=q;i++){
    int t=read();
    int l=read();
    int r=read();
    switch(t){
      case 1:{
        auto cur=se.lower_bound(l);
        auto cur2=se.lower_bound(l-1);
        if(cur==cur2&&l!=1){
          cur--;
          se.insert(l-1);
          aa.mod((*cur2),-(cnt[(*cur2)])*(cnt[(*cur2)]+1)/2);
          cnt[(*cur2)]=(*cur2-l+1);
          aa.mod((*cur2),cnt[(*cur2)]*(cnt[(*cur2)]+1)/2);
          cnt[l-1]=(l-(*cur)-1);
          aa.mod(l-1,cnt[l-1]*(cnt[l-1]+1)/2);
        }else if(l!=1){
          aa.mod((*cur),-(cnt[*(cur)])*(cnt[*(cur)]+1)/2);
          aa.mod((*cur2),-(cnt[*(cur2)])*(cnt[*(cur2)]+1)/2);
          cnt[*(cur)]+=cnt[*cur2];
          cnt[(*cur2)]=0;
          aa.mod((*cur),cnt[(*cur)]*(cnt[(*cur)]+1)/2);
          se.erase(cur2);
        }
        if(r==n){
          break;
        }
        cur=se.lower_bound(r+1);
        cur2=se.lower_bound(r);
        if(cur==cur2){
          cur--;
          se.insert(r);
          aa.mod((*cur2),-(cnt[(*cur2)])*(cnt[(*cur2)]+1)/2);
          int tt=cnt[*cur2]-(*cur2-r);
          cnt[(*cur2)]=(*cur2-r);
          aa.mod((*cur2),cnt[(*cur2)]*(cnt[(*cur2)]+1)/2);
          cnt[r]=tt;
          aa.mod(r,cnt[r]*(cnt[r]+1)/2);
        }else{
          aa.mod((*cur),-(cnt[*(cur)])*(cnt[*(cur)]+1)/2);
          aa.mod((*cur2),-(cnt[*(cur2)])*(cnt[*(cur2)]+1)/2);
          cnt[*(cur)]+=cnt[*cur2];
          cnt[(*cur2)]=0;
          aa.mod((*cur),cnt[(*cur)]*(cnt[(*cur)]+1)/2);
          se.erase(cur2);
        }
        break;
      }
      case 2:{
        auto cur=se.lower_bound(r);
        auto cur2=se.lower_bound(l);
        if(cur==cur2){
          printf("%lld\n",(r-l+1)*(r-l+2)/2);
          break;
        }
        cur--;
        int ans=0;
        if((*cur)>=l){
          ans+=(r-(*cur))*(r-(*cur)+1)/2;
        }
        if((*cur2)<=r){
          ans+=((*cur2)-l+1)*((*cur2)-l+2)/2;
        }
        cur2++;
        if(*cur>=*cur2){
          ans+=aa.query(*cur)-aa.query(*cur2-1);
        }
        printf("%lld\n",ans);
        break;
      }
    }
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

