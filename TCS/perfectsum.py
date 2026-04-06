def is_perfect(n):
    sum = 0
    for i in range(1, n):
        if n % i == 0:
            sum += i
    return sum == n

n = int(input())
#print("Perfect" if is_perfect(n) else "Not Perfect")
if is_perfect(n):
    print("Perfect")
else:
    print("not perfect")
