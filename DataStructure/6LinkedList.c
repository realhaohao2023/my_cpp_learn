#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 线性表链式存储结构
// 用一组任意的存储单元存储线性表的数据元素，可以是连续的，也可以是不连续的

// 为了表示每个数据元素a1,a2,...,an与其直接后继数据元素a2,a3,...,an之间的逻辑关系
// 除本身的数据元素信息外，还需要存储一个指示其直接后继的存储位置的信息

// 这两部分信息组成数据元素的存储映像，称为结点
// 数据域 + 指针域

typedef int ElemType;

typedef struct Node
{
    ElemType data;     // 数据域
    struct Node *next; // 指针域 下一个结点的地址 尾节点的指针域为NULL

    //指针域也是一个结构体指针，代表这个指针直接指向下一个结点，方便我们遍历链表
    //p = p->next; 就能实现往下一个结点移动
} Node;

// 初始化
Node *Initlist() // 创建一个头结点
{
    Node *head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("内存分配失败\n");
        exit(0);
    }
    head->data = 0;
    head->next = NULL;
    return head;
}

// 头插法，每次都是在头结点后面插入数据
Node *insertHead(Node *head, ElemType e)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(0);
    }
    newNode->data = e;
    // 顺序，先让新结点的指针域指向头结点指向的下一个结点
    // 再让头结点的指针域指向新结点
    newNode->next = head->next; // 新结点的指针域改为原本头结点的指针域
    head->next = newNode;       // 头结点的指针域改为新结点的地址
    return newNode;
}

// 尾插法 先获取尾结点的地址
Node *get_tail(Node *head)
{
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

Node *insertTail(Node *tail, ElemType e)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // 为一个新的结点申请动态内存
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(0);
    }
    newNode->data = e;    // 新结点的数据域赋值
    tail->next = newNode; // 尾结点的指针域指向新结点
    newNode->next = NULL; // 新结点的指针域指向NULL

    return newNode;
}

// 在指定位置插入元素
Node *insertElem(Node *head, int pos, ElemType e)
{
    Node *p = head;
    int i = 0;
    while (i < pos - 1) // 寻找插入的位置 最后得到的p就是插入位置的前驱结点
    {
        p = p->next;
        i++;
        if (p == NULL)
        {
            printf("插入位置不合法\n");
            return NULL;
        }
    }
    // 要插入的新结点
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(0);
    }
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return newNode;
}

// 删除指定位置的结点
int deleteNode(Node *L, int pos)
{
    //要删除的结点的前驱结点
    Node *p = L;
    int i = 0;
    //遍历链表
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)
        {
            printf("删除位置不合法\n");
            return -1;
        }
    }

    //判断前驱结点指向的是否是空结点
    if (p->next == NULL)
    {
        printf("删除位置不合法\n");
        return -1;
    }

    //q指向要删除的结点 目的是为了free(q)，释放被删除的结点占用的内存
    Node *q = p->next;
    p->next = q->next; //前驱结点执行要删除结点的后继结点
    free(q);

    return 0;
}

// 单链表的遍历
void displayList(Node *head)
{
    Node *p = head->next; // p指向第一个结点
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

//单链表 获取链表长度 从头结点开始
int listLength(Node* L)
{
    int len = 0;
    Node* p = L;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

//单链表 释放链表 把每一个结点的内存空间都释放掉 但是保留头结点
void freeList(Node* L)
{
    Node* p = L->next; //指向头节点后的第一个结点
    Node* q = NULL; //记录q的后继结点
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

//找到单链表倒数第k的结点
//用快慢指针，快指针先走k步，然后快慢指针同步走，直到快指针指向NULL，此时慢指针指向的就是倒数第k个结点
int findNodeFS(Node *L, int k)
{
    Node *fast = L->next;  //指向第一个结点，即头结点的下一个结点
    Node *slow = L->next; 
    
    for(int i = 0; i < k; i++)
    {
        if(fast == NULL)
        {
            printf("k值不合法\n");
            return -1;
        }
        fast = fast->next;
    }

    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    printf("FS %d is %d\n", k, slow->data);
    return 0;
}

//反转链表
//使用三个指针，分别指向当前结点，前一个结点，后一个结点，循序渐进，依次反转，直到second指向NULL，再让头结点指向first
Node* reverseList(Node* Head)
{
    Node *first = NULL; //先让first指向NULL，而不是头结点
    Node *second = Head->next;
    Node *third = NULL;

    while (second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    //再造一个头结点，指向first
    Node *newHead = Initlist();
    newHead->next = first;

    return newHead;

}

//删除链表中的中间结点
//使用快慢指针，快指针每次走两步，慢指针每次走一步，当快指针走到尾结点时，慢指针指向的就是中间结点
int delMiddleNode(Node *head)
{
    Node *fast = head->next; //指向首结点
    Node *slow = head; //指向头结点

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next; //快指针每次走两步
        slow = slow->next; //慢指针每次走一步
    }

    Node *q = slow->next; //要删除的结点
    slow->next = q->next; //前驱结点指向后继结点
    free(q); //释放被删除结点的内存
    return 1;
}

//单向循环链表：尾结点的指针域指向头结点

//遍历完成的条件：当前指针p的 p!=head 或 p->next != head
//单链表的遍历完成调节：p->next != NULL 或 p != NULL

//判断链表是否有环
int isCycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            return 1;
        }
    }
    return 0;
}



int main()
{
    Node *list = Initlist();

    // 头插法
    insertHead(list, 1);
    insertHead(list, 2);
    insertHead(list, 3);

    // 尾插法
    Node *tail = get_tail(list);
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);

    //插入结点
    insertElem(list, 3, 100);

    //删除结点
    deleteNode(list, 6);

    tail = insertTail(tail, 93);

    displayList(list);

    //打印链表长度
    printf("%d\n", listLength(list));

    //分隔符
    printf("=====================================\n");

    //freeList(list);
    //遍历链表，打印长度
    //displayList(list);
    //printf("%d\n", listLength(list));

    //找到倒数第5个结点
    findNodeFS(list, 4);

    //分隔符
    printf("=====================================\n");

    // //反转链表
    // Node* reverse = reverseList(list);
    // displayList(reverse);

    //分隔符
    printf("=====================================\n"); 
    //删除中间结点
    delMiddleNode(list);
    displayList(list);
    return 0;
}