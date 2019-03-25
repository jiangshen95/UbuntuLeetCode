class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        num = (rand7() - 1) * 7 + rand7()
        return num % 10 + 1 if num <= 40 else self.rand10()
