/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (59.00%)	538	-
Tags
Companies
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]



 

示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。
*/

class Solution {
public:
    
    //函数功能：
    //如果当前子树包含p和q，则返回其公共祖先
    //如果当前子树包含p或者q，则返回p或q本身
    //如果p和q都不存在，就返回null
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == NULL)
            return NULL;
        if(root==p||root==q)
        {
            //如果有找到一个，则返回
            return root;
        }
        else
        {
            //分别去当前节点的左右子树找有没有与p，q对应的
            TreeNode* left = lowestCommonAncestor(root->left,p,q);
            TreeNode* right = lowestCommonAncestor(root->right,p,q);
            if(left==NULL)
            {
                //左子树为空，说明左子树没有找到p，q,也没有找到公共父节点，则返回右子树
                return right;
            }
            if(right==NULL)
            {
                return left;
            }
            //都不为空，说明p和q分布在root的两边，此时root就是结果
            if(left&&right)
                return root;
            return NULL;
        }
        
    }
};
