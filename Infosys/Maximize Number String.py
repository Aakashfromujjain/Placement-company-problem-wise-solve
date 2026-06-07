def maximizeNumstring(num: str,digit: str)->str:
    last_idx = -1
    n=len(num)

    for i in range(n):
        if num[i] == digit:
            last_idx = i

            if i+1 < n and num[i+1] > digit:
                return num[:i] + num[i+1:]

    return num[:last_idx] + num[last_idx+1:]

#test cases
num_str="1321"
target_digit ='1'
print ("Maximize String: ",maximizeNumstring (num_str , target_digit))
