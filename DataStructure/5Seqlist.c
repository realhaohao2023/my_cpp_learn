#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

//���Ա�: ��n������������ͬ������Ԫ����ɵ���������
//����Ԫ�ذ��������Ρ��ַ��͡��ṹ�塢�����

//����Ψһ��һ������Ϊ��һ��Ԫ�ص�����Ԫ�أ�ͷ���
//����Ψһ��һ������Ϊ���һ��Ԫ�ص�����Ԫ�أ�β���
//����һ��Ԫ���⣬ÿ��Ԫ�����ҽ���һ��ǰ��Ԫ��
//�����һ��Ԫ���⣬ÿ��Ԫ�����ҽ���һ�����Ԫ��


//˳�����һ�ε�ַ�����Ĵ洢��Ԫ���δ洢���Ա������Ԫ��
//һ����������ʵ��˳���



//˳���Ĵ洢�ṹ
#define MAXSIZE 100
typedef int ElemType;
// typedef struct  //����һ��˳���
// {
//     ElemType data[MAXSIZE]; //���˳���Ԫ��
//     int length; //���˳���ĳ���

// }SeqList;

typedef struct 
{
    ElemType *data; //���˳���Ԫ��
    int length;
    /* data */
}SeqList;


//˳���ĳ�ʼ��
// void InitList(SeqList *L) //���ݽṹ������ĵ�ַ
// {
//     L->length = 0; //��ǰ˳�����û��Ԫ��
// }

//��̬�ڴ����
SeqList* InitList() //�ڶ��ڴ��и�˳�������ռ�
{
    SeqList *L = (SeqList *)malloc(sizeof(SeqList)); //����������һ���ṹ��ָ��
    L->data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if (L->data == NULL)
    {
        printf("�ڴ����ʧ��\n");
        exit(0);
    }
    L->length = 0;
}

//����˳���
void displayList(SeqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("��%d������Ϊ%d\n", i+1, L->data[i]);
    }
}

//��β������Ԫ��
int appendElem(SeqList *L, ElemType e) //��˳����β������Ԫ��e
{
    if (L->length == MAXSIZE) //˳�������
    {
        return -1;
    }
    L->data[L->length] = e; //��e���뵽˳�������
    L->length++; //˳����ȼ�1
    return 0;
}

//��ָ��λ�ò���Ԫ��
//�����Ԫ����������ƶ�
//˳����е�λ�ô�1��ʼ
int insertElem(SeqList *L, int pos, ElemType e)
{
    if (pos < 0 || pos > L->length || L->length == MAXSIZE) //����λ�ò��Ϸ�����˳�������
    {
        printf("����λ�ò��Ϸ�����˳�������\n");
        return -1;
    }

    //�Ӻ�ǰ��������ƶ�
    for (int i = L->length - 1; i >= pos; i--)
    {
        L->data[i + 1] = L->data[i];
    }
    L->data[pos-1] = e;
    L->length++;
    return 0;
}

//ɾ��ָ��λ�õ�Ԫ��
int deleteElem(SeqList *L, int pos, ElemType *e)
{
    *e = L->data[pos-1];
    if (pos < 0 || pos > L->length)
    {
        printf("ɾ��λ�ò��Ϸ�\n");
        return -1;
    }

    //ÿ��ѭ������ĸ���ǰ���
    for (int i = pos; i < L->length; i++)
    {
        L->data[i-1] = L->data[i];
    }
    L->length--;
    return 0;
}


//����ĳ��Ԫ����˳����е�һ�γ��ֵ�λ��
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

ElemType deletedata; //ɾ��������

int main()
{


    // book b1;
    // b1.num = 1;
    // strcpy(b1.name, "C����");
    // b1.price = 20.5;
    // printf("b1.num=%d,b1.name=%s,b1.price=%f\n", b1.num, b1.name, b1.price);

    //SeqList L1; //����һ��˳���
    //InitList(&L1); //��ʼ��˳���

    //��Ϊ��̬�ڴ���䣬�ڳ�ʼ������������һ���ṹ��ָ��
    SeqList *L1 = InitList();
    //�ں����ĺ�������������ټ�ȡ��ַ����&



    //��ʾ����
    printf("��ʼ���ɹ�����Ϊ%d\n", L1->length);
    //��ʾ����dataռ�õ��ڴ�
    printf("ռ�õ��ڴ�Ϊ%d\n", sizeof(L1->data));

    appendElem(L1, 0);
    appendElem(L1, 1);
    appendElem(L1, 2);
    appendElem(L1, 3);
    appendElem(L1, 4);
    appendElem(L1, 100);
    appendElem(L1, 200);
    appendElem(L1, 300);

    //����˳���
    displayList(L1);
    //�ָ���
    printf("=====================================\n");

    insertElem(L1, 3, 1000);
    displayList(L1);
    insertElem(L1, 300, 1000);

    //�ָ���
    printf("=====================================\n");

    deleteElem(L1, 3, &deletedata);
    displayList(L1);
    printf("ɾ��������Ϊ%d\n", deletedata);
    printf("����4��λ��Ϊ%d\n", locateElem(L1, 4));




    return 0;
}
