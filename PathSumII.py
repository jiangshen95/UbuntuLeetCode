class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        def pathSum(result, path, root, sum):
            if not root:
                return
            if not root.left and not root.right and sum==root.val:
                #path.append(root.val)
                result.append(path+[root.val])
                #path.pop()
            else:
                #path.append(root.val)
                pathSum(result, path+[root.val], root.left, sum-root.val)
                pathSum(result, path+[root.val], root.right, sum-root.val)
                #path.pop()
        result = []
        path = []
        pathSum(result, path, root, sum)
        return result
        
if __name__=='__main__':
    root=TreeNode(5);
    a=TreeNode(4);
    b=TreeNode(8);
    c=TreeNode(11);
    d=TreeNode(13);
    e=TreeNode(4);
    f=TreeNode(7);
    g=TreeNode(2);
    h=TreeNode(1);
    k=TreeNode(5)
    
    root.left=a;
    root.right=b;
    a.left=c;
    b.left=d;
    b.right=e;
    c.left=f;
    c.right=g;
    e.left=k;
    e.right=h;
    
    sum = int(raw_input())
    
    solution = Solution()
    print(solution.pathSum(root, sum))
