/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (60.55%)	1104	-
Tags
Companies
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。



图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

 

示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/

// @lc code=start
class Solution {
public:
//暴力法，没意思
    int maxArea1(vector<int>& height) {
        int len = height.size();
        int ans = -1;
        for(int i=0;i<len;i++)
        {
            int tmp_max=-1;
            for(int j=i+1;j<len;j++)
            {
                int h = min(height[i],height[j]);
                int square = (j-i)*h;
                tmp_max = max(tmp_max,square);
            }
            ans = max(ans,tmp_max);
        }
        return ans;
    }
    //方法二：双指针，一头一尾。每次小的指针向前移动。原因：两者面积取决于小的部分。一旦通过双指针确定面积，一定是最小的
    //那个能确定的最大面积，所以没有必要再以小的为基准找了，所以小的那里指针赶紧移走，寻找其他基准。
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i=0,j=len-1;
        int ans = -1;
        while(i<j)
        {
            int square;
            if(height[i]<height[j])
            {
                square = (j-i)*height[i];
                i++;
            }else
            {
                square = (j-i)*height[j];
                j--;
            }
            ans = max(ans,square);
        }
        return ans;
    }
};
