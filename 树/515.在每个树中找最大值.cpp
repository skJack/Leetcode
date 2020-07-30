/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (57.31%)	48	-
Tags
Companies
您需要在二叉树的每一行中找到最大的值。

示例：

输入: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

输出: [1, 3, 9]
*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            int max = INT_MIN;
            while(len--)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if(max<tmp->val)
                    max = tmp->val;
                if(tmp->left!=NULL)
                    q.push(tmp->left);
                if(tmp->right!=NULL)
                    q.push(tmp->right);
            }
            ans.push_back(max);
        }
        return ans;
    }
};
