#include <iostream>
#include <cstring>
using namespace std;


/*
    oop四大特征：抽象 封装 继承 多态

*/

const int NAME_LEN = 20;
class CGoods
{
    public: //提供公有的方法，来访问私有属性,类体内实现的方法，自动处理成inline内联函数
        void init(const char *name, double price, int num)
        {
            strncpy(_name, name, NAME_LEN);
            _price = price;
            _num = num;
        }
        void print();
        // void print()
        // {
        //     cout << "name: " << _name << endl;
        //     cout << "price: " << _price << endl;
        //     cout << "num: " << _num << endl;
        // }
        void setName(const char *name)
        {
            strncpy(_name, name, NAME_LEN);
        }
        void setPrice(double price)
        {
            _price = price;
        }
        void setNum(int num)
        {
            _num = num;
        }
        const char *getName()
        {
            return _name;
        }
        double getPrice()
        {
            return _price;
        }
        int getNum()
        {
            return _num;
        }


    private: //属性一般私有
        char _name[NAME_LEN];
        double _price;
        int _num;
};
//类外定义时，要加作用域符
void CGoods::print()
{
    cout << "name: " << _name << endl;
    cout << "price: " << _price << endl;
    cout << "num: " << _num << endl;
}





int main()
{
    /*
        CGoods可以定义无数对象，每一个对象都有自己的成员变量，但是共享同一套成员方法
        方法是怎么知道操作那个对象的成员变量的呢？
        类的成员方法一经编译，所有方法参数，都会加一个this指针，接收调用该方法的对象地址
    */
    CGoods good;
    //init(&good, "apple", 5.5, 100); 
    good.init("apple", 5.5, 100);
    good.print();

}