#include <iostream> // C++标准输入输出库
#include <string.h>

using namespace std;

//c++中，结构体不仅可以定义变量，还可以定义函数

struct student
{
    //成员变量
    int _id;
    char _name[20];
    int _age;

    //成员函数
    void init(const char* name, int age, int id)
    {
        strcpy(_name, name);
        _age = age;
        _id = id;
    }

    void print()
    {
        cout << "id: " << _id << " name: " << _name << " age: " << _age << endl;
    }
};

//c++中使用类（class)来代替，c++定义类可以用关键字class或者struct
//类中的数据称为类的属性或者成员变量
//类中的函数称为类的方法或者成员函数
//类中的属性和方法统称为类的成员
//三个访问限定符：public protected private
// public修饰的成员在类外可以直接被访问
// protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的)
// 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止
// 如果后面没有访问限定符，作用域就到 } 即类结束。
// class的默认访问权限为private，struct为public(因为struct要兼容C)
//用以规范成员的访问权限，提高代码的安全性和可维护性
class Example {
public:
    int publicVar; // 从这里开始到下一个访问限定符出现之前，成员都是 public 的

protected:
    int protectedVar; // 从这里开始到下一个访问限定符出现之前，成员都是 protected 的

private:
    int privateVar; // 从这里开始到类结束，成员都是 private 的
};

//struct和class的区别
//struct定义的类默认访问权限是public，class定义的类默认访问权限是private

class student2
{
    //成员变量
    int _id;
    char _name[20];
    int _age;

public:
    //成员函数
    void init(const char* name, int age, int id)
    {
        strcpy(_name, name);
        _age = age;
        _id = id;
    }

    void print()
    {
        cout << "id: " << _id << " name: " << _name << " age: " << _age << endl;
    }

    void printf();

};


//面向对象：封装、继承、多态
//封装体现在两方面，一是将数据和方法都放到类中封装起来，二是给成员增加访问权限的限制。
//封装定义：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来和对象进行交互。

//在类体外定义成员，需要使用 : : 作用域解析符指明成员属于哪个类域。

void student2::printf() //类体外定义成员函数
{
    cout << "hello,world" << endl;
}


int main()
{
    // student s1;
    // student s2;

    // s1.init("zhangsan", 20, 1);
    // s2.init("lisi", 21, 2);

    // s1.print();
    // s2.print();

    //类的实例化
    student2 s1;
    student2 s2;

    s1.init("zhangsan", 20, 1);
    s2.init("lisi", 21, 2);

    s1.print();
    s2.print();

    return 0;

}