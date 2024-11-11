#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

//线性表: 由n个数据特性相同的数据元素组成的有限序列
//数据元素包括：整形、字符型、结构体、数组等

//存在唯一的一个被称为第一个元素的数据元素，头结点
//存在唯一的一个被称为最后一个元素的数据元素，尾结点
//除第一个元素外，每个元素有且仅有一个前驱元素
//除最后一个元素外，每个元素有且仅有一个后继元素


//顺序表：用一段地址连续的存储单元依次存储线性表的数据元素
//一般用数组来实现顺序表



//顺序表的存储结构
#define MAXSIZE 100
typedef int ElemType;
// typedef struct  //定义一个顺序表
// {
//     ElemType data[MAXSIZE]; //存放顺序表元素
//     int length; //存放顺序表的长度

// }SeqList;

typedef struct 
{
    ElemType *data; //存放顺序表元素
    int length;
    /* data */
}SeqList;


//顺序表的初始化
// void InitList(SeqList *L) //传递结构体变量的地址
// {
//     L->length = 0; //当前顺序表中没有元素
// }

//动态内存分配
SeqList* InitList() //在堆内存中给顺序表申请空间
{
    SeqList *L = (SeqList *)malloc(sizeof(SeqList)); //在这里声明一个结构体指针
    L->data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if (L->data == NULL)
    {
        printf("内存分配失败\n");
        exit(0);
    }
    L->length = 0;
}

//遍历顺序表
void displayList(SeqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("第%d个数据为%d\n", i+1, L->data[i]);
    }
}

//在尾部插入元素
int appendElem(SeqList *L, ElemType e) //在顺序表的尾部插入元素e
{
    if (L->length == MAXSIZE) //顺序表已满
    {
        return -1;
    }
    L->data[L->length] = e; //将e插入到顺序表的最后
    L->length++; //顺序表长度加1
    return 0;
}

//在指定位置插入元素
//后面的元素依次向后移动
//顺序表中的位置从1开始
int insertElem(SeqList *L, int pos, ElemType e)
{
    if (pos < 0 || pos > L->length || L->length == MAXSIZE) //插入位置不合法或者顺序表已满
    {
        printf("插入位置不合法或者顺序表已满\n");
        return -1;
    }

    //从后到前依次向后移动
    for (int i = L->length - 1; i >= pos; i--)
    {
        L->data[i + 1] = L->data[i];
    }
    L->data[pos-1] = e;
    L->length++;
    return 0;
}

//删除指定位置的元素
int deleteElem(SeqList *L, int pos, ElemType *e)
{
    *e = L->data[pos-1];
    if (pos < 0 || pos > L->length)
    {
        printf("删除位置不合法\n");
        return -1;
    }

    //每次循环后面的覆盖前面的
    for (int i = pos; i < L->length; i++)
    {
        L->data[i-1] = L->data[i];
    }
    L->length--;
    return 0;
}


//查找某个元素在顺序表中第一次出现的位置
int locateElem(SeqList *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i+1;
        }
    }
    return -1;
}


typedef struct 
{
    int num; 
    char name[20]; 
    float price; 

}book;

ElemType deletedata; //删除的数据

int main()
{


    // book b1;
    // b1.num = 1;
    // strcpy(b1.name, "C语言");
    // b1.price = 20.5;
    // printf("b1.num=%d,b1.name=%s,b1.price=%f\n", b1.num, b1.name, b1.price);

    //SeqList L1; //声明一个顺序表
    //InitList(&L1); //初始化顺序表

    //改为动态内存分配，在初始化函数里声明一个结构体指针
    SeqList *L1 = InitList();
    //在后续的函数调用里，不用再加取地址符号&



    //显示长度
    printf("初始化成功长度为%d\n", L1->length);
    //显示数据data占用的内存
    printf("占用的内存为%d\n", sizeof(L1->data));

    appendElem(L1, 0);
    appendElem(L1, 1);
    appendElem(L1, 2);
    appendElem(L1, 3);
    appendElem(L1, 4);
    appendElem(L1, 100);
    appendElem(L1, 200);
    appendElem(L1, 300);

    //遍历顺序表
    displayList(L1);
    //分隔线
    printf("=====================================\n");

    insertElem(L1, 3, 1000);
    displayList(L1);
    insertElem(L1, 300, 1000);

    //分隔线
    printf("=====================================\n");

    deleteElem(L1, 3, &deletedata);
    displayList(L1);
    printf("删除的数据为%d\n", deletedata);
    printf("数据4的位置为%d\n", locateElem(L1, 4));




    return 0;
}
