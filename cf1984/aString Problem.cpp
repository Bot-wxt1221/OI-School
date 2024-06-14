#include <cstring>
#include <iostream>
#include <cstdio>
inline int read();
char temp[300005];
int fir[300005];
int magic[300005];
int tt[15][300005];
int pow(int x,int y,int mod){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pow(x,y/2,mod);
    return (1ll*tt*tt)%mod;
  }
  return (1ll*pow(x,y-1,mod)*x)%mod;
}
int inv(int y,int md){
  return tt[md][y];
}
int mod[15]={0,100000007,100000039,100000193,100000223,100000259,100000073,100000399,100000661,1000000801,1000000753};
int lowbit(int x){
  return x&(-x);
}
int tn;
class BIT{
public:
  int tree[300005];
  int md;
  int query(int now){
    now++;
    int ans=0;
    while(now>0){
      ans+=tree[now];
      ans%=md;
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    x++;
    while(x<=tn){
      tree[x]+=y;
      tree[x]%=md;
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x,int y=0){
    x++;
    while(x<=tn){
      tree[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}aa[15];
void init(int n){
  for(int i=1;i<=7;i++){
    long long tt=1;
    aa[i].md=mod[i];
    for(int j=1;j<=n;j++){
      aa[i].mod(j,(1ll*tt*(temp[j]-'a'+1))%mod[i]);
      tt*=27;
      tt%=mod[i];
    }
  }
  return ;
}
void clear(int n){
  for(int i=1;i<=7;i++){
    long long tt=1;
    aa[i].md=mod[i];
    for(int j=1;j<=n;j++){
      aa[i].clear(j);
      tt*=27;
      tt%=mod[i];
    }
  }
}
bool yes(int l1,int l2,int r1,int r2){
  if(l2-l1!=r2-r1){
    return 0;
  }
  for(int i=1;i<=7;i++){
    long long tt1=(aa[i].query(l2)-aa[i].query(l1-1))*1ll*inv(l1-1,i)%mod[i];
    long long tt2=(aa[i].query(r2)-aa[i].query(r1-1))*1ll*inv(r1-1,i)%mod[i];
    tt1+=mod[i];
    tt1%=mod[i];
    tt2+=mod[i];
    tt2%=mod[i];
    if(tt1!=tt2){
      return 0;
    }
  }
  return 1;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  for(int i=1;i<=7;i++){
    magic[i]=pow(27,mod[i]-2,mod[i]);
    tt[i][0]=1;
    long long tt=1;
    for(int j=1;j<=200000;j++){
      tt*=27;
      tt%=mod[i];
      ::tt[i][j]=pow(tt,mod[i]-2,mod[i]);
    }
  }
  while(T--){
    scanf("%s",temp+1);
    int n=strlen(temp+1);
    tn=n+1;
    fir[n+1]=n+1;
    for(int i=n;i>=1;i--){
      if(temp[i]=='a'){
        fir[i]=fir[i+1];
      }else{
        fir[i]=i;
      }
    }
    if(fir[1]==n+1){
      printf("%d\n",n-1);
      continue;
    }
    init(n);
    long long ttans=0;
    for(int siz=1;siz<=n;siz++){
      int tt=fir[1];
      int mn=tt-1;
      if(tt+siz-1<=n){
        int nl=tt,nr=tt+siz-1;
        int cur=tt;
        int lst=0x3f3f3f3f;
        while(cur+siz-1<=n){
          if(yes(nl,nr,cur,cur+siz-1)==0){
            goto end;
          }
          mn=std::min(mn,lst);
          lst=fir[cur+siz]-(cur+siz);
          cur=fir[cur+siz];
        }
        if(fir[cur]!=n+1){
          goto end;
        }
        ttans+=mn+1;
      }
      end:{}
    }
    clear(n);
    printf("%lld\n",ttans);
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
