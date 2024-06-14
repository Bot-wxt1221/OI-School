#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,a[maxn],s1,s2,ans[maxn],p[maxn],q[maxn];
int mod[100005];
int to[100005];
bool yes[100005];
void solve(){
    for(int i=1;i<=n;i++){
      to[a[i]]=i;
      yes[i]=0;
      mod[i]=0;
    }
    int ans=0;
    for(int i=n;i>=1;i--){
      if(mod[to[i]+1]||mod[to[i]-1]||to[i]==n||to[i]==1){
        continue;
      }
      ans++;
      mod[to[i]]=ans;
      yes[i]=1;
    }
    int cnt=0;
    for(int i=n;i>=1;i--){
      if(mod[to[i]]==0){
        cnt++;
        mod[to[i]]=cnt;
      }
    }
    for(int i=n;i>=1;i--){
      if(yes[i]){
        mod[to[i]]+=cnt;
      }
    }
    for(int i=1;i<=n;i++){
    //  printf("%d ",mod[i]);
      ::ans[i]=mod[i];
    }
return ;
}
int stdd(){
    for(int i=1;i<=n;i++) p[i]=i;
    int ress=0;
    do{
        for(int i=1;i<=n;i++) q[i]=p[i]+a[i];
        int s=0;
        for(int i=2;i<n;i++) s+=(q[i]>q[i-1]&&q[i]>q[i+1]);
        ress=max(ress,s);
    }while(next_permutation(p+1,p+n+1));
    return ress;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    for(n=2;;n+=2){
        for(int i=1;i<=n;i++) a[i]=i;
        do{
            solve();
            int s=0;
            for(int i=2;i<n;i++) s+=(ans[i]+a[i]>ans[i-1]+a[i-1]&&ans[i]+a[i]>ans[i+1]+a[i+1]);
            if(s!=stdd()){
                cout<<"Wrong Answer,data:"<<endl<<n<<endl;
                for(int i=1;i<=n;i++) cout<<a[i]<<" ";
                cout<<endl<<"Answer number:"<<stdd()<<endl;
                cout<<"Your Answer number:"<<s<<endl;
                cout<<"Your Answer preutation:"<<endl;
                for(int i=1;i<=n;i++) cout<<ans[i]<<" "; 
                exit(0);
            }
        }while(next_permutation(a+1,a+n+1));
        cout<<"n="<<n<<" permutation:Accepted"<<endl;
    }
    return 0;
}
