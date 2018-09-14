class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.list = nestedList

    def next(self):
        """
        :rtype: int
        """
        return self.list.pop(0).getInteger()

    def hasNext(self):
        """
        :rtype: bool
        """
        while self.list:
            if self.list[0].isInteger():
                return True
            t = self.list.pop(0)
            self.list = t.getList() + self.list
        return False
