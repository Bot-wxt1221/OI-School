#include <algorithm>
#include <cctype>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <queue>
inline int read();
int x1[1005];
int y1[1005];
int x2[1005];
int y2[1005];
std::queue<int>qu;
int transfer(int x,int y){
  return (x-1)*1002+y;
}
int fir[2000005];
int nxt[2000005];
int v[2000005];
int type[1005];
int tie[2000005];
int now;
void add(int x,int y){
  if(x==y){
    return ;
  }
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int sum[1005][1005];
int sum2[1005][1005];
int getsum(int x1,int y1,int x2,int y2){
  return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	#endif
  int n=read();
  int b=read();
  b++;
  memset(fir,-1,sizeof(fir));
  for(int i=1;i<=n;i++){
    x1[i]=read()+1;
    y1[i]=read()+1;
    x2[i]=read()+1;
    y2[i]=read()+1;
    if(x1[i]==x2[i]){
      assert(y1[i]!=y2[i]);
      if(y1[i]<y2[i]){
        type[i]=1;
        sum[x1[i]][y2[i]+1]-=i;
        sum[x1[i]][y1[i]]+=i;
        for(int j=y1[i];j<y2[i];j++){
          add(transfer(x1[i],j),transfer(x2[i],y2[i]));
        }
      }else{
        type[i]=2;
        sum[x1[i]][y1[i]+1]-=i;
        sum[x1[i]][y2[i]]+=i;
        for(int j=y2[i]+1;j<=y1[i];j++){
          add(transfer(x1[i],j),transfer(x2[i],y2[i]));
        }
      }
    }else{
      if(x1[i]<x2[i]){
        type[i]=3;
        sum2[y1[i]][x2[i]+1]-=i;
        sum2[y1[i]][x1[i]]+=i;
        for(int j=x1[i];j<x2[i];j++){
          add(transfer(j,y1[i]),transfer(x2[i],y2[i]));
        }
      }else{
        type[i]=4;
        sum2[y1[i]][x1[i]+1]-=i;
        sum2[y1[i]][x2[i]]+=i;
        for(int j=x2[i]+1;j<=x1[i];j++){
          add(transfer(j,y1[i]),transfer(x2[i],y2[i]));
        }
      }
    }
  }
  for(int i=1;i<=b;i++){
    for(int j=1;j<=b;j++){
      sum[i][j]+=sum[i][j-1];
      sum2[i][j]+=sum2[i][j-1];
    }
  }
  for(int i=1;i<=b;i++){
    for(int j=1;j<=b;j++){
      sum[i][j]+=sum2[j][i];
    }
  }
  for(int i=1;i<=b;i++){
    for(int j=1;j<=b;j++){
      sum[i][j]+=sum[i-1][j];
      sum[i][j]+=sum[i][j-1];
      sum[i][j]-=sum[i-1][j-1];
    }
  }
  for(int i=1;i<=n;i++){
    add(transfer(x1[i],y1[i]),transfer(x2[i],y2[i]));
    switch(type[i]){
      case 1:{
               int l=y2[i]+1;
               int r=b;
               while(r-l>3){
                 int mid=(l+r)/2;
                 if(getsum(x1[i],y2[i]+1,x1[i],mid)==0){
                   l=mid;
                 }else{
                   r=mid;
                 }
               }
               for(int mid=l;mid<=r;mid++){
                 if(getsum(x1[i],y2[i]+1,x1[i],mid)==0){
                 }else{
                   add(transfer(x2[i],y2[i]),transfer(x2[i],mid));
                   break;
                 }
               }
               break;
             }
      case 2:{
               int l=1;
               int r=y2[i]-1;
               while(r-l>3){
                 int mid=(l+r)/2;
                 if(getsum(x1[i],mid,x1[i],y2[i]-1)==0){
                   r=mid;
                 }else{
                   l=mid;
                 }
               }
               for(int mid=r;mid>=l;mid--){
                 if(getsum(x1[i],mid,x1[i],y2[i]-1)==0){
                 }else{
                   add(transfer(x2[i],y2[i]),transfer(x2[i],mid));
                   break;
                 }
               }
               break;
             }
      case 3:{
               int l=x2[i]+1;
               int r=b;
               while(r-l>3){
                 int mid=(l+r)/2;
                 if(getsum(x2[i]+1,y2[i],mid,y2[i])==0){
                   l=mid;
                 }else{
                   r=mid;
                 }
               }
               for(int mid=l;mid<=r;mid++){
                 if(getsum(x2[i]+1,y2[i],mid,y2[i])==0){
                 }else{
                   add(transfer(x2[i],y2[i]),transfer(mid,y2[i]));
                   break;
                 }
               }
               break;
             }
      case 4:{
               int l=1;
               int r=x2[i]-1;
               while(r-l>3){
                 int mid=(l+r)/2;
                 if(getsum(mid,y2[i],x2[i]-1,y2[i])==0){
                   r=mid;
                 }else{
                   l=mid;
                 }
               }
               for(int mid=r;mid>=l;mid--){
                 if(getsum(mid,y2[i],x2[i]-1,y2[i])==0){
                 }else{
                   add(transfer(x2[i],y2[i]),transfer(mid,y2[i]));
                   break;
                 }
               }
               break;
             }
    }
    if(fir[transfer(x2[i],y2[i])]==-1){
      fir[transfer(x2[i],y2[i])]=-2;
    }
  }
  int q=read();
  for(int i=1;i<=q;i++){
    int x1=read()+1;
    int y1=read()+1;
    char temp=getchar();
    while(!isprint(temp)){
      temp=getchar();
    }
    long long T;
    scanf("%lld",&T);
    while(T){
      if(fir[transfer(x1,y1)]==-1){
        if(temp=='U'){
          y1++;
        }
        if(temp=='D'){
          y1--;
        }
        if(temp=='L'){
          x1--;
        }
        if(temp=='R'){
          x1++;
        }
        T--;
        if(!(x1>0&&x1<=b&&y1>0&&y1<=b)){
          if(temp=='U'){
            y1--;
          }
          if(temp=='D'){
            y1++;
          }
          if(temp=='L'){
            x1++;
          }
          if(temp=='R'){
            x1--;
          }
          T=0;
        }
        continue;
      }else{
        break;
      }
    }
    if(T==0){
      printf("%d %d\n",x1-1,y1-1);
    }else{
      int curdis=1;
      while(T){
        int cur=transfer(x1,y1);
        if(tie[cur]){
          T%=(curdis-tie[cur]);
        }
        tie[cur]=curdis;
        qu.push(cur);
        if(fir[cur]==-2){
          int ret=getsum(x1,y1,x1,y1);
          if(type[ret]==1){
            temp='D';
          }else if(type[ret]==2){
            temp='U';
          }else if(type[ret]==3){
            temp='R';
          }else{
            temp='L';
          }
          while(T){
            if(temp=='D'){
              y1++;
            }
            if(temp=='U'){
              y1--;
            }
            if(temp=='L'){
              x1--;
            }
            if(temp=='R'){
              x1++;
            }
            T--;
            if(!(x1>0&&x1<=b&&y1>0&&y1<=b)){
              if(temp=='U'){
                y1++;
              }
              if(temp=='D'){
                y1--;
              }
              if(temp=='L'){
                x1++;
              }
              if(temp=='R'){
                x1--;
              }
              T=0;
            }
          }
        }else{
          int nxt=v[fir[transfer(x1,y1)]];
          int nxty=(nxt-1)%1002+1;
          int nxtx=(nxt-1)/1002+1;
          int addis=std::abs(x1-nxtx);
          addis+=std::abs(y1-nxty);
          if(addis>=T){
            int ret=getsum(x1,y1,x1,y1);
            if(type[ret]==1){
              temp='D';
            }else if(type[ret]==2){
              temp='U';
            }else if(type[ret]==3){
              temp='R';
            }else{
              temp='L';
            }
            while(T){
              if(temp=='D'){
                y1++;
              }
              if(temp=='U'){
                y1--;
              }
              if(temp=='L'){
                x1--;
              }
              if(temp=='R'){
                x1++;
              }
              T--;
              if(!(x1>0&&x1<=b&&y1>0&&y1<=b)){
                if(temp=='U'){
                  y1++;
                }
                if(temp=='D'){
                  y1--;
                }
                if(temp=='L'){
                  x1++;
                }
                if(temp=='R'){
                  x1--;
                }
                T=0;
              }
              continue;
            }
          }else{
            T-=addis;
            curdis+=addis;
            x1=nxtx;
            y1=nxty;
          }
        }
      }
      printf("%d %d\n",x1-1,y1-1);
      while(qu.size()>0){
        tie[qu.front()]=0;
        qu.pop();
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
