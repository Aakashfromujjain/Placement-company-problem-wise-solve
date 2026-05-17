n=str(input())
d=str(input())

ans=[]
for i in range(len(n)):
  if n[i]==d:
    t=n[0:i] + n[(i+1)]:]
    ans.append(int (t))
print(str(max(ans)))
