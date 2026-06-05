def Binarysum():
    #no of test cases
    t=int(input("Enter no of pairs"))
    max_sum=0

    for _ in range(t):
        m,n =input().split()

        decimal_m = int(m,2)
        decimal_n = int(n,2)

        current_sum=decimal_m + decimal_n

        if current_sum>max_sum:
            max_sum = current_sum
    return bin(max_sum)[2:]
