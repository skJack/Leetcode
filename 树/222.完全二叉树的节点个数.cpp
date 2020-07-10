/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (65.17%)	189	-
Tags
Companies
给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入: 
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6
*/

class Solution {
public:
    //根据完全二叉树的性质计算深度
    int depth(TreeNode* root)
    {
        int height = 0;
         while (root!=NULL)
         {
             root = root->left;
             height++;
         }
         return height;
        
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int left_height = depth(root->left);
        int right_height = depth(root->right);
        if(left_height==right_height)
        {
            //此时左子树一定是满二叉树，因为节点已经入侵到右边去了
            //所以此时总数量等于左满二叉树+右子树的数量
            return pow(2,left_height)+countNodes(root->right);
        }
        else
        {
            //左子树不满，需要都递归
            return countNodes(root->left)+countNodes(root->right)+1;
        }
    }
};
