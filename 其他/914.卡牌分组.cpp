/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (32.61%)	133	-
Tags
Companies
Unknown

给定一副牌，每张牌上都写着一个整数。

此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：

每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。

 

示例 1：

输入：[1,2,3,4,4,3,2,1]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
示例 2：

输入：[1,1,1,2,2,2,3,3]
输出：false
解释：没有满足要求的分组。
示例 3：

输入：[1]
输出：false
解释：没有满足要求的分组。
示例 4：

输入：[1,1]
输出：true
解释：可行的分组是 [1,1]
示例 5：

输入：[1,1,2,2,2,2]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[2,2]

提示：

1 <= deck.length <= 10000
0 <= deck[i] < 10000
*/

// @lc code=start
class Solution {
public:
    int gcd(int a,int b)
    {
        if(a<b)
            swap(a,b);
        if(b==0)
            return a;
        else
        {
            return gcd(b,a%b);
        }
    }
    //方法一：自己的笨办法，先统计数字频率，之后挨个计算每个频率的最小公倍数，当公倍数
    //小于2的时候就肯定无法分组，否则一定可以分组
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int>m;
        int min = 10001;
        for(int i=0;i<deck.size();i++)
        {
            m[deck[i]]++;
        }
        map<int,int>::iterator iter = m.begin();
        int pre = iter->second;
        for(iter = m.begin();iter!=m.end();iter++)
        {
            int g = gcd(pre,iter->second);
            if(g<2)
                return false;
            pre = iter->second;
        }
        return true;
    }
};
