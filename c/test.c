#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int *p = a; // pָ������a���׵�ַ

//�ṹ�������
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

//�����ṹ�����
struct point p1;


int main()
{
    // int a = 10;
    // int b = 20;
    // printf("����ǰa=%d,b=%d\n", a, b);
    // swap(&a, &b);
    // printf("������a=%d,b=%d\n", a, b);

    // p1.x = 10;
    // p1.y = 20;
    
    p1 = createPoint(10, 20);

    // printf("p1.x=%d,p1.y=%d\n", p1.x, p1.y);
    // printf("a���׵�ַ:%p\n", a);
    // printf("p��ֵ:%p\n", p); //40320
    // //p+1 ��ַ��һ��int���͵ĳ���,int����ռ4���ֽ�,���Լ�4
    // //��ӡp+1��ֵ
    // printf("p+1��ֵ:%p\n", p+1);//40324, 4���ֽ�,����ĵ�ַ��������
    // printf("����a�ĵ�һ��Ԫ��:%d\n", *(p+1));

    
}