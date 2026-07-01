import sys
n=int(input())
c=0
m=-sys.maxsize-1
while n:
    n-=1
    a=int(input())
    if a>m:
        m=a
        c+=1
print(c)
