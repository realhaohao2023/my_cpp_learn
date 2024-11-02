#include <iostream> // C++标准输入输出库

using namespace std;

class date
{
    public:
    void init(int year, int month, int day)
    {
        //形参和成员变量同名，形参会覆盖成员变量，使用三种方法来规避这个问题
        _year = year; //在成员变量前加下划线
        date::month = month;//使用类名限定

        //前两项有一个问题，当方法放在公共区，不同的对象调用同一个函数，无法区分是哪个对象的成员变量
        this->day = day;//使用this指针
       
    }

    void print()
    {
        cout << _year << "-" << month << "-" << day << endl;
    }

    private:

    int _year;
    int month;
    int day;
};

int main()
{
    date d1, d2;
    d1.init(2021, 1, 1);
    d2.init(2042, 2, 2);
    d1.print();
    d2.print();
    return 0;
}