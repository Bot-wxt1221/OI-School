#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
int a[1000005];
int l[1000005];
int r[1000005];
int mn[1000005];
int mx[1000005];
int premn[1000005];
int nxtmx[1000005];
int ans[1000005];
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[1000005];
  int query(int now){
    now+=2;
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    x+=2;
    while(x<=1000002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
}aa;
class node{
public:
  int x,y,c,ti;
  node(int a=0,int b=0,int cc=0,int d=0){
    x=a;
    y=b;
    c=cc;
    ti=d;
    return ;
  }
}tt[10000005];
int cnt;
std::vector<int>vec[1000005];
bool operator < (const node &a,const node &b){
  if(a.x!=b.x){
    return a.x<b.x;
  }else if(a.y!=b.y){
    return a.y<b.y;
  }
  return std::abs(a.c)>std::abs(b.c);
}
bool vised[1000005];
bool can[1000005];
inline void write(long long ans);
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    vec[i].push_back(0);
  }
  for(int i=1;i<=n;i++){
    a[i]=read();
    vec[a[i]].push_back(i);
    if(mn[a[i]]==0){
      mn[a[i]]=i;
      premn[a[i]]=mx[a[i]-1];
    }
    mx[a[i]]=i;
    if(nxtmx[a[i]+1]<mx[a[i]+1]){
      nxtmx[a[i]+1]=i;
    }
    if(vised[mx[a[i]-1]]){
      can[a[i]]=1;
    }
    if(mx[a[i]+1]){
      vised[i]=1;
    }
  }
  for(int i=1;i<=n;i++){
    vec[i].push_back(n+1);
  }
  int cntt=0;
  for(int i=1;i<=n+1;i++){
    if(mx[i]==0&&mx[i-1]){
      cntt++;
      for(int j=1;j<vec[i-1].size();j++){
        tt[++cnt]=node(vec[i-1][j-1]+1,vec[i-1][j-1]+1,-1);
        tt[++cnt]=node(vec[i-1][j-1]+1,vec[i-1][j],1);
        tt[++cnt]=node(vec[i-1][j],vec[i-1][j-1]+1,1);
        tt[++cnt]=node(vec[i-1][j],vec[i-1][j],-1);
      }
      continue;
    }
    if(mx[i]==0&&mx[i-1]==0){
      continue;
    }
    cntt++;
    if(nxtmx[i]<mx[i]){
      nxtmx[i]=n+1;
    }
    if(can[i]==0){
      tt[++cnt]=node(premn[i]+1,mx[i],-1);
      tt[++cnt]=node(premn[i]+1,nxtmx[i],1);
      tt[++cnt]=node(mn[i]+1,mx[i],1);
      tt[++cnt]=node(mn[i]+1,nxtmx[i],-1);
    }
  }
  for(int i=1;i<=m;i++){
    int l=read();
    int r=read();
    tt[++cnt]=node(l,r,0,i);
  }
  std::stable_sort(tt+1,tt+cnt+1);
  for(int i=1;i<=cnt;i++){
    if(tt[i].c!=0){
      aa.mod(tt[i].y,tt[i].c);
    }
    if(tt[i].ti!=0){
      ans[tt[i].ti]+=aa.query(tt[i].y);
    }
  }
  for(int i=1;i<=m;i++){
    write(cntt+ans[i]);
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
inline void write(long long ans){
        if(ans==0){
                putchar('0');
                putchar('\n');
                return ;
        }
        static char out[65];
        long long n=0;
        while(ans){
                out[++n]=ans%10+'0';
                ans/=10;
        }
        for(int i=n;i>=1;i--){
                putchar(out[i]);
        }
        putchar('\n');
        return ;
}
