/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (56.06%)	82	-
Tags
Companies
给定一个二叉树，计算整个树的坡度。

一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。

整个树的坡度就是其所有节点的坡度之和。

 

示例：

输入：
         1
       /   \
      2     3
输出：1
解释：
结点 2 的坡度: 0
结点 3 的坡度: 0
结点 1 的坡度: |2-3| = 1
树的坡度 : 0 + 0 + 1 = 1
 

提示：

任何子树的结点的和不会超过 32 位整数的范围。
坡度的值不会超过 32 位整数的范围。
*/

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int caltilt(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left = caltilt(root->left);
        int right = caltilt(root->right);
        ans+=abs(left-right);
        return left+right+root->val;
    }

    
    int findTilt(TreeNode* root) {
        //思路：计算节点和，因为节点和正好等于左节点和+右节点和，所以只要在中间记录一下就行
        int sums = caltilt(root);
        return ans;
    }
};
