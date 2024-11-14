#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 队列：限定在表头进行删除，表尾进行插入操作的线性表
/*
FIFO: First In First Out 先进先出
队头：允许删除的一端 front
队尾：允许插入的一端 rear
进就是插入，出就是删除，从队尾进，从队头出
假设q = (a1, a2, ..., an)是一个队列，那么a1是队头元素，an是队尾元素
*/

//顺序结构的实现
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int front, rear; //数组的下标
}Queue;

//初始化队列
void initQueue(Queue *q)
{
    q->front = q->rear = 0;
}

//判断队列是否为空，判断队头和队尾是否相等
int isempty(Queue *q)
{
    if (q->front == q->rear)
    {
        printf("队列为空\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

//出队 获取队头元素，front后移，相当于删除队头元素，但实际上并没有删除，只是front后移
ElemType dequeue(Queue *q)
{
    if (isempty(q))
    {
        return -1;
    }
    ElemType e = q->data[q->front];//获取队头元素
    q->front++;//队头指针后移
    return e;
}

//入队 队尾插入元素，rear后移
int equeue(Queue *q, ElemType e)
{
    if (q->rear == MAXSIZE)
    {
        if (!queuefull(q)) //如果队列真的已经满了，返回-1
        {
            return -1;
        }
    }
    q->data[q->rear] = e;
    q->rear++;
    printf("%d\n", q->rear);
    return 0;
}

//获取队头数据
int gethead(Queue *q, ElemType *e)
{
    if (isempty(q))
    {
        return -1;
    }
    *e = q->data[q->front];
    return 0;
}
   




//如果队列满了后的操作
//只是通过判断rear是否等于maxsize，并不能判断队列是否满了，因为队头可能还有空间
int queuefull(Queue *q)
{
    if (q->front >0) //如果队尾满了，但是队头还有空间，将队列中的元素向前移动
    {
        int step = q->front;
        for (int i = q->front; i<=q->rear; i++)
        {
            q->data[i-step] = q->data[i];
        }
        q->front = 0;
        q->rear = q->rear - step;
        return 1;
    }
    else
    {
        printf("队列已满\n");
        return 0;
    }
}



int main()
{
    Queue q;
    initQueue(&q);

    equeue(&q, 1);
    equeue(&q, 2);
    equeue(&q, 3);
    equeue(&q, 4); 
    equeue(&q, 5);

    //出队
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    ElemType e;
    gethead(&q, &e);
    printf("%d\n", e);



    return 0;
}