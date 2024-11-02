#include <stdio.h>
#include <stdlib.h>

namespace xnh
{
    //命名空间里的变量只能初始化，不能赋值
    int rand = 0;
    int a = 1;
    //命名空间中可以定义变量/函数/类型
    int Add(int a, int b)
    {
        return a + b;
    }

    struct Node
    {
        struct Node *next;
        int data;
    };
}

int a = 2;

using xnh::Add; //展开命名空间中的函数，可以直接使用函数名

int main()
{

    xnh::rand = 10;
    struct  xnh::Node node;
    xnh::Add(1, 2);
    printf("%d\n", xnh::rand);//打印命名空间中的变量
    printf("%d\n", rand);//打印全局变量
    printf("%d\n", a);//打印全局变量
    printf("%d\n", xnh::a);//打印命名空间中的变量
    return 0;
}