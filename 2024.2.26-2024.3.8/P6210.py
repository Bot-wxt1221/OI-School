import math

import sys
sys.set_int_max_str_digits(999999)

def mu(n):
    ans=1
    i=2
    while i*i<=n:
        if(n%i==0):
            n=n//i
            if(n%i==0):
                return 0
            ans*=-1
        i+=1
    if(n>1):
        ans*=-1
    return ans
def f2(n,k):
    tt=min(math.sqrt(n),k)
    ans=0
    for i in range(1,int(tt)+1):
        if(n%i==0):
            ans+=(k//i)*mu(i);
            if(n/i!=i):
                ans+=(k//(n//i))*mu(n//i)
    return ans
def g(n,m,k):
    tt=min(math.sqrt(n),k)
    ans=0
    for i in range(1,int(tt)+1):
       if(n%i==0):
            ans+=f2(int(n//i),m//i)
            if(n/i!=i and n//i<=k):
                ans+=f2(int(i),m//(n//i))
    return ans
n, c, f, ll, rr = map(int, input().split())
x=g(n,n,c)
if(f%x==0):
    y=(f//x-1)*n
    f=x
else:
    y=(f//x)*n
    f=f%x
l=1
r=n
while(r-l>3):
    mid=int((l+r)/2);
    if(g(n,mid,c)<f):
        l=mid-1
    else:
        r=mid+1
while l<=r:
    if(g(n,l,c)>=f):
        print(l+y)
        break
    l+=1
print(int(g(n,rr,c)-g(n,ll-1,c)))
