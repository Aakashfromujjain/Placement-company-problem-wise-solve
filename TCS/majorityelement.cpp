class Solution:
    def majorityElement(self, arr):
        #code here
        count = 0
        ele = 0     
        # store the elements beign counted, when becomes 0
        
        for num in arr:
            if count == 0:
                ele = num
                count = 1
                
            elif ele == num:
                count += 1
            
            else: count -= 1
        
        # varify
        counter = arr.count(ele)
            
        if counter > len(arr)//2:
                return ele
        
        return -1
