/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (39.83%)	365	-
Tags
Companies
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

// @lc code=start
class Solution {
public:
    //方法一：
    //思路：先按照左断点从小往大排序，注意这里默认的sort就是按照左断点。
    //之后从右往前老老实实合并区间，很蠢
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len==1||len==0)
            return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int>last = intervals[0];
        ans.push_back(intervals[0]);
        for(int i=1;i<len;i++)
        {
            cout<<i<<" ";
            vector<int>first = last;
            vector<int>second = intervals[i];
            
            if(min(first[1],second[1])>=max(first[0],second[0]))
            {
                //if (ans.size()!=0)
                    ans.erase(ans.begin()+i-1);
                int l = min(first[0],second[0]);
                int r = max(first[1],second[1]);
                vector<int>tmp{l,r};
                last = tmp;
                ans.push_back(tmp);
            }
            else
            {
                //ans.push_back(first);
                ans.push_back(second);
                last = second;
            }
        }
        return ans;
    }
    //方法二：首先同样排序
    //其次
    /*
    如果当前区间的左端点在数组 merged 中最后一个区间的右端点之后，那么它们不会重合，我们可以直接将这个区间加入数组 merged 的末尾；
    否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区间的右端点，将其置为二者的较大值。

    */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
