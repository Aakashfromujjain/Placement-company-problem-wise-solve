def cnt(s):
    up,lo =0,0
    for ch in s:
        if 'A'<=ch <='Z':
            up+=1
        elif 'a'<=ch<='z':
            lo+=1
  
    return up,lo
s=input().strip()
u,l=cnt(s)
print(f"uppercase:{u} lowercase:{l}")
