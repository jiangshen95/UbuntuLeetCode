class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []
        
class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    dic = {}
    def cloneGraph(self, node):
        if node == None:
            return None
        if node in dic:
            return dic[node]
        copy = UndirectedGraphNode(node.label)
        dic[node] = copy
        for neighbor in node.neighbors:
            copy.neighbors.append(cloneGraph(neighbor))
        return copy
        
