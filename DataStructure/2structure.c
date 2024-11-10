#include <stdio.h>

//结构体与指针
//在某些场景，如果传递给函数的结构体很大，使用指针的方式效率更高

struct point
{
    int x;
    int y;
};

struct point *pp; //定义一个结构体指针,pp指向一个point类型的结构体

struct point p1;



int main()
{
    // (*pp).x = 10;
    // (*pp).y = 20;

    //更简单的方式
    // pp->x = 10;
    // pp->y = 20;

    p1.x = 10;
    p1.y = 20;

    pp = &p1; //pp指向p1，pp对应的就是结构体p1的地址，那么pp就可以访问p1的成员

    pp->x = 30; //通过pp访问p1的成员
    pp->y = 40;

    printf("p1.x=%d,p1.y=%d\n", p1.x, p1.y);
    printf("pp->x=%d,pp->y=%d\n", pp->x, pp->y);
    
    return 0;
}