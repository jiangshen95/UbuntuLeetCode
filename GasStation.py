class Solution:
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        total = 0
        tank = 0
        start = 0
        for i in range(len(gas)):
            tank += gas[i]-cost[i]
            if tank<0:
                total += tank
                start = i+1
                tank = 0
        return -1 if total+tank<0 else start
        
if __name__=='__main__':
    gas = list(input())
    cost = list(input())
    solution = Solution()
    print(solution.canCompleteCircuit(gas, cost))
