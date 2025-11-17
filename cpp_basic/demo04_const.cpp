#include <iostream>
using namespace std;

/*
    const 指针 引用 在函数中的引用
    const如何理解
    ：const修饰的变量不能作为左值，初始化完成后不能修改

    C:在C语言中，const修饰的量可以不用初始化
      不叫常量，叫常变量，例如
        const int a = 10;
        int arr[a] = {0};//不合法，数组里面要填常量，但是这时候a还是变量，只不过是常变量
      const只是语法层面上将a修饰为常变量，编译器并没有对a进行特殊处理，a依然是变量，只不过不能作为左值使用
      但是可以通过对内存修改进行赋值
        int *p = (int *)&a;
        *p = 20;//合法，通过内存修改的方式修改了a的值
        printf("a = %d\n", a);//20
    
    C++:在C++中，const修饰的量必须初始化，叫常量，可以作为数组下标
        const int a = 10;
        int arr[a] = {0};//合法，a是常量，可以作为数组下标使用
    //C中,const只是当作一个变量来编译生成指令，cpp中所有出现const的地方，都被常量的初始化替换掉了
    const int a = 10;
    int *p = (int *)&a;
    *p = 20;//
    printf("%d %d %d \n", a,*p,*(&a));//10 20 10
*/

int main()
{
    const int a = 10;
    int *p = (int *)&a;
    *p = 20;//
    printf("%d %d %d \n", a,*p,*(&a));//10 20 10
    /*
    printf("%d %d %d \n", a,*p,*(&a));
    等价于将所有出现a的地方都用10替换掉了
        | |
        | |
    printf("%d %d %d \n", 10,*p,*(&10));
    */
    //这就是为什么cpp中const修饰的量必须初始化的原因，不初始化的话，cpp编译器无法将其替换掉
    return 0;
}

int main1()
{
    /*
      用变量初始化，就变成常变量了，与C语言就变为一致
      变量b在编译阶段是不可知的，编译器无法将所有出现a的地方替换成b
      因此int arr[a]是不合法的，此时a就是常变量，而不是常量
      printf("%d %d %d \n", a,*p,*(&a));里面也无法替换成b，最终结果与C语言中一致
    */
    int b = 10;
    const int a = b;

    int *p = (int *)&a;
    *p = 20;//
    printf("%d %d %d \n", a,*p,*(&a));//20 20 20
    
    return 0;
}