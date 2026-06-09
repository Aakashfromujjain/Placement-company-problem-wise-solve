s="prepbytes"
list_s=list(s)
n=len(list_s)

for i in range(n):
    for j in range(n):
        if(list_s[i]<list_s[j]):
            list_s[i] , list_s[j] = list_s[j] , list_s[i]
s="".join(list_s)
print(s)
