/*
面试题40. 最小的k个数
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
 

限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
*/
class Solution {
public:
    //方法一：排序暴力法
    vector<int> getLeastNumbers1(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int len = arr.size();
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
    //方法二：最小堆,用c++中的优先队列实现，每次入堆，如果队中数量大于k，就出队
    //最后剩下的就是最小的k个数字
    vector<int> getLeastNumbers2(vector<int>& arr, int k) {
        int len = arr.size();
        priority_queue<int>q;//默认大顶堆，队头元素是最大的元素
        vector<int>ans;
        for(int i=0;i<len;i++)
        {
            q.push(arr[i]);
            if(i>k-1){
                q.pop();
            }
        }
        //取出堆中剩余的数字即可
        while(!q.empty())
        {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
    //快速排序
    int partition(vector<int>& arr,int left,int right)
    {
        int x = arr[left];//相当于left的坑没了
        while(left<right)
        {
            while(left<right && arr[right]>=x)//从右侧指针开始，找到比基准位置小的就交换
                right--;
            if(left<right)
                arr[left] = arr[right];//填坑
            while(left<right && arr[left]<x)//一样的道理
                left++;
            if(left<right)
                arr[right] = arr[left];
        }
        arr[left] = x;
        return left;
    }
    void quicksort(vector<int>&arr,int left,int right)
    {
        if(left<right)
        {
            int part = partition(arr,left,right);
            cout<<part<<endl;
             for(int i=0;i<arr.size();i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            quicksort(arr,left,part-1);
            quicksort(arr,part+1,right);
        }
    }
    //方法三：快速选择法，基于快速排序的改进
    vector<int> getLeastNumbers3(vector<int>& arr, int k)
    {
        quicksort(arr,0,arr.size()-1);//排序
        // for(int i=0;i<arr.size();i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        int len = arr.size();
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
    //方法四：quickselection,部分快速排序，因为每次前m个数字必定是数组中最小的m个数，所以只要比较m和k的大小，然后去增大或减少m的数量即可
    void quickselect(vector<int>&arr,int left,int right,int k)
    {
        if(left<right)
            {
                int q = partition(arr,left,right);
                if(q==k)
                    return;
                else if(q<k)
                    quickselect(arr,q+1,right,k);
                else
                    quickselect(arr,left,q-1,k);
            }
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        quickselect(arr,0,arr.size()-1,k);//排序
        int len = arr.size();
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }

};
