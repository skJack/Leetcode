/*

Category	Difficulty	Likes	Dislikes
algorithms	Hard (47.96%)	859	-
Tags
Companies
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

*/
/*
1、dp解法：
算法：
1.1、求出每一列是否可以积水
1.2、max_left [i] 代表第 i 列左边最高的墙的高度，max_right[i] 代表第 i 列右边最高的墙的高度（一定要注意下，第 i列左（ 右）边最高的墙，是不包括自身的）
1.3、max_left [i] = Max(max_left [i-1],height[i-1])。它前边的墙的左边的最高高度和它前边的墙的高度选一个较大的
就是当前列左边最高的墙了。
1.4、max_right[i] = Max(max_right[i+1],height[i+1]) 。它后边的墙的右边的最高高度和它后边的墙的高度选一个较大 的，就是当前列右边最高的墙了。
1.5、参考
参考https://leetcode-cn.com/problems/trapping-rain-water/solution/ xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/的解法2的图解

*/

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size(), ans = 0;
        vector<int> max_left(size, 0);
        vector<int> max_right(size, 0);
        for(int i = 1; i < size - 1; ++i) 
            max_left[i] = max(height[i-1], max_left[i-1]);
        for(int i = size - 2; i >= 1; --i) 
            max_right[i] = max(height[i+1], max_right[i+1]);
        for(int i = 1; i < size-1; ++i) 
        {
            int minn = min(max_left[i], max_right[i]);
            if(height[i] < minn) 
            {
                ans += minn - height[i];
            }
        }
        return ans;
    }

    //双指针法
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_left = 0, max_right = 0, ans = 0;
        while(left < right) {
            if(height[left] < height[right])  {
                height[left] >= max_left ? ( max_left = height[left]) : ans += (max_left - height[left]); 
                ++left;
            }
            else {
                height[right] >= max_right ? ( max_right = height[right] ) : ans += (max_right - height[right]);
                --right;
            }
        }
        return ans;
    }
};
