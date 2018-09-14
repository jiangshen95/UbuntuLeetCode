class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        def make_list(nestedList):
            for x in nestedList:
                if x.isInteger():
                    self.list.append(x.getInteger())
                else:
                    make_list(x.getList())
        self.list = []
        make_list(nestedList)

    def next(self):
        """
        :rtype: int
        """
        return self.list.pop(0)

    def hasNext(self):
        """
        :rtype: bool
        """
        return True if self.list else False