#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int *p = a; // p指向数组a的首地址

//结构体的声明
struct point
{
    int x;
    int y;
};

struct point createPoint(int x, int y)
{
    struct point p;
    p.x = x;
    p.y = y;
    return p;
}

//声明结构体变量
struct point p1;


int main()
{
    // int a = 10;
    // int b = 20;
    // printf("交换前a=%d,b=%d\n", a, b);
    // swap(&a, &b);
    // printf("交换后a=%d,b=%d\n", a, b);

    // p1.x = 10;
    // p1.y = 20;
    
    p1 = createPoint(10, 20);

    // printf("p1.x=%d,p1.y=%d\n", p1.x, p1.y);
    // printf("a的首地址:%p\n", a);
    // printf("p的值:%p\n", p); //40320
    // //p+1 地址加一个int类型的长度,int类型占4个字节,所以加4
    // //打印p+1的值
    // printf("p+1的值:%p\n", p+1);//40324, 4个字节,数组的地址是连续的
    // printf("数组a的第一个元素:%d\n", *(p+1));

    
}