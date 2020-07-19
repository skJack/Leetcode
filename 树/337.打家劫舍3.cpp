/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (54.88%)	208	-
Tags
Companies
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//原则：
//树的dp，当前节点的最大等于所有四个可能的孙子节点的和加上当前节点的值和两个爸爸的和取最大
//注意树的dp问题用哈希表来解决重复计算问题，算是一个通用套路
class Solution {
public:
    unordered_map<TreeNode*,int> hash;
    //方法一：超时方法，有重复计算
    int rob1(TreeNode* root) {
        if(root==NULL)
            return 0;
        int money = root->val;
        if(root->left!=NULL)
            money += rob(root->left->left)+rob(root->left->right);
        if(root->right!=NULL)
            money += rob(root->right->left)+rob(root->right->right);
        return max(money,rob(root->left)+rob(root->right));
    }
    int rob2(TreeNode* root) {
        map<TreeNode*,int>m;
        return helper(root,m);
    }
    int helper(TreeNode* root,map<TreeNode*,int>&m)
    {
        if(root==NULL)
            return 0;
        if(m[root]!=0)
            return m[root];
        int money = root->val;
        if(root->left!=NULL)
            money += rob(root->left->left)+rob(root->left->right);
        if(root->right!=NULL)
            money += rob(root->right->left)+rob(root->right->right);
        m[root] = max(money,rob(root->left)+rob(root->right));
        return m[root];
    }
    int rob(TreeNode* root) {
        if(root== NULL)
            return 0;
        if(hash.count(root) == 1)
            return hash[root];
        hash[root] = max(root->val+(root->left == NULL?0:(rob(root->left->left)+rob(root->left->right)))+
                    (root->right== NULL?0:(rob(root->right->left)+rob(root->right->right))),
                    rob(root->left)+rob(root->right));
        return hash[root];
    }

};
