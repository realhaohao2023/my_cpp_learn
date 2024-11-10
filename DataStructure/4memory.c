#include <stdio.h>
#include <stdlib.h> //malloc函数所在的头文件
#include <string.h> //strcpy函数所在的头文件

//C语言中的内存分配

//静态/全局内存
/*
静态声明的变量，全局变量，常量都存储在静态内存中
静态内存在程序运行时就已经分配好，程序结束时才释放
*/

//自动内存（栈内存）
/*
函数内部声明的变量，函数的参数，都存储在栈内存中
函数被调用时，分配内存，函数结束时，释放内存
*/

//动态内存（堆内存）
/*
根据需求分配内存，使用完后，需要手动释放
内存中的内容知道释放才会消失
*/

//malloc函数,动态分配内存，在堆内存中开辟一块指定大小的内存空间
/*
void *malloc(size_t size); 
size_t数据类型，占位符为%zu
返回值：成功返回指向该内存的指针，失败返回NULL（空指针）

void *是通用数据类型指针，可以指向任何类型的数据

使用free函数释放内存
*/

typedef struct
{
    int x;
    int y;
} POINT;

int main(int argc, char const *argv[])
{
    //整形
    int a = 10;
    int *p = NULL;
    //malloc返回一个指向分配的内存地址的指针
    p = (int *)malloc(sizeof(int)); //开辟一个int类型的内存空间
    *p = a;

    //字符型
    char *s;
    s = (char *)malloc(100); //开辟100个字节的内存空间
    strcpy(s, "hello world");
    printf("s=%s\n", s);

    //数组
    int *arr;
    arr = (int *)malloc(5 * sizeof(int)); //开辟5个int类型的内存空间
    for(int i = 0; i < 5; i++)
    {
        arr[i] = i;
    }
    for(int i = 0; i < 5; i++)
    {
        printf("arr[%d]=%d\n", i, arr[i]);
    }

    int *p0;
    p0 = &a;
    printf("*p0=%d\n", *p0);
    printf("p0=%p\n", p0);
    printf("a的地址%p\n", &a);

    //结构体
    POINT *point;
    point = (POINT *)malloc(sizeof(POINT)); //开辟一个POINT类型的内存空间
    //sizeof(POINT) = sizeof(int) + sizeof(int) = 4 + 4 = 8
    point->x = 10;
    point->y = 20;
    printf("point->x=%d,point->y=%d\n", point->x, point->y);
  
    free(p); //释放内存
    free(s);
    free(arr);
    free(point);
    return 0;
}