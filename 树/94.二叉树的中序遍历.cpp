/*
Category	Difficulty	Likes	Dislikes
algorithms	Medium (69.58%)	532	-
Tags
Companies
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？


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
    void dfs(vector<int>&ans,TreeNode* root)
    {
        if(root==NULL)
            return;
        else
        {
            dfs(ans,root->left);
            ans.push_back(root->val);
            dfs(ans,root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        dfs(ans,root);
        return ans;
    }
   //中序遍历先左再中再右
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>ans;
        TreeNode* curr = root;
        while (curr!=NULL||!s.empty())
        {
            while (curr!=NULL)
            {
                s.push(curr);
                curr = curr->left;
            }//先把左支路都放进去
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            //s.push(root->right);注意这么写就错了
            curr = curr->right;
        }
        return ans;
    }
    //先序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>ans;
        TreeNode* curr = root;
        while(curr!=NULL||!s.empty())
        {
            while(curr!=NULL)//内层循环相当于可以处理两个节点
            {
                //先直接使用根节点
                ans.push_back(curr->val);
                //右节点入栈
                s.push(curr->right);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();

        }

    }

};
