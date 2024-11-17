#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 递归：函数直接或间接调用自身

//计算1+2+3+...+n的和
//非递归方式
int func1(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

//递归方式
int func2(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return func2(n-1) + n;
        //一层一层的调用，直到n=1，然后一层一层的返回，类似于栈
    }
}


//用递归的方式计算n项斐波那契数列
int fib(int n )
{
    if (n == 1 || n ==2)
    {
        return 1;
    }
    else
    {
        return fib(n-1) + fib(n-2);
    }
}



int main()
{
    printf("%d\n", func1(100));
    printf("%d\n", func2(100));
    printf("%d\n", fib(10));
}