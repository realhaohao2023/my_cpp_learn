#include <iostream> // C++标准输入输出库

using namespace std;

//for循环后的括号由冒号“ ：”分为两部分：第一部分是范围内用于迭代的变量，第二部分则表示被迭代的范围。

int arr[] = {1, 2, 3, 4, 5};
//迭代范围必须是确定的
//对于类来说，必须实现begin()和end()方法

int main()
{
    for (int i : arr)
    {
        cout << arr[i-1] << endl;
    }
    return 0;
}