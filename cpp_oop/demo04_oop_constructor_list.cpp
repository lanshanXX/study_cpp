#include <iostream>
#include <cstring>
using namespace std;



class CDate
{
public:
    CDate(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    void print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
private:
    int _year;
    int _month;
    int _day;
}

/*
    CDate是CGoods的成员变量
    成员变量的初始化顺序和它们定义的顺序有关，而不是和初始化列表中出现的顺序有关
*/
const int NAME_LEN = 20;
class CGoods
{
public:
    CGoods(const char *n, int a, double p, int y, int m, int d)
        : _productDate(y, m, d)// -->相当于CDate _productDate(y, m, d);
        //，_price(p) -->int _price=p
        //,_num(a)
        // 这样写也行 
        // //1.构造函数初始化列表（先执行）
    {
        //2.当前类类型构造函数体（后执行）
        strncpy(_name, n, NAME_LEN);
        _price = p; //-->int _price;_price = p;
        _num = a;
    }
    void CGoods::print()
    {
        cout << "name: " << _name << endl;
        cout << "price: " << _price << endl;
        cout << "num: " << _num << endl;
    }
private:
    char _name[NAME_LEN];
    double _price;
    int _num;
    CDate _productDate; //成员变量的初始化列表
};






int main()
{

    CGoods good("apple", 100, 3.5, 2023, 5, 1);
    good.print();

}