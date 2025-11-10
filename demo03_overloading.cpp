#include <iostream>

using namespace std;
/*
    cpp为什么支持重载,c为什么不支持重载、
    A：cpp代码产生函数符号的时候，由函数名加参数列表类型构成唯一的函数符号
       c代码产生函数符号的时候，只有函数名，没有参数列表类型
    函数重载注意什么
    A:一组函数要称得上重载，一定先处在同一作用域中
    cpp和c之间如何相互调用
    const和volatile是如何影响形参类型的
    仅仅靠返回值类型不同，不能构成函数重载，重载主要是因为生成的函数符号不同而产生重载，函数符号由函数名和返回值类型组成

    多态
    静态（编译时期）多态：函数重载
    动态（运行时期）多态：
*/
/*
    cpp调用c函数
    extern "C" {
        //c函数声明
    }
    c调用cpp函数
    extern "C" {
        //c函数源码 
    }
    extern "C" 这个只有cpp编译器认识，c编译器不认识

    //这种写法更加灵活，c编译器和cpp编译器都能编译，上面的写法只能在cpp编译器下编译
    #ifdef __cplusplus
    extern "C" {
    #endif
        //c函数源码
    #ifdef __cplusplus
    }
    #endif
*/
/*
    函数重载：函数名相同，参数列表不同（参数个数不同，参数类型不同，参数顺序不同）
    函数重载发生在编译阶段，通过参数列表区分不同的函数
    函数重载和返回值类型无关
    函数重载和形参的默认值无关
    函数重载注意事项：
        1.函数名相同，参数列表不同
        2.函数重载和返回值类型无关
        3.函数重载和形参的默认值无关
        4.函数重载发生在编译阶段，通过参数列表区分不同的函数
*/
bool compare(int a, int b) //compare_int_int
{
    cout << "compare(int, int) called" << endl;
    return a > b ;
}

bool compare(double a, double b) //compare_double_double
{
    cout << "compare(double, double) called" << endl;
    return a > b ;
}

bool compare(const char* a, const char* b) //compare_constchar_constchar
{
    cout << "compare(const char*, const char*) called" << endl;
    return strcmp(a, b) > 0 ;
}

int main()
{
    //bool compare(int a, int b); //函数声明,作用域会导致下面调用出错
    int a = 10;
    int b = 20;

    bool ret = compare(a, b);
    cout << "ret = " << ret << endl;

    double d1 = 3.14;
    double d2 = 2.18;
    ret = compare(d1, d2);
    cout << "ret = " << ret << endl;

    const char* str1 = "hello";
    const char* str2 = "world";
    ret = compare(str1, str2);
    cout << "ret = " << ret << endl;

    return 0;
}