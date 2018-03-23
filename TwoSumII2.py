class Solution:
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        for i, num in enumerate(numbers):
            if target-num in dic:
                return [dic[target-num] + 1, i + 1]
            dic[num] = i
                
if __name__=='__main__':
    numbers = list(input())
    target = int(raw_input())
    
    solution = Solution()
    print(solution.twoSum(numbers, target))
