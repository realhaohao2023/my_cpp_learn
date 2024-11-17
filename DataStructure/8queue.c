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
// typedef struct
// {
//     ElemType data[MAXSIZE];
//     int front, rear; //数组的下标
// }Queue;

// //初始化队列
// void initQueue(Queue *q)
// {
//     q->front = q->rear = 0;
// }


//动态分配内存
typedef struct
{
    ElemType *data;
    int front, rear;
}Queue;

Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    q->front = q->rear = 0;
    return q;
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
   






/*=================================================================================================================*/
//循环队列，解决顺序队列的假溢出问题（队尾已经满了，但是队头还有空间）

//入队 
int queue2(Queue *q, ElemType e)
{
    if ((q->rear+1) % MAXSIZE == q->front) //队尾指针+1取余等于队头指针，队列满了
    /*
    假设MAXSIZE = 8 ,rear = 7, front = 0, 7+1%8 = 0
    假设MAXSIZE = 8 ,rear = 6, front = 7, 6+1%8 = 7
    队尾下标和队头下标相邻，队列满了
    */
    {
        printf("队列已满\n");
        return 0;
    }
    q->data[q->rear] = e; //给队尾下标对应的元素赋值
    q->rear = (q->rear+1) % MAXSIZE; //队尾指针+1取余
    //原本是自增+1，但是在环形队列中，当rear到达MAXSIZE时，需要回到0，所以取余
    //假设MAXSIZE = 8, rear = 7, rear+1 = 8, 8%8 = 0

    //先赋值，再后移
    return 1;
}

//如果对头队尾都指向0，那么队尾指向的是最后一个元素的下一个位置


//出队
int dequeue2(Queue *q, ElemType *e)
{
    if(q->front == q->rear) //判满
    {
        printf("队列为空\n");
        return 0;
    }

    *e = q->data[q->front]; //获取队头元素
    q->front = (q->front+1) % MAXSIZE; //队头指针后移
}

//获取队头元素
int gethead2(Queue *q, ElemType *e)
{
    if(q->front == q->rear) //判满
    {
        printf("队列为空\n");
        return 0;
    }

    *e = q->data[q->front]; //获取队头元素
    return 1;
}

/*==========================================================================================================*/
//队列的链式结构
//用两个结构体分别控制，一个用来存储链表本身，另一个用来存储队头和队尾指针



//链表，作为队列的主体，由Queue_link进行队列的操作
typedef struct QueueNode
{
    ElemType data;
    struct QueueNode *next;//指针域为结构体指针，指向下一个结点
}QueueNode;

//队列结构体，只用来存放队头和队尾指针，指向链表中的结点，来实现队列的操作
typedef struct 
{
    QueueNode *front, *rear; //队头和队尾指针
    /* data */
}Queue_link;


//链式队列初始化
Queue_link *initQueue_link()
{
    Queue_link *q = (Queue_link *)malloc(sizeof(Queue_link)); //申请一个队列的内存
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode)); //申请一个结点的内存
    //链表的头结点 
    node->data = 0; 
    node->next = NULL;

    q->front = q->rear = node; //队头和队尾指向头结点
    return q; 
}

//判断队列是否为空，判断队头和队尾是否相等
int isempty_link(Queue_link *q)
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


//入队
//可以用链表的头插法，也可以用尾插法
//链表的首结点既可以是队头也可以是队尾，自己确定
//如果把链表的首结点设置为队尾(入队)，那么就用头插法，从链表的头部入队
//如果把链表的首结点设置为队头(出队)，那么就用尾插法，从链表的尾部入队

//这里用尾插法，链表的首结点是队头，链表的尾结点是队尾
//这样的优点是，每次入队都是在尾结点，出队都是首结点在删除，不用每次都遍历链表找到尾结点
//是吗？已经用queue_link存放的队头和队尾指针指向了链表中的结点，用头插法和尾插法好像都不用去遍历
int equeue_link(Queue_link *q, ElemType e)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(0);
    }
    newNode->data = e;
    newNode->next = NULL;
    q->rear->next = newNode;
    //q->rear是链表尾结点，q->rear->next是原本尾结点的指针域，这个操作是让新结点成为链表的尾结点
    q->rear = newNode; //让队尾指向新结点，更新队尾指针指向的结点，让rear挪到新结点
    return 1;
}

//出队
//还是以把首结点作为队头
int dequeue_link(Queue_link *q, ElemType *e)
{
    QueueNode *node = q->front->next; //队头指针指向头结点，队头指针的下一个结点才是队头
    //q->front是头结点，q->front->next是队头
    *e = node->data; //获取队头元素
    q->front->next = node->next; //队头指针的下一个结点指向队头的下一个结点
    //相当于队头后移
    if (q->rear == node) //如果队头指针指向的是队尾，那么队列为空
    {
        q->rear = q->front; //队尾指针指向头结点
    }
    free(node); //释放被删除的结点的内存
    return 1;
}

//获取队头元素
ElemType getfront_link(Queue_link *q)
{
    if (isempty_link(q))
    {
        printf("队列为空\n");
        return -1;
    }
    return q->front->next->data;
}

//遍历链式队列
void displayQueue_link(Queue_link *q)
{
    QueueNode *p = q->front->next; //指向队头
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}


int main()
{
    // Queue *q;
    // initQueue(q);

    // equeue(q, 1);
    // equeue(q, 2);
    // equeue(q, 3);
    // equeue(q, 4); 
    // equeue(q, 5);

    // //出队
    // printf("%d\n", dequeue(q));
    // printf("%d\n", dequeue(q));

    // ElemType e;
    // gethead(q, &e);
    // printf("%d\n", e);

    //创建一个链式队列
    Queue_link *q = initQueue_link();
    equeue_link(q, 1);
    equeue_link(q, 2);
    equeue_link(q, 3);
    equeue_link(q, 4);
    //遍历队列
    displayQueue_link(q);

    //分隔符
    printf("=====================================\n");
    //出队
    ElemType e;
    dequeue_link(q, &e);
    printf("%d\n", e);
    dequeue_link(q, &e);
    printf("%d\n", e);

    displayQueue_link(q);




    return 0;
}