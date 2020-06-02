/*
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

 

示例 1：

输入: n = 3
输出: 6
示例 2：

输入: n = 9
输出: 45
*/
class Solution {
public:
    //思路：首先不能写循环，只能用递归做。
    //用递归需要判断条件，但是不能用if
    //所以用逻辑运算符的特殊性，当n==0的时候没救不会执行后面的语句，直接跳到后面
    int sumNums(int n) { 
        n&& (n=n+sumNums(n-1));
        return n;
        
    }
};
