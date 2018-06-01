# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        if not root:
            return result
        tmp = []
        container = []
        container.append(root)
        while container:
            tmp.clear()
            level = []
            for key in container:
                print("key: ", key.val)
                level.append(key.val)
                if key.left is not None:
                    print("key left", key.left.val)
                    tmp.append(key.left)
                if key.right is not None:
                    print("key right", key.right.val)
                    tmp.append(key.right)
            result.append(level)
            print(level)
            container = list(tmp)
        result.reverse()
        return result
            
        
