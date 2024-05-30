#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int fir[4000005];
int nxt[8000005];
int v[8000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int ans=0x3f3f3f3f3f3f3f3f;
int dissum[4000005];
int cnt[4000005];
int lowbit(int x){
  return x&(-x);
}
class Tree{
  public:
    int tree[10000005];
    int query(int x){
      x=std::min(x,10000001ll);
      int ans=0x3f3f3f3f3f3f3f3f;
      while(x>0){
        ans=std::min(ans,tree[x]);
        x-=lowbit(x);
      }
      return ans;
    }
    void mod(int x,int y){
      while(x<=10000001){
        tree[x]=std::min(tree[x],y);
        x+=lowbit(x);
      }
      return ;
    }
    Tree(){
      for(int i=1;i<=10000001;i++){
        tree[i]=0x3f3f3f3f3f3f3f3f;
      }
      return ;
    }
}a,b,c;
int n;
int _max[1000005];
int num[1000005];
int _max2[1000005];
int maxdis[1000005];
bool leaf[1000005];
int up[1000005];
std::pair<int,int> tttt[1000005];
void dfs(int now,int fa){
  int cntt=0;
  leaf[now]=1;
  _max[now]=_max2[now]=-0x3f3f3f3f3f3f3f3f;
  num[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    leaf[now]=0;
    dfs(v[i],now);
    if(_max[v[i]]+1>=_max[now]){
      _max2[now]=_max[now];
      _max[now]=_max[v[i]]+1;
      num[now]=v[i];
    }else if(_max[v[i]]+1>=_max2[now]){
      _max2[now]=_max[v[i]]+1;
    }
        cntt++;
    cnt[now]+=cnt[v[i]];
    dissum[now]+=dissum[v[i]];
  }
  dissum[now]+=cnt[now];
  if(cntt==0){
    _max[now]=0;
    cnt[now]=1;
    dissum[now]=0;
  }
  return ;
}
int ndis;int cntt;
int ttt=0;
int ttttt[1000005];
void dfs2(int now,int fa){
  if(leaf[now]){
    return ;
  }
  maxdis[now]=std::max(maxdis[now],_max[now]);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    int bkttt=ttt;
    if(num[now]==v[i]){
      ttt=std::max(ttt+1,_max2[now]+1);
    }else{
      ttt=std::max(ttt+1,_max[now]+1);
    }
    maxdis[v[i]]=std::max(_max[v[i]],ttt);
    ndis+=(cnt[1]-cnt[v[i]]);
    ndis-=cnt[v[i]];
    dfs2(v[i],now);
    ndis-=(cnt[1]-cnt[v[i]]);
    ndis+=cnt[v[i]];
    ttt=bkttt;
  }
  if(cntt==1&&now==1){
    return ;
  }
  tttt[now]=std::make_pair(0x3f3f3f3f3f3f3f3f-((maxdis[now]*cnt[1]-ndis)/2),now);
  if(maxdis[now]%2){
    b.mod(maxdis[now],-(((maxdis[now]*cnt[1]-ndis)/2)*2)+maxdis[now]*cnt[1]);
  }else{
    c.mod(maxdis[now],-(((maxdis[now]*cnt[1]-ndis)/2)*2)+maxdis[now]*cnt[1]);
  }
  return ;
}
void dfs3(int now,int fa){
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs3(v[i],now);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("tree12.in","r",stdin);
  freopen("tree.out","w",stdout);
  #endif
  n=read();
  for(int i=1;i<=n+n-1;i++){
    fir[i]=-1;
  }
  cntt=0;
  for(int i=1;i<n;i++){
    int a=read();
    int b=read();
    if(a==1||b==1){
      cntt++;
    }
    add(a,i+n);
    add(i+n,a);
    add(i+n,b);
    add(b,i+n);
  }
  dfs(1,1);
  ndis=dissum[1];
  if(cntt==1){
    cnt[1]++;
  }
  dfs2(1,1);
  if(cntt==1){
    leaf[1]=1;
  }
  std::sort(tttt+1,tttt+2*n);
  int cnttt=0;
  for(int i=1;i<=2*n-1;i++){
    if(leaf[tttt[i].second]||tttt[i].second==0){
      continue;
    }
    a.mod(++cnttt,maxdis[tttt[i].second]);
    ttttt[cnttt]=tttt[i].first;
  }
  int q=read();
  for(int i=1;i<=q;i++){
    int k=read();
    int l=1,r=10000000;
    int pos=std::lower_bound(ttttt+1,ttttt+cnttt+1,0x3f3f3f3f3f3f3f3f-k+1)-ttttt-1;
    int anss=a.query(pos);
    if(ttttt[pos]>0x3f3f3f3f3f3f3f3f-k){
      anss=0x3f3f3f3f3f3f3f3f;
    }
    while(r-l>3){
      int mid=(l+r)/2;
      int ans=anss;
      int tt=2*k+(b.query(mid-1));
      tt=tt/cnt[1]+((tt%cnt[1])>0);
      if(tt%2==0){
        tt++;
      }
      ans=std::min(ans,tt);
      if(c.query(mid-1)){
        goto end2;
      }
      tt=2*k+(c.query(mid-1));
      tt=tt/cnt[1]+((tt%cnt[1])>0);
      if(tt%2){
        tt++;
      }
      ans=std::min(ans,tt);
    end2:{}
      if(ans<mid){
        r=mid+1;
      }else{
        l=mid-1;
      }
    }
    for(int ii=l;ii<=r;ii++){
      int ans=anss;
      if(b.query(ii-1)==0x3f3f3f3f3f3f3f3f){
        int tt;
        if(c.query(ii-1)==0x3f3f3f3f3f3f3f3f){
          goto end;
        }
        tt=2*k+(c.query(ii-1));
        tt=tt/cnt[1]+((tt%cnt[1])>0);
        if(tt%2){
          tt++;
        }
        ans=std::min(ans,tt);
      }else{
        int tt=2*k+(b.query(ii-1));
        tt=tt/cnt[1]+((tt%cnt[1])>0);
        if(tt%2==0){
          tt++;
        }
        ans=std::min(ans,tt);
        if(c.query(ii-1)==0x3f3f3f3f3f3f3f3f){
          goto end;
        }
        tt=2*k+(c.query(ii-1));
        tt=tt/cnt[1]+((tt%cnt[1])>0);
        if(tt%2){
          tt++;
        }
        ans=std::min(ans,tt);
      }
      end:{}
      if(ans!=0x3f3f3f3f3f3f3f3f&&ans>=ii){
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


