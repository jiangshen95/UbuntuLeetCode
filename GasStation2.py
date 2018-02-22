class Solution:
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        start = 0
        rest = 0
        subsum = 1000000000
        for i in range(len(gas)):
            rest += gas[i]-cost[i]
            if rest<subsum:
                subsum = rest
                start = i+1
        return start%len(gas) if rest>=0 else -1
        
if __name__=='__main__':
    gas = list(input())
    cost = list(input())
    solution = Solution()
    print(solution.canCompleteCircuit(gas, cost))
