#include <iostream>
#include <cstdio>
#define int long long
inline int read();
char temp[300005];
int hash[500005];
int invhash[500005];
int pw[500005];
int inv[500005];
int base=131;
int mod=900000041;
int ans2[500005][30];
int pow(int x,int y){
  int ans=1;
  while(y){
    if(y&1){
      ans*=x;
      ans%=mod;
    }
    y>>=1;
    x*=x;
    x%=mod;
  }
  return ans;
}
int calcA(int l,int r){
  return (1ll*(hash[r]-hash[l-1])*inv[l]%mod+mod)%mod;
}
int calcB(int l,int r){
  return (1ll*(invhash[r]-invhash[l-1])*inv[500000-r+1]%mod+mod)%mod;
}
int pat1[500005];
int pat2[500005];
int lowbit(int x){
  return x&(-x);
}
int calcLCP(int l1,int r1,int l2,int r2){//l r T
  if(l1>r1||l2>r2){
    return 0;
  }
  int l=1,r=std::min(r1-l1+1,r2-l2+1);
  while(r-l>3){
    int mid=(l+r)/2;
    if(calcA(l2,l2+mid-1)==calcB(r1-mid+1,r1)){
      l=mid;
    }else{
      r=mid;
    }
  }
  for(int mid=r;mid>=l;mid--){
    if(calcA(l2,l2+mid-1)==calcB(r1-mid+1,r1)){
      return mid;
    }
  }
  return 0;
}
class BIT{
public:
  int tree[500005];
  int query(int x){
    return tree[x];
  }
  void add(int x,int y){
    tree[x]+=y;
  }
}A;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  if(n==1){
    printf("1\na");
    return 0;
  }
  scanf("%s",temp+1);
  pw[0]=1;
  int rans=0;
  for(int i=1;i<=500000;i++){
    pw[i]=1ll*pw[i-1]*base%mod;
  }
  inv[500000]=pow(pw[500000],mod-2);
  for(int i=500000-1;i>=0;i--){
    inv[i]=1ll*inv[i+1]*base%mod;
  }
  for(int i=1;i<=n;i++){
    hash[i]=hash[i-1];
    hash[i]+=1ll*pw[i]*(temp[i]-'a'+2)%mod;
    hash[i]%=mod;
    invhash[i]=invhash[i-1];
    invhash[i]+=1ll*pw[500000-i+1]*(temp[i]-'a'+2);
    invhash[i]%=mod;
  }
  for(int i=1;i<=n;i++){ //around i
    int l=1,r=std::min(i-1,n-i);
    while(r-l>3){
      int mid=(l+r)/2;
      if(calcA(i-mid,i+mid)==calcB(i-mid,i+mid)){
        l=mid;
      }else{
        r=mid;
      }
    }
    for(int mid=r;mid>=l;mid--){
      if(calcA(i-mid,i+mid)==calcB(i-mid,i+mid)){
        pat1[i]=mid;
        break;
      }
    }
    rans+=pat1[i]+1;
    A.add(i-pat1[i],1);
    A.add(i+1,-2);
    A.add(i+pat1[i]+2,1);
    if(i-pat1[i]>1&&i+pat1[i]<n){
      int anss=calcLCP(1,i-pat1[i]-2,i+pat1[i]+2,n)+1;
      ans2[i-pat1[i]-1][temp[i+pat1[i]+1]-'a']+=anss;
      ans2[i+pat1[i]+1][temp[i-pat1[i]-1]-'a']+=anss;
    }
  }
  for(int i=2;i<=n;i++){
    //i-1 & i
    int l=1,r=std::min(i-1,n-i+1);
    while(r-l>3){
      int mid=(l+r)/2;
      if(calcA(i-mid,i+mid-1)==calcB(i-mid,i+mid-1)){
        l=mid;
      }else{
        r=mid;
      }
    }
    pat2[i]=0;
    for(int mid=r;mid>=l;mid--){
      if(calcA(i-mid,i+mid-1)==calcB(i-mid,i+mid-1)){
        pat2[i]=mid;
        break;
      }
    }
    rans+=pat2[i];
    if(pat2[i]>0){
      A.add(i-pat2[i],1);
      A.add(i,-1);
      A.add(i+1,-1);
      A.add(i+pat2[i]+1,1);
    }
    if(i-pat2[i]-2>=0&&i+pat2[i]+1<=n+1){
      int anss=calcLCP(1,i-pat2[i]-2,i+pat2[i]+1,n)+1;
      ans2[i-pat2[i]-1][temp[i+pat2[i]]-'a']+=anss;
      ans2[i+pat2[i]][temp[i-pat2[i]-1]-'a']+=anss;
    }
  }
  int xans=rans;
  int op1=-1,op2=-1;
  for(int i=1;i<=n;i++){
    A.tree[i]+=A.tree[i-1];
  }
  for(int i=1;i<=n;i++){
    A.tree[i]+=A.tree[i-1];
  }
  for(int i=n;i>=1;i--){
    for(int j=temp[i]-1;j>='a';j--){
      int nans=rans;
      if(temp[i]==j){
        continue;
      }
      nans-=A.query(i);
      nans+=pat1[i]+1;
      nans+=ans2[i][j-'a'];
      if(nans>=xans){
        xans=nans;
        op1=i;
        op2=j;
      }
    }
  }
  for(int i=n;i>=1;i--){
    for(int j=temp[i]+1;j<='z';j++){
      int nans=rans;
      if(temp[i]==j){
        continue;
      }
      nans-=A.query(i);
      nans+=pat1[i]+1;
      nans+=ans2[i][j-'a'];
      if(nans>xans){
        xans=nans;
        op1=i;
        op2=j;
      }
    }
  }
  printf("%lld\n",xans);
  if(op1!=-1){
    temp[op1]=op2;
  }
  printf("%s",temp+1);
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
