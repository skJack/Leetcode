/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (60.31%)	467	-
Tags
Companies
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>level;
            int count = q.size();//当前存储的所有节点
            //记住求树高的一定两个循环
            while(count--)
            {
                TreeNode* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if(tmp->left!=NULL)
                    q.push(tmp->left);
                if(tmp->right!=NULL)
                    q.push(tmp->right);
            }
            ans.push_back(level);
        }
        //reverse(ans.begin(),ans.end());
        return ans;

    }
};
