#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
inline int read();
int p[200005];
char temp[200005];
bool yes[200005];
int valmn[200005];
int valmx[200005];
int mnst[200005][21];
int mxst[200005][21];
int cnt[200005*8];
int mn[200005*8];
int mx[200005*8];
bool ans[200005*8];
void merge(int now){
  cnt[now]=cnt[now*2]+cnt[now*2+1];
  ans[now]=ans[now*2]&&ans[now*2+1];
  mn[now]=0x3f3f3f3f;
  mx[now]=0;
  if(cnt[now*2]!=0&&cnt[now*2+1]!=0){
    ans[now]&=(mx[now*2]<=mn[now*2+1]);
  }
  if(cnt[now*2]!=0){
    mn[now]=std::min(mn[now],mn[now*2]);
    mx[now]=std::max(mx[now],mx[now*2]);
  }
  if(cnt[now*2+1]!=0){
    mn[now]=std::min(mn[now],mn[now*2+1]);
    mx[now]=std::max(mx[now],mx[now*2+1]);
  }
  return ;
}
void build(int now,int l,int r){
  if(l==r){
    ans[now]=1;
    if(yes[l]==0){
      cnt[now]=0;
    }else{
      mx[now]=valmx[l];
      mn[now]=valmn[l];
      cnt[now]=1;
    }
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  merge(now);
  return ;
}
int ql;
void mod(int now,int l,int r){
  if(ql<l||r<ql){
    return ;
  }
  if(l==r){
    ans[now]=1;
    if(yes[l]==0){
      cnt[now]=0;
    }else{
      mx[now]=valmx[l];
      mn[now]=valmn[l];
      cnt[now]=1;
    }
    return ;
  }
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  merge(now);
  return ;
}
int getmn(int l,int r){
  int lgsiz=std::log2(r-l+1);
  return std::min(mnst[l][lgsiz],mnst[(r-(1<<lgsiz)+1)][lgsiz]);
}
int getmx(int l,int r){
  int lgsiz=std::log2(r-l+1);
  return std::max(mxst[l][lgsiz],mxst[(r-(1<<lgsiz)+1)][lgsiz]);
}
std::set<int>se;
int n;
void del(int tt){
  auto ttt=se.find(tt);//suf
  ttt--;
  auto pre=ttt;
  ttt++;
  se.erase(ttt);
  ttt=pre;
  ttt++;
  yes[tt]=0;
  ql=tt;
  mod(1,1,n);
  valmn[*ttt]=getmn(*pre+1,*ttt);
  valmx[*ttt]=getmx(*pre+1,*ttt);
  ql=*ttt;
  mod(1,1,n);
  return ;
}
void add(int tt){
  auto ttt=se.lower_bound(tt);
  ttt--;
  auto pre=ttt;
  ttt++;
  se.insert(tt);
  valmx[*ttt]=getmx(tt+1,*ttt);
  valmn[*ttt]=getmn(tt+1,*ttt);
  ql=*ttt;
  mod(1,1,n);
  yes[tt]=1;
  valmx[tt]=getmx(*pre+1,tt);
  valmn[tt]=getmn(*pre+1,tt);
  ql=tt;
  mod(1,1,n);
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    se.clear();
    n=read();
    int q=read();
    for(int i=1;i<=n;i++){
      p[i]=read();
      mxst[i][0]=mnst[i][0]=p[i];
      yes[i]=0;
    }
    for(int i=1;i<=20;i++){
      for(int j=1;j+(1<<(i))-1<=n;j++){
        mxst[j][i]=std::max(mxst[j][i-1],mxst[j+(1<<(i-1))][i-1]);
        mnst[j][i]=std::min(mnst[j][i-1],mnst[j+(1<<(i-1))][i-1]);
      }
    }
    scanf("%s",temp+1);
    temp[n+1]='R';
    int pre=0;
    se.insert(0);
    for(int i=2;i<=n+1;i++){
      if(temp[i-1]=='L'&&temp[i]=='R'){
        yes[i]=1;
        se.insert(i-1);
        int ll=pre+1;
        int rr=i-1;
        pre=i-1;
        yes[i-1]=1;
        valmn[i-1]=getmn(ll,rr);
        valmx[i-1]=getmx(ll,rr);
      }else{
        yes[i-1]=0;
      }
    }
    build(1,1,n);
    for(int i=1;i<=q;i++){
      int tt=read();
      if(temp[tt-1]=='L'&&temp[tt]=='R'){
        del(tt-1);
      }
      if(temp[tt]=='L'&&temp[tt+1]=='R'){
        del(tt);
      }
      if(temp[tt]=='R'&&temp[tt+1]=='R'){
        add(tt);
      }
      if(temp[tt-1]=='L'&&temp[tt]=='L'){
        add(tt-1);
      }
      if(temp[tt]=='L'){
        temp[tt]='R';
      }else{
        temp[tt]='L';
      }
      if(ans[1]){
        printf("YES\n");
      }else{
        printf("NO\n");
      }
    }
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
