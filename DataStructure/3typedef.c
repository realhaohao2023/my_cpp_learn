#include <stdio.h>

//typedef关键字,给一个已有的数据类型起一个新的名字

typedef int INT; //INT就是int的别名

//使用typedef定义结构体
typedef struct point
{
    int x;
    int y;
} POINT;

//或者这样写
typedef struct
{
    int x;
    int y;
} POINT2;

INT a = 10;

//声明结构体变量
POINT p1;
POINT2 p2;
POINT2 *pp2;


int main()
{
    pp2 = &p2;
    pp2->x = 10;
    pp2->y = 20;
    printf("p2.x=%d,p2.y=%d\n", p2.x, p2.y);
    printf("a=%d\n", a);
    return 0;
}