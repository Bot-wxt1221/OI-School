#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
int read(){
	int x=0,f=1;
	char a=getchar();
	while(a<'0'||a>'9'){
		a=='-'?f=-1:0;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		x=(x<<3)+(x<<1)+(a^'0');
		a=getchar();
	}
	return f*x;
}
int a[300005];
int a2[300005];
int b[300005];
int b2[300005];
int c[600005];
int c2[600005];
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[1000005];
  int query(int now){
    now+=500000;
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    x+=500000;
    while(x<=1000002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x,int y){
    x+=500000;
    while(x<=1000002){
      tree[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}aa,ji,ou;
int main(){
//	freopen("robot.in","r",stdin);
//	freopen("robot.out","w",stdout);
	int T=read();
	while(T--){
		int n=read();
		for(int i=1;i<=n;i++){
			a2[i]=read();
			a[i]=read()+a[i-1];
			c[i]=a[i];
		}
		int m=read();
		for(int i=1;i<=m;i++){
			b2[i]=read();
			b[i]=read()+b[i-1];
			c[i+n]=b[i];
		}
		std::sort(c+1,c+n+m+1);
		int cnt=std::unique(c+1,c+n+m+1)-c-1;
		for(int i=1;i<=cnt;i++){
			c2[i]=b2[std::lower_bound(b+1,b+m+1,c[i])-b]-a2[std::lower_bound(a+1,a+n+1,c[i])-a];
		}
		int tans=0;
    int mx=-0x3f3f3f3f;
    int mn=0x3f3f3f3f;
    int now=0;
    for(int i=1;i<=cnt;i++){
      int nnow=now+c2[i]*(c[i]-c[i-1]);
      if(c2[i]%2==0&&c2[i]!=0){
        if(now%2==0){
          ou.mod(std::min(now,nnow),1);
          ou.mod(std::max(now,nnow)+1,-1);
          ou.mod(now,-1);
          ou.mod(now+1,1);
        }else{
          ji.mod(std::min(now,nnow),1);
          ji.mod(std::max(now,nnow)+1,-1);
          ji.mod(now,-1);
          ji.mod(now+1,1);
        }
      }else if(c2[i]!=0){
        aa.mod(std::min(now,nnow),1);
        aa.mod(std::max(now,nnow)+1,-1);
        aa.mod(now,-1);
        aa.mod(now+1,1);
      }else{
        aa.mod(now,c[i]-c[i-1]);
        aa.mod(now+1,-(c[i]-c[i-1]));
      }
      mx=std::max(mx,now);
      mn=std::min(mn,now);
      now=nnow;
      mx=std::max(mx,now);
      mn=std::min(mn,now);
    }
    for(int i=mn;i<=mx;i++){
      if(i%2==0){
        tans=std::max(tans,aa.query(i)+ou.query(i));
      }else{
        tans=std::max(tans,aa.query(i)+ji.query(i));
      }
    }
    now=0;
    aa.clear(0,1);
    for(int i=1;i<=cnt;i++){
      int nnow=now+c2[i]*(c[i]-c[i-1]);
      if(c2[i]%2==0){
        if(now%2==0){
          ou.clear(std::min(now,nnow),1);
          ou.clear(std::max(now,nnow)+1,-1);
          ou.clear(now,1);
          ou.clear(now+1,1);
        }else{
          ji.clear(std::min(now,nnow),1);
          ji.clear(std::max(now,nnow)+1,-1);
          ji.clear(now,1);
          ji.clear(now+1,1);
        }
      }else{
        aa.clear(std::min(now,nnow),1);
        aa.clear(std::max(now,nnow)+1,-1);
      }
      aa.clear(now,1);
      aa.clear(now+1,1);
      mx=std::max(mx,now);
      mn=std::min(mn,now);
      now=nnow;
      mx=std::max(mx,now);
      mn=std::min(mn,now);
    }

		printf("%d\n",tans);
	}
	return 0;
}
