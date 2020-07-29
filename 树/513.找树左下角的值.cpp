/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (67.48%)	56	-
Tags
Companies
给定一个二叉树，在树的最后一行找到最左边的值。

示例 1:

输入:

    2
   / \
  1   3

输出:
1
 

示例 2:

输入:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

输出:
7
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
    int maxdepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(maxdepth(root->left),maxdepth(root->right))+1;
    }
    //方法一：先算最大深度，之后光搜找最大
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxlen = maxdepth(root);
        queue<TreeNode*>q;
        q.push(root);
        int curlen = 0;
        while (!q.empty())
        {
            int l = q.size();
            curlen++;
            while (l--)
            {
                TreeNode* tmp = q.front();
                if(curlen==maxlen)
                    return tmp->val;
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
        }
        return 0;
    }
    //方法二：直接从右往左光搜，之后找数组最后一个值就行.但如果是满二叉树的话就回很慢
};
