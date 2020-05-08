/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (63.69%)	230	-
Tags
Companies
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

*/

//注意bfs根据树高的写法，就是在大while里面直接把所有元素提取
//本题和102完全一致 加一个翻转就行
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
