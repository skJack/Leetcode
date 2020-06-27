/*

Category	Difficulty	Likes	Dislikes
algorithms	Hard (54.30%)	116	-
Tags
Companies
二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:

输入: [1,3,null,null,2]

   1
  /
 3
  \
   2

输出: [3,1,null,null,2]

   3
  /
 1
  \
   2
示例 2:

输入: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

输出: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
进阶:

使用 O(n) 空间复杂度的解法很容易实现。
你能想出一个只使用常数空间的解决方案吗？
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
    TreeNode* node1 = NULL;
    TreeNode* node2 = NULL;
    TreeNode* pre = NULL;
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return;
        dfs(root->left);
        int value = root->val;
        if(pre != NULL && value < (pre->val))
            {
                if(node1 == NULL)
                {
                    node1 = pre;//如果此时第一个节点为空，就记录前一个
                    node2 = root;
                }
                else
                {
                    node2 = root;//更新第二个节点
                }
                
            }
        pre = root;
        dfs(root->right);
    }
    void recoverTree1(TreeNode* root) {
        if(root==NULL)
            return;
        dfs(root);
        cout<<node1->val<<" "<<node2->val;
        int tmp = node1->val;
        node1->val = node2->val;
        node2->val = tmp;
        return;
    }
};
