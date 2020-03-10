/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (46.50%)	251	-
Tags
Companies
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。


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
    //思路：每次求各个节点的最大深度的时候，需要判断一下当前节点和最大值的关系并进行更新
    //我卡在，知道思路但是想着重复执行maxDepth函数，没想到利用求深度的过程本身就是遍历树的过程，太蠢了！
    int maxd = 0;
    int maxDepth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        else
        {
            int left_height = maxDepth(root->left);
            int right_height = maxDepth(root->right);
            maxd = max(left_height+right_height,maxd);
            return max(left_height,right_height)+1;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxd;
    }
};
