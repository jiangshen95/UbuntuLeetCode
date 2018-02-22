class Solution:
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        start = len(gas)-1
        end = 0
        rest = gas[start]-cost[start]
        
        while start>end:
            if rest>=0:
                rest += gas[end]-cost[end]
                end += 1
            else:
                start -= 1
                rest += gas[start]-cost[start]
        return start if rest>=0 else -1
        
if __name__=='__main__':
    gas = list(input())
    cost = list(input())
    solution = Solution()
    print(solution.canCompleteCircuit(gas, cost))
