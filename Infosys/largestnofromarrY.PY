from functools import cmp_to_key

def largestNumber(nums):
    # Convert all integers to strings
    str_nums = list(map(str, nums))
    
    # Custom comparator function
    def compare(a, b):
        if a + b > b + a:
            return -1  # a should come before b
        elif a + b < b + a:
            return 1   # b should come before a
        return 0
    
    # Sort using custom comparator
    str_nums.sort(key=cmp_to_key(compare))
    
    # Join strings together
    result = "".join(str_nums)
    
    # Edge case: If the array consists only of zeros, return "0" instead of "000..."
    return "0" if result[0] == "0" else result

# Test case matching the image
sample_input = [1, 34, 3, 98, 9, 76, 45, 4]
print("Python Output:", largestNumber(sample_input)) 
# Output: 998764543431
