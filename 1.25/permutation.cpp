#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
bool prime[3000005];
int lst[3000005];
int cho[3000005];
std::deque<int>deq;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	#endif
  int n=read();
  int cnt=0;
  if(n<=18){
		if(n==4) std::cout<<"2\n2 4";
		if(n==5) std::cout<<"2\n2 4";
		if(n==6) std::cout<<"4\n2 4 6 3";
		if(n==7) std::cout<<"4\n2 4 6 3";
		if(n==8) std::cout<<"5\n8 2 4 6 3";
		if(n==9) std::cout<<"6\n2 4 8 6 3 9";
		if(n==10) std::cout<<"8\n5 10 2 4 8 6 3 9";
		if(n==11) std::cout<<"8\n5 10 8 2 4 6 3 9";
		if(n==12) std::cout<<"9\n5 10 12 8 2 4 6 3 9";
    if(n==13){
      std::cout<<"9\n5 10 6 3 9 12 2 4 8";
    }
    if(n==14){
      std::cout<<"11\n7 14 6 3 9 12 2 4 8 10 5";
    }
    if(n==15){
      std::cout<<"12\n7 14 10 5 15 6 3 9 12 2 4 8";
    }
    if(n==16){
      std::cout<<"13\n7 14 10 5 15 6 3 9 12 2 4 8 16";
    }
    if(n==17){
      std::cout<<"13\n7 14 10 5 15 6 3 9 12 2 4 8 16";
    }
    if(n==18){
      std::cout<<"14\n7 14 10 5 15 6 3 9 18 12 2 4 8 16\n";
    }
    return 0;
  }
  for(int i=2;i<=n;i++){
    if(!prime[i]){
      lst[++cnt]=i;
      cho[i*3]=1;
    }
    for(int j=1;j<=cnt;j++){
      if((1ll*i*lst[j])>n){
        break;
      }
      prime[i*lst[j]]=1;
      if(i%lst[j]==0){
        continue;
      }
    }
  }
  int pian1=0;
  int pian2=0;
  int asns=0;
  int cntt=0;
  int oo=0;
  for(int i=3;i<=n;i+=2){
    int ans=0;
    for(int j=i;j<=n;j+=2*i){
      if(cho[j]){
        continue;
      }
      cho[j]=i;
      ans++;
    }
    if(ans==0){
      continue;
    }
    if((i*2)<=n&&(i*3)>n){
      cntt++;
      if(cntt==1){
        pian1=ans;
        asns++;
        deq.push_front(i*2);
        cho[i*2]=1;
        for(int j=i;j<=n;j+=2*i){
          if(cho[j]==i){
            deq.push_front(j);
            asns++;
          }
        }
      }else if(cntt==2){
        pian2=ans;
        cho[i*2]=1;
        asns++;
  if(n>=18&&!cho[18]){
    cho[18]=1;
    asns++;
    deq.push_back(18);
  }
        for(int i=2;i<=n;i+=2){
          if(cho[i]==0){
            deq.push_back(i);
            asns++;
            cho[i]=1;
          }
        }
        deq.push_back(i*2);
        for(int j=i;j<=n;j+=2*i){
          if(cho[j]==i){
            deq.push_back(j);
          }
        }
      }
    }else if((i*2)<=n&&(i*3)<=n){
      asns+=ans;
      if(oo){
        deq.push_back(i*2);
        cho[i*2]=1;
      }else{
        if(i==3){
          deq.push_back(i*4);
          cho[i*4]=1;
        }
        deq.push_back(i*3);
        cho[i*3]=1;
      }
      asns+=2;
      for(int j=i;j<=n;j+=2*i){
        if(cho[j]==i){
          deq.push_back(j);
        }
      }
      if(!oo){
        deq.push_back(i*2);
        cho[i*2]=1;
      }else{
        if(i==3){
          deq.push_back(i*4);
          cho[i*4]=1;
        }
        deq.push_back(i*3);
        cho[i*3]=1;
      }
      oo^=1;
    }
  }
  asns+=pian1;
  asns+=pian2;
  if(n>=18&&!cho[18]){
    cho[18]=1;
    asns++;
    deq.push_back(18);
  }
  for(int i=2;i<=n;i+=2){
    if(cho[i]==0){
      deq.push_back(i);
      asns++;
      cho[i]=1;
    }
  }

  printf("%d\n",int(deq.size()));
  for(int i=0;i<deq.size();i++){
    printf("%d ",deq[i]);
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


