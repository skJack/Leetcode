/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (60.72%)	73	-
Tags
Companies
amazon

给你一个二叉树的根结点，请你找出出现次数最多的子树元素和。一个结点的「子树元素和」定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。

你需要返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。

 

示例 1：
输入:

  5
 /  \
2   -3
返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。

示例 2：
输入：

  5
 /  \
2   -5
返回 [2]，只有 2 出现两次，-5 只出现 1 次。

 

提示： 假设任意子树元素和均可以用 32 位有符号整数表示。


*/

class Solution {
public:
    map<TreeNode*,int>m;
    vector<int>res;
    void dfs1(TreeNode* root)
    {
        if(root==NULL)
            return;
        dfs(root->left);
        
        dfs(root->right);
        if(!root->left&&!root->right)
        {
            //叶子结点
            m[root] = root->val;
        }
        if(root->left==NULL&&root->right!=NULL)
            m[root] = root->val+m[root->right];
        if(root->left!=NULL&&root->right==NULL)
            m[root] = root->val+m[root->left];
        else
        {
            m[root] = m[root->left]+m[root->right]+root->val;
        }
        res.push_back(m[root]);
    }
    //思路：先用哈希表存储每个节点的和，使用dp递归的思想用后续遍历自底向上加，填写完成哈希表
    //之后对得到的表进行排序，求众数。
    vector<int> findFrequentTreeSum1(TreeNode* root) {
        vector<int>ans;
        int maxcount = 1;
        int currcount = 1;
        if(root==NULL)
            return ans;
        dfs(root);
        sort(res.begin(),res.end());
        ans.push_back(res[0]);
        for(int i=1;i<res.size();i++)
        {
            cout<<res[i]<<" ";
            if(res[i]!=res[i-1])
                currcount = 1;
            else
            {
                currcount++;
            }
            
            if(currcount==maxcount)
                ans.push_back(res[i]);
            if(currcount>maxcount)
            {
                ans.clear();
                ans.push_back(res[i]);
                maxcount = currcount;
            }
        }
        return ans;
    }
    unordered_map<int, int> freqInfo;
    int maxFreq = 0;
    //和我的方法改进点
    //直接用dfs做dp的加法
    //遍历树的时候就记录下来最大频率是多少
    //用哈希表记录出现次数
    int dfs(TreeNode * root) {
        if(root != NULL) {
            int sum = root->val + dfs(root->left) + dfs(root->right);
            freqInfo[sum]++;
            maxFreq = std::max(maxFreq, freqInfo[sum]);
            
            return sum;
        } else {
            return 0;
        }
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        
        vector<int> res;
        //学会遍历map的方式
        for(auto & kv : freqInfo) {
            if(kv.second == maxFreq) {
                res.push_back(kv.first);
            }
        }
    }

};
