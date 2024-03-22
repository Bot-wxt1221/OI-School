import math


n=int(input())
k=0
s=0
pri=1
for i in range(1,n+1,1):
    di=int(input())
    if(di!=-1):
        k=k+1
        s=s+di-1
        pri=pri*math.factorial(di-1)
ans=math.factorial(n-2)//(math.factorial(s)*math.factorial(n-2-s))
ans=int(ans)
ans=ans*(n-k)**(n-2-s)
print(int(ans*math.factorial(s)//pri))
