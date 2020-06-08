/*
等式方程的可满足性
Category	Difficulty	Likes	Dislikes
algorithms	Medium (37.80%)	78	-
Tags
Companies
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

 

示例 1：

输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
示例 2：

输出：["b==a","a==b"]
输入：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
示例 3：

输入：["a==b","b==c","a==c"]
输出：true
示例 4：

输入：["a==b","b!=c","c==a"]
输出：false
示例 5：

输入：["c==c","b==d","x!=z"]
输出：true

*/

// @lc code=start
class UnionFind{
public:
    vector<int>parent;//根节点，相当于每个集合的代表
    UnionFind()
    {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int index)//递归查找法，相当于完全路径压缩
    {
        //作用：查找当前元素的爸爸
        if(index==parent[index])
            return index;//本身就是爸爸，递归终止条件
        parent[index] = find(parent[index]);
        return parent[index];
    }
    void unite(int index1,int index2)
    {
        //作用：建立并查集，将index1和index2连在一起
        parent[find(index1)]=find(index2);
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int len = equations.size();
        UnionFind un;
        for(int i=0;i<len;i++)
        {
            string eq = equations[i];
            if(eq[1]=='=')
            {
                //建立并查集
                un.unite(eq[0]-'a',eq[3]-'a');    
            }
        }
        for(int i=0;i<len;i++)
        {
            string eq = equations[i];
            if(eq[1]=='!')
            {
                //如果他俩不等于但又属于一个并查集，也就是有一个爸爸的话，那么返回false
                if(un.find(eq[0]-'a')==un.find(eq[3]-'a'))
                    return false;
            }
        }
        return true; 
    }
};
