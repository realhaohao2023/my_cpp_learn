#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//栈 ：限定在表尾进行插入和删除操作的线性表
/*
表尾端称为栈顶
表头端称为栈底
不含元素的空表称为空栈

后进先出

基本操作：进展（push）和出栈（pop），前者相当于插入操作，后者相当于删除操作（删除最后插入的元素）

*/

//栈的顺序结构
#define MAXSIZE 100
typedef int ElemType;

// typedef struct
// {
//     ElemType data[MAXSIZE];
//     int top; //栈顶指针，每次入栈加1，出栈减1，初始化时指向第一个元素（也是栈底）
// }stack;

// //初始化栈
// void initStack(stack *s)
// {
//     s->top = -1; //栈顶指针初始化为-1
// }

//动态分配内存
typedef struct
{
    ElemType *data;
    int top;
}stack;

stack *initstack()
{
    stack *s = (stack *)malloc(sizeof(stack));//分配一个栈的内存
    s->data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));//分配栈的数据域内存

    s->top = -1;
    return s;
}


//进栈
int push(stack *s, ElemType e)
{
    if (s->top == MAXSIZE - 1)//栈顶指针从0开始，所以满栈时指向MAXSIZE-1
    {
        printf("栈满\n");
        return -1;
    }

    s->top++; //栈顶指针加1
    s->data[s->top] = e; //将元素e放入栈顶指针指向的位置
    return 0;
}

//出栈
ElemType pop(stack *s, ElemType *e) //传入参数的指针
{
    if (s->top == -1)
    {
        printf("栈空\n");
        return -1;
    }

    *e = s->data[s->top]; //将栈顶元素赋值给e
    s->top--; //栈顶指针减1
    return 0;

}

//获取栈顶元素
ElemType getTop(stack *s)
{
    if (s->top == -1)
    {
        printf("栈空\n");
        return -1;
    }

    return s->data[s->top];
}


int main()
{
    // stack s;
    // initStack(&s);
    // //进栈
    // push(&s, 1);
    // push(&s, 2);
    // push(&s, 3);
    // //出战
    // ElemType e;
    // pop(&s, &e);

    // printf("%d\n", e);

    // //获取栈顶元素
    // printf("%d\n", getTop(&s));

    stack *s = initstack();
    push(s, 1);
    push(s, 2);
    push(s, 3);

    //出栈
    ElemType e;
    pop(s, &e);
    printf("%d\n", e);

    //获取栈顶元素
    printf("%d\n", getTop(s));

    return  0;
}