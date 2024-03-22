#include<cstdio>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
ll x1,y1,x2,y2,x,y;
ll extend_gcd(ll a,ll b,ll &x,ll &y)
{ 
    ll d=a;
    if(b!=0)
    {
        d=extend_gcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else 
    {
        x=1;
        y=0;
    }
    return d;
}
ll linear(ll a,ll b,ll c)//求解一元线性同余方程ax=b(mod c)
{
    ll x,y;
    ll g=extend_gcd(a,c,x,y);
    if(b%g)//无解 
        return -1;
    x=x*(b/g);
    ll mod=c/g;
    x=(x%mod+mod)%mod;
    return x;
}
ll solve()
{
    ll fx,fy,tx,ty;
    fx=(x1==x2),fy=(y1==y2);
    tx=(2*x-(x1+x2))/2,ty=(2*y-(y1+y2))/2;
    if(fx&&fy)return 0;
    if(fx)return ty;
    if(fy)return tx;
    ll ans=linear(x,ty-tx,y);
    if(ans==-1)return INF;
    return tx+ans*x;
}
int main()
{
    int T,res=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&x,&y,&x1,&y1,&x2,&y2);
        x*=2,y*=2,x1*=2,y1*=2,x2*=2,y2*=2;
        ll t=solve();
        printf("Case #%d:\n",res++);
        if(t==INF)printf("Collision will not happen.\n");
        else
        {
            ll xx=t+x1,yy=t+y1;
            if((xx/x)%2==0)xx%=x;
            else xx=((x-xx)%x+x)%x;
            if((yy/y)%2==0)yy%=y;
            else yy=((y-yy)%y+y)%y;
            printf("%.1lf %.1lf\n",xx/2.0,yy/2.0);
        }
    }
    return 0;
}
