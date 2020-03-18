/*
矩形重叠
Category	Difficulty	Likes	Dislikes
algorithms	Easy (44.65%)	100	-
Tags
Companies
矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。

如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。

给出两个矩形，判断它们是否重叠并返回结果。

 

示例 1：

输入：rec1 = [0,0,2,2], rec2 = [1,1,3,3]
输出：true
示例 2：

输入：rec1 = [0,0,1,1], rec2 = [1,0,2,1]
输出：false
 

提示：

两个矩形 rec1 和 rec2 都以含有四个整数的列表的形式给出。
矩形中的所有坐标都处于 -10^9 和 10^9 之间。
x 轴默认指向右，y 轴默认指向上。
你可以仅考虑矩形是正放的情况。
*/

// @lc code=start
class Solution {
public:
    //好题
    //方法一：投影判断法：如果两个矩形相交，说明其x方向和y方向的投影线段
    //一定有相交.
    //如何判断线段相交？
    //min(x2,y2)>max(x1,y1),则一定相交，因为相当于长的末尾比短的初始长，就一定相交
    //也是计算交由比的重要做法
    bool isRectangleOverlap1(vector<int>& rec1, vector<int>& rec2) {
        int x1_left = rec1[0];
        int x1_right = rec1[2];
        int y1_left = rec1[1];
        int y1_right = rec1[3];

        int x2_left = rec2[0];
        int x2_right = rec2[2];
        int y2_left = rec2[1];
        int y2_right = rec2[3];
        //为了清晰 都写出来
        if(min(x1_right,x2_right)>max(x1_left,x2_left)&&min(y1_right,y2_right)>max(y1_left,y2_left))
            return true;//如果在横坐标上的投影有交集，则一定重叠
        else
        {
            return false;
        }
    }
    //方法二：中心点坐标法。取两个矩形的中心点，如果中心点的x分距离和y分距离分别等于两个矩形的一半长/宽相加，则不相交
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //略
        
    }

};
