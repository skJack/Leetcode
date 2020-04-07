/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (66.34%)	367	-
Tags
Companies
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

// @lc code=start
class Solution {
public:
//方法一：先转置，在逆序。注意这种题如果实在不会做，先转制一下，因为转制
//转制就包含了中间部分的旋转。之后再做操作
    void rotate1(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=i;j<col;j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for(int i=0;i<row;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
    void rotate(vector<vector<int>>& matrix)
    {
        //https://leetcode-cn.com/problems/rotate-image/solution/zhi-xing-yong-shi-ji-bai-liao-100de-yong-hu-jie-fa/
        int len = matrix.size();
        for(int start=0,end=len-1;start<len/2;start++,end--)
        {
            //外层循环定义框的边界
            for(int s=start,e=end;s<end;s++,e--)
            {
                //内层循环定义里面四个循环的部件
                int tmp = matrix[start][s];
                matrix[start][s] = matrix[e][start];
                matrix[e][start] =  matrix[end][e];
                matrix[end][e] = matrix[s][end];
                matrix[s][end] = tmp;
            }
        }
    }



};

class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        // 选择 四分之一区域 
        for(int i = 0; i < N / 2; i++){
            for(int j = 0; j < (N + 1) / 2; j++){ // 四个坐标 轮流转换。
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N - j - 1][i];
                matrix[N - j - 1][i] = matrix[N - i - 1][N - j - 1];
                matrix[N - i - 1][N- j - 1] = matrix[j][N - i - 1];
                matrix[j][N - i - 1] = temp;
            }
        }
    }
}


