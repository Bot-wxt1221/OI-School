#include<bits/stdc++.h>
using namespace std;
#define db double
#define inf 1e9
#define eps 1e-9
const int N=100005;
int n,s[N];db dp[N];
struct node{db k,x,y,a,b,r;int id;}Q[N],kl[N];
db getk(int i,int j) {
    if(fabs(Q[i].x-Q[j].x)<=eps) return inf;
    return (Q[j].y-Q[i].y)/(Q[j].x-Q[i].x);
}
void merge(int l,int r,int mid) {//归并排序
    int t1=l,t2=mid+1;
    for(int i=l;i<=r;++i)
        if(t1<=mid&&(t2>r||Q[t1].x<Q[t2].x+eps)) kl[i]=Q[t1],++t1;
        else kl[i]=Q[t2],++t2;
    for(int i=l;i<=r;++i) Q[i]=kl[i];
}
void cdq(int l,int r) {
    if(l==r) {//那么在l之前的所有询问都已经处理完毕，可以更新l的答案了
        dp[l]=max(dp[l],dp[l-1]);
        Q[l].y=dp[l]/(Q[l].a*Q[l].r+Q[l].b),Q[l].x=Q[l].y*Q[l].r;
        return;
    }
    int mid=(l+r)>>1,t1=l-1,t2=mid,top=0;
    for(int i=l;i<=r;++i)//把前mid个询问放在左边，后mid个放在右边
        if(Q[i].id<=mid) kl[++t1]=Q[i];
        else kl[++t2]=Q[i];
    for(int i=l;i<=r;++i) Q[i]=kl[i];
    cdq(l,mid);//递归处理左边
    for(int i=l;i<=mid;++i) {//维护斜率递减的凸包
        while(top>=2&&getk(s[top],i)+eps>getk(s[top-1],s[top])) --top;
        s[++top]=i;
    }
    for(int i=mid+1;i<=r;++i) {//处理右边的询问
        while(top>=2&&getk(s[top-1],s[top])<=Q[i].k+eps) --top;
        int j=s[top];
        dp[Q[i].id]=max(dp[Q[i].id],Q[j].x*Q[i].a+Q[j].y*Q[i].b);
    }
    cdq(mid+1,r),merge(l,r,mid);//递归处理右边后，按照x值为关键字归并排序
}
int cmp1(node t1,node t2) {return t1.k<t2.k;}
int main() 
{
    scanf("%d%lf",&n,&dp[0]);
    for(int i=1;i<=n;++i) {
        scanf("%lf%lf%lf",&Q[i].a,&Q[i].b,&Q[i].r);
        Q[i].k=-Q[i].a/Q[i].b,Q[i].id=i;
    }
    sort(Q+1,Q+1+n,cmp1),cdq(1,n);
    printf("%.3lf\n",dp[n]);
    return 0;
}
