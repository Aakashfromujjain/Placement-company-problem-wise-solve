# Python program to check if a number 
# is Tidy or not.

# Returns true if num is Tidy
def isTidy(num):

    # To store previous digit (Assigning
    # initial value which is more than any
    # digit)
    prev = 10
    
    # Traverse all digits from right to
    # left and check if any digit is
    # smaller than previous.
    while (num):
        rem = num % 10
        num /= 10
        if rem > prev:
            return False
        prev = rem
    return True

# Driver code
num = 1556
if isTidy(num):
    print("Yes")
else:
    print("No")

# This code is contributed by Sharad_Bhardwaj.
