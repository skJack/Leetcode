/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (57.27%)	396	-
Tags
Companies
请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。


*/

// @lc code=start
class Solution {
public:
    //方法一：暴力法，超时
    vector<int> dailyTemperatures1(vector<int>& T) {
        int len = T.size();
        vector<int>ans;
        for(int i=0;i<len;i++)
        {
            int j=i+1;
            int days = 1;
            while(j<len)
            {
                if(T[i]<T[j])
                {
                    ans.push_back(days);
                    break;
                }
                else
                {
                    j++;
                    days++;
                }
            }
            if(j==len)
                ans.push_back(0);
        }
        return ans;
    }
    //方法二：单调栈.重点学会什么情况改用单调栈，当出现求某段
    //序列的最值的时候用，也就是一个数组求他部分单调区间时候往单调栈想
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        stack<int>s;
        vector<int>ans(len,0);
        for(int i=0;i<len;i++)
        {
            if(s.empty())
                s.push(i);//如果栈空，将索引入栈
            else
            {
                while(!s.empty()&&T[i]>T[s.top()])
                {
                    //新元素比栈顶元素大，更新栈顶索引数组并出栈
                    int tmp = s.top();
                    ans[tmp] = i-tmp;
                    s.pop();
                }
                s.push(i);//如果栈空，将索引入栈
            }
        }
        return ans;
    }
};
// @lc code=end

