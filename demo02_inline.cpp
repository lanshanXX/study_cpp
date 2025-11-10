#include <iostream>


using namespace std;

//内联函数：提高效率
//在编译过程中直接将函数的代码进行展开，不在生成新的函数符号
//适用于函数体积小，调用频率高的函数
//内联函数一般定义在头文件中，方便被多个源文件调用
//内联函数定义时不能有复杂的控制结构（如循环，switch，递归等）
inline int sum(int a, int b)
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
        此处有标准的函数调用流程 参数压栈，函数栈帧开辟和回退过程
        有函数调用开销
        a+b mov add mov
    */

    /*
        
    */
    return 0;
}