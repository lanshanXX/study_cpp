#include <iostream>

using namespace std;

//形参带默认值的函数
//给默认值的时候，从右想左
//定义处和声明处都能给默认值，但只能给一次
int sum(int a = 10, int b = 20)
{
    return a + b ;
}

int main()
{
    int a =10;
    int b =20;

    int ret = sum(a, b); //实参传递给形参
    cout << "ret = " << ret << endl;
    /*
        mov eax, DWORD PTR [rbp-8]  //a
        push eax
        mov ecx, DWORD PTR [rbp-4]  //b
        push ecx
        call sum
    */

    ret = sum(a); //实参传递给第一个形参，第二个形参使用默认值
    ret = sum(a,40);
    cout << "ret = " << ret << endl;
    //上述两者效率一样，都会少一次mov指令，直接将立即数压栈
    /*
        push 14h
        mov ecx, DWORD PTR [rbp-4]  //a
        push ecx
        call sum
    */
    ret = sum(); //两个形参都使用默认值
    cout << "ret = " << ret << endl;
    /*
        push 14h
        push 0Ah
        call sum
    */
    return 0;

}
