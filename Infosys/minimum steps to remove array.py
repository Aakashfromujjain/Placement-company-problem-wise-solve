n=int (input())
arr=list(map (int , input().split() ))

ans=0
arr.sort()

while len(arr) != 0:
    if arr[0] != arr[-1]:
        arr.pop()
        arr.pop(0)
    else:
        arr.pop(0)
    ans+=1
print(ans)
