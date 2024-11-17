#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


//枚举型
/*
将变量的值一一列举出来，称为枚举型，变量的值只限于列举出的值中
枚举中列出的每一个值，称为枚举元素
每一个枚举元素由系统定义了一个用序号表示的数值，从0开始
*/

enum weekday
{
    mon = 1, tue, wed, thu, fri, sat, sun
    //默认从0开始，给第一个元素赋值为1，后面的元素依次加1，就可以从1开始

};

enum bool
{
    false, true
};

typedef enum mytest
{
    test1, test2, test3

}test;

//表达式求值，中缀表达式转后缀表达式
/*
后缀表达式求值 82/2+56*-
字符串 "82/2+56*-\0"
op1、op2......用来存放操作数
symbol用来存放运算符 
对于后缀表达式，遇到数字就入栈，遇到运算符就出栈两个数进行运算，结果再入栈
运算套用 op1 symbol op2 = result ,先出栈的是op2，后出栈的是op1，运算结果入栈，继续根据后缀表达式进行运算

*/
typedef int ElemType;

//定义一个栈
typedef struct
{
    ElemType *data; //动态分配内存
    int top;
}Stack;

//定义内容类型枚举型
typedef enum
{
    LEFT_PARE,    //左括号
    RIGHT_PARE,   //右括号
    ADD,          //加
    SUB,          //减
    MUL,          //乘
    DIV,          //除
    MOD,          //取模 取余 %
    EOS,          //结束符  \0
    NUM           //数字
}contentType;

char expr[] = "82/2+56*-";

//初始化栈
Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (ElemType *)malloc(100 * sizeof(ElemType));
    s->top = -1;
    return s;
}

//判断栈是否为空
int isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//进栈
int push(Stack *s, ElemType e)
{
    if (s->top == 100 - 1)
    {
        printf("栈满\n");
        return -1;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

//出栈
int pop(Stack *s, ElemType *e)
{
    if (isEmpty(s))
    {
        return -1;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

//获取栈顶元素
int getTop(Stack *s, ElemType *e)
{
    if (isEmpty(s))
    {
        return -1;
    }
    *e = s->data[s->top];
    return 1;
}



//获取表达式中的内容类型
contentType getToken(char *symbol, int *index) //传入表达式字符串和索引的指针
{
    *symbol = expr[*index];  //获取表达式中的字符，index默认是0，第一次获取的是第一个字符
    *index = *index + 1; //每次操作时通过地址传递+1，后面再调用时，index就是上一次的值+1
    switch (*symbol)
    { 
        case '(':
            return LEFT_PARE;
        case ')':
            return RIGHT_PARE;
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MUL;
        case '/':
            return DIV;
        case '%':
            return MOD;
        case '\0':
            return EOS;
        default:
            return NUM;
    }
}


//计算后缀表达式
int eval(Stack *s)
{
    char sysmbol; //从表达式中获取的字符
    int op1, op2; //存放操作数
    int index = 0;//扫描字符串的索引
    contentType token; //存放每次扫描的内容类型
    token = getToken(&sysmbol, &index); //获取表达式中的内容类型
    //通过地址传递的方式，让sysmbol存放表达式中的字符，index存放索引
    ElemType result; //存放单次运算结果
    ElemType result_final; //存放最终的结果
    while(token != EOS) //如果获取的内容不是结束符，就进行进栈和出栈和计算
    {
        if (token == NUM)
        {
            push(s, sysmbol - '0'); //将字符转换为数字，然后进栈
            //字符'0'的ASCII码是48，'1'的ASCII码是49，'2'的ASCII码是50，'3'的ASCII码是51
            //'8' - '0' = 8，将字符数字转化为整形数字
        }
        else
        {
            pop(s, &op2); //出栈两个操作数
            pop(s, &op1);
            switch (token)
            {
                case ADD:
                    result = op1 + op2;
                    break;
                case SUB:
                    result = op1 - op2;
                    break;
                case MUL:
                    result = op1 * op2;
                    break;
                case DIV:
                    result = op1 / op2;
                    break;
                case MOD:
                    result = op1 % op2;
                    break;
            }
            push(s, result); //将运算结果入栈
        }
        token = getToken(&sysmbol, &index); //获取下一个内容类型
    }//直到获取的内容类型是结束符，结束循环，此时result就是表达式的结果

    pop(s, &result_final); //将栈顶元素出栈，此时栈中只有一个元素，就是表达式的结果
    printf("%d\n", result);
    return 1;
}

/*======================================================================================================*/
//中缀表达式转后缀表达式
//重点：运算符的优先级
/*
x/(i-j)*y -> xij-/y* 后缀表达式出现运算符时计算运算符前两个操作数的值（符合栈的先入后出特性）

逐个扫描，如果是数字，直接输出，如果是运算符，就要判断优先级

栈中先放一个优先级最低的运算符0，扫描到运算符，如果优先级大于栈顶元素，就入栈，否则将栈顶元素出栈并输出，然后把当前运算符入栈
左括号在栈外时，优先级最高（一定进栈），在栈内时，优先级最低（如果优先级还是最高，后面的运算符就不能进栈了）
如果扫描到右括号，且此时栈顶不是左括号，就持续出栈并输出，直到栈顶是左括号，左括号出栈（不输出）并结束

常见运算符的优先级（数字越大优先级越大）：
*/
 
//示例数组
char expr2[] = "x/(i-j)*y";

//把内容类型输出
int print_token(contentType token)
{
    switch(token)
    {
        case ADD:
            printf("+");
            break;
        case SUB:
            printf("-");
            break;
        case MUL:
            printf("*");
            break;
        case DIV:
            printf("/");
            break;
        case MOD:
            printf("%");
            break;
        default:
            return 0;
        //转化后的后缀表达式没有左括号和右括号  
    }
    return 1;
}

//把中缀表达式转换为后缀表达式
void postfix(Stack *s)
{
    //内容类型枚举型contentType的元素一一对应的优先级（0到8，可以直接拿来当数组下标来检索对应的优先级）
    int in_stack[] = {0, 19, 12, 12, 13, 13, 13, 0}; 
    int out_stack[] = {20, 19, 12, 12, 13, 13, 13, 0}; 

    contentType token; //存放每次扫描的内容类型
    int index = 0; //扫描字符串的索引
    s->data[0] = EOS; //栈底放一个结束符，优先级最低，起到一个让其他任意运算符都可以进栈的作用

    char symbol; //存放表达式中的字符
    ElemType e; 

    token = getToken(&symbol, &index); //获取表达式中的内容类型

    while (token != EOS)
    {
        if (token == NUM)
        {
            printf("%c", symbol); //如果是数字，直接输出
        }
        else if (token == RIGHT_PARE)
        {
            while (s->data[s->top] != LEFT_PARE)
            {
                pop(s, &e); //出栈
                print_token(e); //输出
            }
            pop(s, &e); //左括号出栈
        }
        else
        {
            while (in_stack[s->data[s->top]] >= out_stack[token]) //判断扫描到的内容类型和栈顶元素的优先级大小
            {
                pop(s, &e); //出栈
                print_token(e); //输出
            }
            //如果优先级大于栈顶元素，就入栈
            push(s, token); //入栈
        }


        token = getToken(&symbol, &index); //获取下一个内容类型

    }
}


int main()
{
    enum weekday day;
    day = mon;
    printf("%d\n", day); //枚举型的序号，从0开始

    test t;
    t = test1;
    printf("%d\n", t);

    //分隔符
    printf("=====================================\n");
    Stack *s = initStack();
    eval(s);
}