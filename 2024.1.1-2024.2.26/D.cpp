#include <clocale>
#include <iostream>
#include <cstdio>
inline int read();
void merge(int a1,int b1,int a2,int b2,int &c1,int &c2){
  c1=0;
  c2=0;
  for(int i=0;i<10;i++){
    if(a1&(1<<i)){
      c1|=b2&(1<<i);
    }else{
      c1|=a2&(1<<i);
    }
    if(b1&(1<<i)){
      c2|=b2&(1<<i);
    }else{
      c2|=a2&(1<<i);
    }
  }
  return ;
}
int tree1[1600005];
int tree2[1600005];
int a[1600005];
int b[1600005];
void init(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(l==r){
    tree1[now]=a[l];
    tree2[now]=b[l];
    return ;
  }
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  merge(tree1[now*2],tree2[now*2],tree1[now*2+1],tree2[now*2+1],tree1[now],tree2[now]);
  return ;
}
int pos;
void update(int now,int l,int r){
  if(r<pos||pos<l){
    return ;
  }
  if(l==pos&&pos==r){
    tree1[now]=a[l];
    tree2[now]=b[l];
    return ;
  }
  int mid=(l+r)/2;
  update(now*2,l,mid);
  update(now*2+1,mid+1,r);
  merge(tree1[now*2],tree2[now*2],tree1[now*2+1],tree2[now*2+1],tree1[now],tree2[now]);
  return ;
}
int bb[1600005];
int kind[1600005];
char temp[15];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=n;i++){
    scanf("%s",temp+1);
    bb[i]=read();
    if(temp[1]=='A'){
      a[i]=0&bb[i];
      b[i]=1023&bb[i];
    }else if(temp[1]=='O'){
      a[i]=0|bb[i];
      b[i]=1023|bb[i];
    }else{
      a[i]=0^bb[i];
      b[i]=1023^bb[i];
    }
  }
  init(1,1,n);
  for(int i=1;i<=m;i++){
    int op=read();
    if(op==1){
      int x=read();
      int ans=0;
      for(int j=0;j<10;j++){
        if(x&(1<<j)){
          ans|=tree2[1]&(1<<j);
        }else{
          ans|=tree1[1]&(1<<j);
        }
      }
      printf("%d\n",ans);
    }else{
      int x=read();
      scanf("%s",temp+1);
      bb[x]=read();
      if(temp[1]=='A'){
        a[x]=0&bb[x];
        b[x]=1023&bb[x];
      }else if(temp[1]=='O'){
        a[x]=0|bb[x];
        b[x]=1023|bb[x];
      }else{
        a[x]=0^bb[x];
        b[x]=1023^bb[x];
      }
      pos=x;
      update(1,1,n);
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


