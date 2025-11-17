#include <iostream>



using namespace std;





/*
    构造函数和析构函数
    函数名字和类名一样
    没有返回值

    先构造的后析构，后构造的先析构
    析构函数不带参数，构造函数可以带参数，因此构造函数可以重载，析构函数不能重载
    .data段的对象程序启动时构造，程序退出时析构
    heap ,new时候构造，delete时候析构
    stack ,进入作用域构造，离开作用域析构
*/

//堆区构造对象，只有当delete时才会调用析构函数

/*
    对象的浅拷贝和深拷贝
    对象的默认拷贝函数是做内存拷贝，浅拷贝，如果指向同一个内存，析构是会出现问题
*/
/*
    赋值重载函数：防止自赋值，需要释放当前对象占用的外部资源，执行赋值操作
*/

class String 
{
public:
    String(const char* str = nullptr) //普通构造函数
    {
        if (str == nullptr)
        {
            m_data = new char[1];
            *m_data = '\0';
        }
        else
        {
            m_data = new char[strlen(str) + 1];
            strcpy(m_data, str);
        }
    }
    String(const String& s) //拷贝构造函数
    {
        m_data = new char[strlen(s.m_data) + 1];
        strcpy(m_data, s.m_data);
    }
    ~String() //析构函数
    {
        delete[] m_data;
        m_data = nullptr;
    }
    String& operator=(const String& s) //赋值重载函数
    {
        if(this == &s)//防止自赋值
        {
            return *this;
        }
        delete[] m_data; //释放当前对象占用的资源
        m_data = new char[strlen(s.m_data) + 1];
        strcpy(m_data, s.m_data);//执行赋值操作
        return *this;
    }
private:
    char* m_data;
}

int main()
{
    /*
        seq s; //没有提供任何构造函数的时候，会默认生成构造函数和析构函数，是空函数
        seq s1(10);
        seq s2 = s1; //拷贝构造函数，内存的拷贝，浅拷贝
        seq s3(s1);
    */
    //调用带const char*的构造函数
    String s1;
    String s2("hello");

    //调用拷贝构造函数
    String s3 = s2; 
    String s4(s3);

    //调用赋值重载函数
    s1 = s2; 
    /*
    String& operator=(const String& s) //赋值重载函数
    {
        if(this == &s)//防止自赋值
        {
            return *this;
        }
        delete[] m_data; //释放当前对象占用的资源
        m_data = new char[strlen(s.m_data) + 1];
        strcpy(m_data, s.m_data);//执行赋值操作
        return *this;
    }
    //这里返回值也可以是void类型的，但是返回引用类型可以支持链式赋值
    s1 = s2 = s3;
    否则会出错
    */

    return 0;
}