/*
1.遍历使用栈三种顺序遍历方式：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/die-dai-fa-by-jason-2/
*/
//先序
vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt->right);
                v.push_back(rt->val);
                rt=rt->left;
            }
            rt=S.top();S.pop();
        }
        return v;        
    }

//后序：
vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt->left);
                v.push_back(rt->val);
                rt=rt->right;
            }
            rt=S.top();S.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
//后序2：
vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        unordered_map<TreeNode*,int> done;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt);
                rt=rt->left;
            }
            while(S.size() && done[S.top()]){
                v.push_back(S.top()->val);
                S.pop();
            }
            if(S.size()){
                rt=S.top()->right;
                done[S.top()]=1;    
            }
        }
        return v;
    }
//中序：
vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt);
                rt=rt->left;
            }
            rt=S.top();S.pop();
            v.push_back(rt->val);
            rt=rt->right;
        }
        return v;        
    }
