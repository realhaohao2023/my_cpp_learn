#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//栈 ：限定在表尾进行插入和删除操作的线性表
/*
表尾端称为栈顶
表头端称为栈底
不含元素的空表称为空栈

后进先出

基本操作：进栈（push）和出栈（pop），前者相当于插入操作，后者相当于删除操作（删除最后插入的元素）

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




/*=============================================================================*/

//栈的链式存储结构
typedef struct stack
{
    ElemType data;
    struct stack *next;
}stack_link;


//链式栈的头结点始终指向栈顶元素，即最新进栈的元素，而不是指向栈底
//初始化链式栈
stack_link* initstack_link()
{
    stack_link *s = (stack_link *)malloc(sizeof(stack_link));
    s->data = 0;   //头节点不存放数据
    s->next = NULL; //头结点不是栈的一部分，s->next才是栈的第一个元素
    return s;
}

//判断栈是否为空
int isEmpty(stack_link *s)
{
    if (s->next == NULL)
    {
        printf("栈空\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

//进栈 (头插法)
int push_link(stack_link *s, ElemType e)
{
    stack_link *newNode = (stack_link *)malloc(sizeof(stack_link));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(0);
    }
    newNode->data = e;
    newNode->next = s->next; //NULL
    s->next = newNode;
    return 1;
}

//出栈 删除头结点后的第一个结点
int pop_link(stack_link *s, ElemType *e)
{
    if (isEmpty(s))
    {
        return -1;
    }

    stack_link *p = s->next; //指向栈顶元素，用指针指向栈顶元素，操作指针就是操作栈顶元素
    *e = p->data;
    s->next = p->next; //头结点执行栈顶下面的元素
    free(p);
    return 1;
}

//获取栈顶元素 取出s->next的data


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