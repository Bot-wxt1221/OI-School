#include <cinttypes>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <random>
#include <cstring>
#define int __int128
int ops,k,x,x2;
inline int read();
int l[8000005];
int r[8000005];
class op{
  public:
    int a,b;
    int tl,tr;
    int vl,vr;
    int isa;
    op(int x=0,int y=0,bool c=0){
      a=x;
      b=y;
      isa=c;
      vl=vr=0;
      tl=tr=0;
      return ;
    }
}a[8000005];
const bool operator < (const op &a,const op &b){
  return a.a==b.a?a.b<b.b:a.a<b.a;
}
int pow(int x,int y,int z){
  int ans=1;
  int cur=x;
  while(y){
    if(y&1){
      ans*=cur;
      ans%=z;
    }
    y>>=1;
    cur*=cur;
    cur%=z;
  }
  return ans;
}
int ans[1000005];
int tt[8000005],tt2[8000005];
int cnt,cnt2;
int modd,modd2;
int rnn[1000005];
void dfs(int now,int cur){
  if(a[now].tl==a[now].tr){
    cur*=rnn[a[now].tl];
    ans[a[now].tl]=cur;
    cnt+=tt[a[now].tl]*(cur)%modd;
    cnt%=modd;
    cnt2+=tt2[a[now].tl]*(cur)%modd2;
    cnt2%=modd2;
    return ;
  }
  dfs(a[now].tl,cur*a[now].vl);
  dfs(a[now].tr,cur*a[now].vr);
  return ;
}
void calc(int base,int base2,int mod,int mod2,int rev,int mtree){
  std::mt19937 rnd(time(NULL));
  modd=mod;
  modd2=mod2;
  while(1){
    int prel=0,prer=(1<<k)-1;
    int ttt=1;
    int ttt2=1;
    for(int i=0;i<(1<<k);i++){
      tt[i]=ttt;
      rnn[i]=rnd()%2+1;
      if(i==0){
        rnn[i]=1;
      }
      tt2[i]=ttt2;
      a[i]=op(ttt*rnn[i],ttt2*rnn[i],i==0);
      ttt*=base;
      ttt%=mod;
      ttt2*=base2;
      ttt2%=mod2;
      a[i].tl=a[i].tr=i;
    }
    int chk=0;
    int tt=1;
    for(int i=0;i<(1<<k);i++){
      chk+=(tt*(('d')))%mod;
      chk%=mod;
      tt*=base;
      tt%=mod;
    }
    a[0].a+=(chk-x+mod)%mod;
    a[0].a%=mod;
    tt=1;
    int bkchk=chk;
    chk=0;
    for(int i=0;i<(1<<k);i++){
      chk+=(tt*(('d')))%mod2;
      chk%=mod2;
      tt*=base2;
      tt%=mod2;
    }
    a[0].b+=(chk-x2+mod2)%mod2;
    a[0].b%=mod2;
    int curt=prer+1;
    for(int tk=0;tk<k;tk++){
      int tt=prer+1;
      if(tk<mtree){
      }else{
        std::sort(a+prel,a+prer+1);
      }
      for(int i=0,cur=prel;i<(1<<k);i+=(1<<(tk+1)),cur+=2){
        int op2=0;
        if(a[cur+1].a-a[cur].a==0){
          op2=a[cur+1].b<a[cur].b;
        }else{
          op2=a[cur+1].a<a[cur].a;
        }
        if(rnd()%1000000000<=ops){
          a[++curt]=op(a[cur].a+a[cur+1].a,a[cur].b+a[cur+1].b);
          a[curt].isa+=a[cur].isa;
          a[curt].isa+=a[cur+1].isa;
          a[curt].tl=cur;
          a[curt].vl=a[curt].vr=1;
          a[curt].tr=cur+1;

        }else if(op2){
          a[++curt]=op(a[cur].a-a[cur+1].a,a[cur].b-a[cur+1].b);
          a[curt].isa+=a[cur].isa;
          a[curt].isa-=a[cur+1].isa;
          a[curt].tl=cur;
          a[curt].vl=1;
          a[curt].vr=-1;
          a[curt].tr=cur+1;
        }else{
          a[++curt]=op(a[cur+1].a-a[cur].a,a[cur+1].b-a[cur].b);
          a[curt].isa-=a[cur].isa;
          a[curt].isa+=a[cur+1].isa;
          a[curt].tl=cur;
          a[curt].tr=cur+1;
          a[curt].vl=-1;
          a[curt].vr=1;
        }
        if(a[curt].isa==1&&a[curt].a==0&&a[curt].b==0){
          cnt=bkchk;
          cnt2=chk;
          memset(ans,0,sizeof(ans));
          dfs(curt,1);
          if(x==cnt&&x2==cnt2){
            return ;
          }
        }
      }
      prel=tt;
      prer=curt;
    }
  }
  return ;
}

signed main(){
  int mod,mod2,base,base2,rev,mtree;
  fprintf(stderr,"p1:\n");mod=read();
	fprintf(stderr,"base1:\n");base=read();
	fprintf(stderr,"p2:\n");mod2=read();
	fprintf(stderr,"base2:\n");base2=read();
    fprintf(stderr,"x:\n");x=read();
    fprintf(stderr,"x2:\n");x2=read();
    fprintf(stderr,"rev:\n");rev=read();
	
    fprintf(stderr,"k:\n");k=read();
	fprintf(stderr,"ops:\n");ops=read();
	fprintf(stderr,"mtree:\n");mtree=read();
  //base=base2=read();
  //mod=mod2=read();
  //x=x2=read();
  //ops=0;
  //k=13;
  //rev=0;
  //ops=1000000;
  //mtree=1;
  calc(base,base2,mod,mod2,rev,mtree);
  for(int i=(1<<k)-1;i>=0;i--){
    printf("%c",(char)((ans[i])+'d'));
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
