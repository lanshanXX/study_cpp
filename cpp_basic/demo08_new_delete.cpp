#include <iostream>




using namespace std;


/*
    new和delete
    new和malloc的区别
    delete和free的区别




    malloc free 是库函数
    new delete 是运算符

    new不仅能开辟内存，还能做内存初始化操作
    malloc开辟内存失败，是通过返回nullptr做比较；new开辟内存失败，是通过抛出异常std::bad_alloc来处理
*/
/*
    new有多少种
    1.普通new：int *p = new int;  会调用构造函数
    2.int *p1 = new (nothrow) int;  不会抛出异常，开辟失败返回nullptr
    3.const int *p2 = new const int;  常量类型
    //定位new
    4.int data = 0;
      int *p3 = new (&data) int(50);//在data的内存地址上开辟一个int类型，并初始化为50

*/


int main()
{

    int *p = (int *)malloc(sizeof(int)); //malloc不会调用构造函数
    *p = 10;
    free(p); //free不会调用析构函数



    int *q = new int(10); //new会调用构造函数
    *q = 20;
    delete q; //delete会调用析构函数

    // try
    // {
    //     int *q = new int(10); //new会调用构造函数
    // }
    // catch (std::bad_alloc &e)
    // {
    //     cout << "内存分配失败" << endl;
    // }



    int *arr = (int *)malloc(10 * sizeof(int)); 
    int *arr2 = new int[10]; //new开辟数组但是不初始化
    int *arr2 = new int[10](); //new开辟数组并初始化为0
    delete[] arr2; //delete数组必须加[]

    return 0;
}