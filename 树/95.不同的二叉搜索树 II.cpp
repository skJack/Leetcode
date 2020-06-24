/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (60.79%)	261	-
Tags
Companies
Unknown

给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
//构建树的经典题，这种递归是真想不出来
//这种递归建树问题先写骨架，之后也就是假设先得到了left和right节点，之后再抽象成三个节点的情况
//完成树的组合
class Solution {
public:
    vector<TreeNode*> build(int start,int end)
    {
        vector<TreeNode*>ans;
        if(start>end)
            return {nullptr};
        else
        {
            for(int i=start;i<=end;i++)
            {
                vector<TreeNode*> left = build(start,i-1);
                vector<TreeNode*> right = build(i+1,end);
                for(auto a:left)
                {
                    for(auto b:right)
                    {
                        TreeNode* root = new TreeNode(i);//注意这里当leftright都为空时直接返回一个节点root
                        root->left = a;
                        root->right = b;
                        ans.push_back(root);
                    }
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n==0)
            return {};
        return build(1,n);
        
    }
};
