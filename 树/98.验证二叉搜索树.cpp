/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (28.07%)	355	-
Tags
Companies
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
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
class Solution {
public:
    bool helper(TreeNode* root,int up,int down)
    {
        //方法一：保存节点的上界和下界，之后递归遍历即可。注意其中变化的小技巧
        if(root==NULL)
            return true;
        //规定当前节点的上界和下界
        if(up!=5050&&root->val>=up)
            return false;
        if(down!=-5050&&root->val<=down)
            return false;
        if(!helper(root->left,root->val,down))
            return false;
        if(!helper(root->right,up,root->val))
            return false;
        return true;
    }
    bool isValidBST1(TreeNode* root) {
        cout<<NULL;
       return helper(root,5050,-5050);
    }
    vector<int>squence;
    //方法二：中序遍历，得到序列应该满足每个元素都比下一个元素小
    //原因：要求每一个子树都满足左<根<右，相当于每个子树都要满足这个性质
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return;
        dfs(root->left);
        squence.push_back(root->val);
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
       dfs(root);
       for(int i=0;i<squence.size()-1;i++)
       {
           if(squence[i]>=squence[i+1])
                return false;
       }
       return true;
    }
    //重做
    long long pre = (long long)INT_MIN - 1;//最重要的就是学会pre的位置，之前写在参数中
    //发现搞不定，后来发现这个pre一定得是全局的，所以要注意递归和全局变量的合理配合
    bool helper(TreeNode* root)
    {
        //直接在中序遍历的时候就判断，不用存下来
        if(root==NULL)
        {
            return true;
        }
        
        bool left_ = helper(root->left);
        int curr = root->val;
        if(curr<=pre)
            return false;
        pre = curr;
        bool right_ = helper(root->right);
        return left_&&right_;

    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        return helper(root);

    }
    
};
