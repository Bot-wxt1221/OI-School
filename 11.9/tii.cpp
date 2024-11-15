#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int __int128
inline int read();
char temp[500005];
std::pair<int,int>pa[500005];
int pre[500005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  int cnt=0;
  while(T--){
    int n=read();
    int p=0;
    scanf("%s",temp+1);
    int siz=strlen(temp+1);
    if(temp[1]=='1'){
      p+=100000;
    }
    for(int i=3;i<=siz;i++){
      p*=10;
      p+=temp[i]-'0';
    }
    for(int i=siz-2;i<5;i++){
      p*=10;
    }
    scanf("%s",temp+1);
    for(int i=1;i<=n;i++){
      pre[i]=pre[i-1]+temp[i]-'0';
    }
    for(int i=1;i<=n;i++){
      pa[i]={(p*i-pre[i]*100000ll),i};
    }
    pa[n+1]={0,0};
    pa[n+2]={0,-1};
   std::sort(pa+1,pa+n+2);
    int ret=n+1;
    for(int i=1;i<=n;i++){
      if(pa[i].second<pa[i+1].second){
        if(ret==n+1||(pa[i+1].first-pa[i].first)*(pa[ret+1].second-pa[ret].second)<(pa[ret+1].first-pa[ret].first)*(pa[i+1].second-pa[i].second)){
          ret=i;
        }
      }
    }
    int st=0x3f3f3f3f;

    for(int i=1;i<=n;i++){
      if(pa[i].second<pa[i+1].second){
        if(ret==n+1||(pa[i+1].first-pa[i].first)*(pa[ret+1].second-pa[ret].second)==(pa[ret+1].first-pa[ret].first)*(pa[i+1].second-pa[i].second)){
          st=std::min(st,pa[i].second+1);
          st=std::min(st,pa[i+1].second);
        }
      }
    }
    std::pair<std::pair<int,int> ,std::pair<int,int> > tt1={pa[ret],pa[ret+1]};
    for(int i=1;i<=n;i++){
      pre[i]=pre[i-1]+((temp[i]-'0')^1);
    }
    for(int i=1;i<=n;i++){
      pa[i]={((100000ll-p)*i-pre[i]*100000ll),i};
    }
    pa[n+2]={0,-1};
    pa[n+1]={0,0};
    std::sort(pa+1,pa+n+2);
    ret=-1;
    for(int i=1;i<=n;i++){
      if(pa[i].second<pa[i+1].second){
        if(ret==-1||(pa[i+1].first-pa[i].first)*(pa[ret+1].second-pa[ret].second)<(pa[ret+1].first-pa[ret].first)*(pa[i+1].second-pa[i].second)){
          ret=i;
        }
      }
    }
    int st2=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
      if(pa[i].second<pa[i+1].second){
        if(ret==-1||(pa[i+1].first-pa[i].first)*(pa[ret+1].second-pa[ret].second)==(pa[ret+1].first-pa[ret].first)*(pa[i+1].second-pa[i].second)){
          st2=std::min(st2,pa[i].second+1);
          st2=std::min(st2,pa[i+1].second);
        }
      }
    }
    if(tt1.second.second==-1&&ret==-1){
      printf("%d\n",1);
    }else if(tt1.second.second==-1){
      printf("%d\n",st2);
    }else if(ret==-1){
      printf("%d\n",st);
    }else{
      if((tt1.first.first-tt1.second.first)*(pa[ret].second-pa[ret+1].second)<(pa[ret].first-pa[ret+1].first)*(tt1.first.second-tt1.second.second)){
        printf("%d\n",st);
      }else if((tt1.first.first-tt1.second.first)*(pa[ret].second-pa[ret+1].second)>(pa[ret].first-pa[ret+1].first)*(tt1.first.second-tt1.second.second)){
        printf("%d\n",st2);
      }else{
        printf("%d\n",std::min(st,st2));
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
