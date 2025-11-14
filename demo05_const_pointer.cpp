#include <iostream>
#include <typeinfo>
using namespace std;



/*
    const与一级指针结合
    const与多级指针结合
    const修饰常出现的错误：
        1.常量不能再作为左值  （直接修改常量值）
        2.不能把常量的地址泄露给一个普通指针或者普通的引用变量 （间接修改常量值）
*/

/*
    const与一级指针结合
    cpp规范：const修饰的是离它最近的类型
    const int *p; //p是一个指向常量的指针，不能通过p修改它所指向的常量的值
    int const *p; //等价于上面
    int *const p; //p是一个常量指针，指针的值不能修改，但是可以通过p修改它所指向的变量的值
    const int *const p; //p是一个指向常量的常量指针
*/

int main1()
{
    const int a = 10;
    //int *p = &a; 不合法  int * <-- const int *
    //通过强制类型转换可以实现，但是不建议这样做
    // int *p = (int *)&a;
    // *p = 20; //未定义行为
    // cout << "a = " << a << endl; //可能输出20，也可能输出10
    const int *p1 = &a; //合法
/*
    从另一个角度理解：
    int * <=(赋值) const int *  不合法,const修饰的量能被改变
    int *const <=(赋值) int *  合法 
    const int * <=(赋值) int *  合法 
*/
    int b = 20;
    int *p2 = &b; //合法 --> int * <=(赋值) int *
    int *const p5 = &b; //合法 --> int * <=(赋值) int *
    int *const p6 = p2; //合法
    return 0;
}

/*
    const与二级指针结合,三种方式：
    const int **p; --> **p不能被赋值，*p,p可以被赋值
    int *const *p; --> *p不能被赋值，p可以被赋值，**p可以被赋值
    int **const p; --> p不能被赋值，*p,**p可以被赋值

    int ** <= (赋值) const int **  不合法
    const int ** <= (赋值) int **  不合法
    |
    |-->int  i  = 10;        // 非 const 对象
        const int ci = 20;   // const 对象

        int *pi = &i;        // pi 指向“可写 int”
        int **q  = &pi;      // q 指向“指向可写 int 的指针”

        const int **p = q;   // ← 假设这一步被允许（危险！）

        // 现在 *p 的类型是 “const int*” ，你可以把它改成指向任意 const int
        *p = &ci;            // 合法：把 *p（即原来的 pi）改成指向 const 对象 ci

        // 注意：q 和 p 指向的是同一个“指针对象”（也就是 pi）
        // 所以经过上一行，pi 已经被改为指向 const int（ci）
        **q = 42;            // 等价于 *pi = 42
                            // 但此时 pi 指向的是 const int（ci）！
                            // 通过“int*”写入到 const 对象 —— 违反 const，未定义行为


    int ** <= (赋值) int *const *  不合法
    int *const * <= (赋值) int **  合法
    |
    |
    |————>const * <= *
*/

int main1()
{
    int a = 10;
    int *p = &a;
    const int **pp = &p; // const int ** <= (赋值) int **  不合法
    /*
        const int *   *pp = &p; //等价于下面两步
        *pp <==> p
        const int b = 20;
        *p = &b; //通过p修改了b的值，违反了const的规则，未定义行为
        本质上是修改了中间一层指针的指向，导致未定义行为，如何修改
        1.使用int *const *pp;
        2.使用const int *const *pp;
    */
    return 0;
}