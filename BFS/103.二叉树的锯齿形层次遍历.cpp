/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (53.04%)	200	-
Tags
Companies
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

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
//方法一：和102题很像，只要最后入结果的时候加入取反就行
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        q.push(root);
        bool flag = true;//当flage为true时从左往右，为false时从右往左
        while (!q.empty())
        {
            vector<int>level;
            int count = q.size();
            while(count--)
            {
                TreeNode *tmp = q.front();
                level.push_back(tmp->val);
                q.pop();
                if(tmp->left!=NULL)
                    q.push(tmp->left);
                if(tmp->right!=NULL)
                    q.push(tmp->right);
            }
            if(flag==true)
                ans.push_back(level);
            else
            {
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
            flag = !flag; 
        }
        return ans;
    }
//方法二：用双端队列或者list实现，只要当flag为true时从左往右，并且插入到队列中
//flag为false时。从右向左插入到栈中
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        list<TreeNode*> q;
        q.push_back(root);
        bool direction=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> tmp;
            if(direction){
                
                for(int i=0;i<size;i++){
                    TreeNode* node=q.front();
                    q.pop_front();
                    tmp.push_back(node->val);
                    if(node->left)q.push_back(node->left);
                    if(node->right)q.push_back(node->right);
                }
            }
            else{
                for(int i=size-1;i>=0;i--){
                    TreeNode* node=q.back();
                    q.pop_back();
                    tmp.push_back(node->val);
                    if(node->right)q.push_front(node->right);
                    if(node->left)q.push_front(node->left);
                }
            }
            ans.push_back(tmp);
            direction=!direction;
        }
        return ans;


};
