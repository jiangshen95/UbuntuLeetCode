class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        nums = list(range(1,n+1))
        result = ''
        
        non = 1
        for i in range(1,n):
            non*=i
        
        m = n-1
        while m>0:
            i = int((k-1)/non)
            result+=str(nums[i])
            nums.remove(nums[i])
            k -= i*non
            non = int(non/m)
            m-=1
        result+=str(nums[0])
        
        return result
        
if __name__=='__main__':
    n=int(input())
    k=int(input())
    solution = Solution()
    result = solution.getPermutation(n, k)
    print(result)
