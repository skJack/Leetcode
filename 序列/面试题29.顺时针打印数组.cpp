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
 
    //方法二：不撞南墙不回头。写了半天没写出来，边界控制好麻烦。学习一下先判断，再更改的操作
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x_dir[4] = {1,0,-1,0};
        int y_dir[4] = {0,1,0,-1};//从左到右
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int>ans(col*row);
        vector<vector<int>>visit(row,vector<int>(col,0));
        int x=0,y=0;
        int direction_index=0;
        for(int i=0;i<col*row;i++)
        {
            ans[i] = matrix[y][x];
            visit[y][x] = 1;
            int xx = x+x_dir[direction_index];
            int yy = y+y_dir[direction_index];
            if(xx<0 || xx>=row || yy<0 || yy>=col || visit[xx][yy]==1)//当到达边界的时候或者已经遍历过的时候.注意要先判断再转移
                direction_index = (direction_index+1)%4;   
            x+=x_dir[direction_index];
            y+=y_dir[direction_index];
            cout<<ans[i]<<" "<<direction_index<<" "<<x<<" "<<y<<endl;
        }
        return ans;
    }
};
