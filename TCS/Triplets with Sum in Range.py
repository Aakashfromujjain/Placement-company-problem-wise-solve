class Solution:
    def countTriplets(self, arr: list[int], l: int, r: int) -> int:
        from bisect import bisect_left,bisect_right
        arr.sort()
        lth=len(arr)
        ret=0
        for i in range(lth-2):
            for j in range(i+1,lth-1):
                ll=l-arr[i]-arr[j]
                rr=r-arr[i]-arr[j]
                lll=bisect_left(arr,ll,j+1)
                rrr=bisect_right(arr,rr,j+1)
                ret+=rrr-lll
        return ret
