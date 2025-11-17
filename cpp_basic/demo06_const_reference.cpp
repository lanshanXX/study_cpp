#include <iostream>

using namespace std;


/*
    C++引用   引用和指针的区别？
    1.左值引用和右值引用
    2.引用实例


    引用是一种更安全的指针
    1.引用必须初始化，指针可以不初始化
    2.引用只有一级引用，指针可以多级引用
    3.定义一个引用变量，和定义一个指针变量，汇编指令是一样的，通过指针和修改指向内存的值，和通过引用修改所引用内存的值，汇编指令也是一样的

    右值引用
    1.int &&rref = 20;专门用来引用右值类型，指令上可以自动产生临时量然后直接引用临时量 c = 40;(可以修改临时量的值)
    2.右值引用本身是一个左值（有内存有空间有名字），只能用左值来引用
    3.右值引用不能引用左值
*/





#if 0
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


int main()
{

    int a = 10;
    int b = 20;
    swap(a, b);
    cout << "a=" << a << ",b=" << b << endl; // a=20,b=10

    // int a = 10;
    // int *p = &a;
    // int &b = a;

    // *p = 20;
    // /*
    //     mov eax,dword ptr [p]
    //     mov dword ptr [eax],20
    // */

    // b = 30;
    // /*
    //     mov eax,dword ptr [p]
    //     mov dword ptr [eax],30
    // */
 
    return 0;
}
#endif

#if 0
int main()
{
    int arr[5] = {};
    int *p = arr; //指针指向数组的第一个元素

    int (&ref)[5] = arr; //ref是一个引用，引用的是一个包含5个整数的数组

    return 0;

}
#endif


//左值引用和右值引用
int main()
{
    int a = 10;//左值，有内存，有名字，值可以修改
    int &ref = a; //左值引用，ref引用a

    //int &c = 20;//右值：没内存，没名字
    //cpp11提供了右值引用
    int &&rref = 20; //右值引用，rref引用一个右值20，此时编译器会在内存中开辟一个临时空间存放20
    /*
        mov dword ptr [临时空间],20
        lea eax,[临时空间]
        mov dword ptr [rref],eax
    */
    int &e = rref; //合法，左值引用可以引用右值引用,一个右值引用变量，本身是一个左值（此时rref有内存有空间有名字）
    int &&e = c;//不合法，右值引用不能引用左值,右值引用只能用来引用右值，不能引用左值
    /*
        int temp = 30
        temp -> cref
    */
    const int &cref = 30; //常量左值引用，可以引用右值
    /*
        mov dword ptr [临时空间],30
        lea eax,[临时空间]
        mov dword ptr [cref],eax
    */

    return 0;
}