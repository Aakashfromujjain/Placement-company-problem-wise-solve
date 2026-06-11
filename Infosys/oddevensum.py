def sum_even_odd(n):
    even_sum = 0
    odd_sum = 0
    for digit in str(n):
        d = int(digit)
        if d % 2 == 0:
            even_sum += d
        else:
            odd_sum += d
    return even_sum, odd_sum

n = int(input())
e, o = sum_even_odd(n)
print(e, o)
