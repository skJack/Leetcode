/*面试题29. 顺时针打印矩阵
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
*/
//这道题想了半天，这种问题两种方法。
//四个方向分别
//第二种是DFS方法，配合visit数组

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int row = matrix.size();
            if(row==0)
                return vector<int>();
            int col = matrix[0].size();
            vector<int>ans(col*row);
            int left = 0,right = col-1,up = 0,down = row-1;
            int index = 0;
            while(1)
            {
                for(int i = left;i<=right;i++)
                //从左往右
                {
                    ans[index++] = matrix[up][i];
                }
                up++;
                if(up>down)
                    break;
                for(int i = up;i<=down;i++)
                {
                    //从上往下
                    ans[index++] = matrix[i][right];
                    
                }
                right--;
                if(left>right)
                    break;
                for(int i=right;i>left-1;i--)
                {
                    //从右往左
                    ans[index++] = matrix[down][i];
                }
                down--;
                if(up>down)
                    break;
                for(int i=down;i>up-1;i--)
                {
                    //从下往上
                    ans[index++] = matrix[i][left];
                }
                left++;
                if(left>right)
                    break;
            } 
            return ans;
    }
};
